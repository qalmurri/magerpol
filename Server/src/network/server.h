#pragma once

#include <vector>
#include <memory>

class Session;
class World;
class Server {

public:
    Server(int port);

    void start();
    void update();
    void poll();
    void broadcast_world(World& world);

private:
    int port;
    std::vector<std::shared_ptr<Session>> sessions;

};
