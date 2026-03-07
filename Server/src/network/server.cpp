#include "network/server.h"
#include "game/world.h"
#include "utils/logger.h"

Server::Server(int port) {
    this->port = port;
}

void Server::start() {

    Logger::info("Server started on port " + std::to_string(port));

}

void Server::update() {

    // network polling
}

void Server::poll()
{
    // cek packet masuk
}

void Server::broadcast_world(World& world)
{
    // kirim posisi player
}
