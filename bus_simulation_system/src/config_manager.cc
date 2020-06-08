/**
 * @file ConfigManager.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include "src/config_manager.h"

#include <sstream>
#include <fstream>
#include <list>
#include <algorithm>

#include "src/route.h"
#include "src/stop.h"
#include "src/random_passenger_generator.h"

// #include <functional>



ConfigManager::ConfigManager() : routes(std::vector<Route *>()) {
}

ConfigManager::~ConfigManager() {
    for (int i = 0; i < static_cast<int>(routes.size()); i++) {
        routes[i] = nullptr;
    }
    routes.clear();
}

void ConfigManager::ReadConfig(const std::string filename) {
    std::ifstream configFile("config/" + filename);

    // std::hash<std::string> stringHash;

    std::list<Stop *> stops = std::list<Stop *>();
    std::list<double> distances = std::list<double>();
    double oldLat = 0;
    double oldLon = 0;
    std::list<double> currProbabilities = std::list<double>();
    std::string currGeneralName = "";
    std::string currRouteName = "";

    std::vector<std::string> stopNames = std::vector<std::string>();
    int stopId = 10;

    std::string line;
    while (std::getline(configFile, line)) {
        std::istringstream stringStream(line);
        std::string chunk;

        if (!std::getline(stringStream, chunk, ',')) { continue; }

        if (chunk == "ROUTE_GENERAL") {
            currGeneralName = "";
            std::getline(stringStream, currGeneralName);
        } else if (chunk == "ROUTE") {
            // If we are coming to a route besides our first one, save all our
            // data and init variables for next route
            if (stops.size() > 0) {
                // Convert our variables into the necessary raw memory
                int numStops = static_cast<int>(stops.size());
                Stop ** rawStops = new Stop *[numStops];
                int it = 0;
                for (auto* s : stops) {
                    rawStops[it] = s;
                    it++;
                }
                int numDists = static_cast<int>(distances.size());
                double * rawDists = new double[numDists];
                it = 0;
                for (const auto& d : distances) {
                    rawDists[it] = d;
                    it++;
                }
                routes.push_back(
                        new Route(
                            currGeneralName + " " + currRouteName,
                            rawStops,
                            rawDists,
                            static_cast<int>(stops.size()),
                            new RandomPassengerGenerator(currProbabilities,
                               stops)));
                stops.clear();
                distances.clear();
                currProbabilities.clear();
            }
            oldLat = 0;  // Refresh our old values on a new route
            oldLon = 0;

            std::getline(stringStream, currRouteName);
            currRouteName.erase(std::remove(currRouteName.begin(),
                currRouteName.end(), ' '), currRouteName.end());

        } else if (chunk == "STOP") {
            // Grab our comma seperated values
            std::string stopName;
            std::getline(stringStream, stopName, ',');

            stopName.erase(std::remove(stopName.begin(),
                stopName.end(), ' '), stopName.end());
            // Check if the stop already exists
            std::vector<std::string>::iterator it =
                std::find(stopNames.begin(),

                stopNames.end(), stopName);
            if (it != stopNames.end()) {
                // We have already seen this stop
                int index = std::distance(stopNames.begin(), it);
                std::list<Stop *>::iterator iter = stops.begin();
                std::advance(iter, index);
                stops.push_back(*iter);
                continue;
            }

            // If we have not seen this stop, set it up
            int id = stopId;
            stopId++;

            std::string latString;
            std::getline(stringStream, latString, ',');
            double latitude = std::stod(latString);

            std::string lonString;
            std::getline(stringStream, lonString, ',');
            double longitude = std::stod(lonString);

            stops.push_back(new Stop(id, latitude, longitude));

            // Need to turn these lat and long into real-world distances
            // This means moving 1 speed in a time click moves 1 mile.
            // That's a bit far,
            // so I multiply * 2 so that a speed of 1 moves 1/2 mile
            latitude *= 69 * 2;
            longitude *= 55 * 2;
            // Grabbing last element from list is hard, so cache position
            // instead
            if (stops.size() > 1) {
                double dist = sqrt((latitude-oldLat)*(latitude-oldLat)

                + (longitude-oldLon)*(longitude-oldLon));
                distances.push_back(dist);
              }
            oldLat = latitude;
            oldLon = longitude;
            std::string probString;
            std::getline(stringStream, probString);
            double probability = std::stod(probString);

            currProbabilities.push_back(probability);
        }
    }
    // Generatre our last route
    if (stops.size() > 0) {
        // Convert our variables into the necessary raw memory
        int numStops = static_cast<int>(stops.size());
        Stop ** rawStops = new Stop *[numStops];
        int it = 0;
        for (auto* s : stops) {
            rawStops[it] = s;
            it++;
        }
        int numDists = static_cast<int>(distances.size());
        double * rawDists = new double[numDists];
        it = 0;
        for (const auto& d : distances) {
            rawDists[it] = d;
            it++;
        }
        routes.push_back(
                new Route(
                    currGeneralName + " " + currRouteName,
                    rawStops,
                    rawDists,
                    static_cast<int>(stops.size()),

                    new RandomPassengerGenerator(currProbabilities, stops)));
    }
    currProbabilities.clear();
    stops.clear();
    distances.clear();
}
