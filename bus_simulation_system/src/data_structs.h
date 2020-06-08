/**
 * @file data_structs.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_DATA_STRUCTS_H_
#define SRC_DATA_STRUCTS_H_

#include <string>
#include <vector>


struct Position {
    Position(int x, int y): x(x), y(y) { }
    Position() : x(0), y(0) {}
    float x;
    float y;
};

struct Color {
    explicit Color(int r = 0, int g = 0, int b = 0, int a = 255):
        red(r), green(g), blue(b), alpha(a) { }
    int red;
    int green;
    int blue;
    int alpha;
};

struct BusData {
    BusData(std::string id, Color color, Position pos, int n_pass, int cap):
        id(id), position(pos),
            num_passengers(n_pass), capacity(cap), color(color) { }
    BusData() : id(""), position(Position()),
        num_passengers(0), capacity(0), color() {}
    std::string id;
    Position position;
    int num_passengers;
    int capacity;
    Color color;
};

struct StopData {
    StopData(std::string id, Position pos , int n_peeps):
        id(id), position(pos), num_people(n_peeps) { }
    StopData() : id(""), position(Position()), num_people(0) {}
    std::string id;
    Position position;
    int num_people;
};

struct RouteData {
    explicit RouteData(std::string id) :
        id(id), stops(std::vector<StopData>(0)) { }
    RouteData() : id(""), stops(std::vector<StopData>(0)) {}
    std::string id;
    std::vector<StopData> stops;
};

#endif  // SRC_DATA_STRUCTS_H_
