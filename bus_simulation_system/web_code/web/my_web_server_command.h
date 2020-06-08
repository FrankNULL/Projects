/**
 * @file my_web_server_command.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef WEB_CODE_WEB_MY_WEB_SERVER_COMMAND_H_
#define WEB_CODE_WEB_MY_WEB_SERVER_COMMAND_H_



#include <vector>
#include "web_code/web/my_web_server_session.h"
#include "web_code/web/my_web_server_session_state.h"
#include "web_code/web/my_web_server.h"
#include "src/data_structs.h"
#include "src/IObservable.h"
#include "src/IObserver.h"
#include "src/config_manager.h"
#include "web_code/web/visualization_simulator.h"

class MyWebServerSession;
class MyWebServerSessionState;

class MyWebServerCommand {
 public:
    virtual ~MyWebServerCommand() {}
    virtual void execute(MyWebServerSession* session,
        picojson::value& command,  // NOLINT
        MyWebServerSessionState* state) = 0;
};

// Commands

class GetRoutesCommand : public MyWebServerCommand {
 public:
    explicit GetRoutesCommand(MyWebServer* ws);
    void execute(MyWebServerSession* session,
        picojson::value& command,
        MyWebServerSessionState* state) override;
 private:
    MyWebServer* myWS;
};

class GetBussesCommand : public MyWebServerCommand {
 public:
    explicit GetBussesCommand(MyWebServer* ws);
    void execute(MyWebServerSession* session,
        picojson::value& command,
        MyWebServerSessionState* state) override;
 private:
    MyWebServer* myWS;
};

class StartCommand : public MyWebServerCommand {
 public:
    explicit StartCommand(VisualizationSimulator* sim);
    void execute(MyWebServerSession* session,
        picojson::value& command,
        MyWebServerSessionState* state) override;
 private:
    VisualizationSimulator* mySim;
    std::vector<int> timeBetweenBusses;
    int numTimeSteps;
};

class UpdateCommand : public MyWebServerCommand {
 public:
    explicit UpdateCommand(VisualizationSimulator* sim);
    void execute(MyWebServerSession* session,
        picojson::value& command,
        MyWebServerSessionState* state) override;
 private:
    VisualizationSimulator* mySim;
};

class PauseCommand : public MyWebServerCommand {
 public:
    explicit PauseCommand(VisualizationSimulator* sim);
    void execute(MyWebServerSession* session,
        picojson::value& command,
        MyWebServerSessionState* state) override;
 private:
    VisualizationSimulator* mySim;
};

/*
*@brief AddListenerCommand to deal with bus observer pattern
*/
class AddListenerCommand: public MyWebServerCommand {
 public:
    explicit AddListenerCommand(VisualizationSimulator* sim);
    void execute(MyWebServerSession* session,
        picojson::value& command,
        MyWebServerSessionState* state) override;
 private:
        VisualizationSimulator* mySim;
};

/*
*@brief AddListenerCommand to deal with stop observer pattern
*/
class AddListenerCommandStop: public MyWebServerCommand {
 public:
    explicit AddListenerCommandStop(VisualizationSimulator* sim);
    void execute(MyWebServerSession* session,
        picojson::value& command,
        MyWebServerSessionState* state) override;
 private:
        VisualizationSimulator* mySim;
};

class InitRoutesCommand : public MyWebServerCommand {
 public:
    explicit InitRoutesCommand(ConfigManager* cm);
    void execute(MyWebServerSession* session,
        picojson::value& command,
        MyWebServerSessionState* state) override;
 private:
    ConfigManager* cm;
};

#endif  // WEB_CODE_WEB_MY_WEB_SERVER_COMMAND_H_
