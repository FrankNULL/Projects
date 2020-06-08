/**
 * @file my_web_server.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef WEB_CODE_WEB_MY_WEB_SERVER_H_
#define WEB_CODE_WEB_MY_WEB_SERVER_H_

#include <vector>
#include "web_code/web/web_interface.h"
/*
*@brief server to update bus and route
*/
class MyWebServer : public WebInterface {
 public:
        MyWebServer();
        ~MyWebServer() {}
        /*
        *@brief UpdateRoute() method to update route info
        *@param route : route data
        *@param deleted : bool if it is deleted
        */
        void UpdateRoute(const RouteData& route, bool deleted = false) override;
        /*
        *@brief UpdateBus() method to update bus info
        *@param bus : bus data
        *@param deleted : bool if it is deleted
        */
        void UpdateBus(const BusData& bus, bool deleted = false) override;

        std::vector<RouteData> routes;
        std::vector<BusData> busses;
};
#endif  // WEB_CODE_WEB_MY_WEB_SERVER_H_
