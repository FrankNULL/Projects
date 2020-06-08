/**
 * @file main.cpp
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cerrno>
#include "../src/config_manager.h"
#include "../web_code/web/visualization_simulator.h"
#include "../web_code/web/my_web_server_session_state.h"
#include "../web_code/web/my_web_server_command.h"
#include "../web_code/web/my_web_server_session.h"
#include "../web_code/web/my_web_server.h"
using std::fstream;
using std::strerror;


// #define _USE_MATH_DEFINES
// #include <cmath>
// #include <libwebsockets.h>

// #define _USE_MATH_DEFINES
// #include <cmath>
// #include <libwebsockets.h>

int main(int argc, char**argv) {
    std::cout << "Usage: ./build/bin/ExampleServer 8081 <fname>" << std::endl;
    if (argc > 1) {
        int port = std::atoi(argv[1]);
        std::streambuf* buffer;
        std::ofstream of;
        if (argc > 2) {
            std::string filename = argv[2];
            of.open(filename.c_str(), fstream::out);
            buffer = of.rdbuf();
            std::cout << "got here" << std::endl;
        } else {
            std::cout << "got here instead" << std::endl;
            buffer = std::cout.rdbuf();
        }
        std::ostream out(buffer);
        out << "Writing" << std::endl;
        MyWebServerSessionState state;
        MyWebServer* myWS = new MyWebServer();
        ConfigManager* cm = new ConfigManager();

        cm->ReadConfig("config.txt");
        std::cout << "Using default config file: config.txt" << std::endl;

        VisualizationSimulator* mySim =
            new VisualizationSimulator(myWS, cm, &out);

        state.commands["getRoutes"] = new GetRoutesCommand(myWS);
        state.commands["getBusses"] = new GetBussesCommand(myWS);
        state.commands["start"] = new StartCommand(mySim);
        state.commands["pause"] = new PauseCommand(mySim);  // add pause
        state.commands["update"] = new UpdateCommand(mySim);
        state.commands["initRoutes"] = new InitRoutesCommand(cm);
        state.commands["listen"] = new AddListenerCommand(mySim);
        // add new command to listen stop observer
        state.commands["listenStop"] = new AddListenerCommandStop(mySim);
        WebServerWithState<MyWebServerSession,
            MyWebServerSessionState> server(state, port);
        while (true) {
            server.service();
        }
    }

    return 0;
}
