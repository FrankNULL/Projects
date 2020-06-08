/**
 * @file ConfigManager.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_CONFIG_MANAGER_H_
#define SRC_CONFIG_MANAGER_H_

#include <vector>
#include <string>


class Route;

class ConfigManager {
 public:
        ConfigManager();
        ~ConfigManager();

        void ReadConfig(const std::string filename);

        std::vector<Route *> GetRoutes() const { return routes; }

 private:
        std::vector<Route *> routes;
};
#endif  // SRC_CONFIG_MANAGER_H_
