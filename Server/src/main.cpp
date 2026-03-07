#include "network/server.h"
#include "game/world.h"
#include "utils/logger.h"

#include <chrono>
#include <thread>

int main()
{
    Logger::info("Starting server...");

    Server server(7777);
    World world;

    server.start();

    const int TICK_RATE = 30;
    const int TICK_TIME = 1000 / TICK_RATE;

    while (true)
    {
        auto tick_start = std::chrono::steady_clock::now();

        // 1. terima network packet
        server.poll();

        // 2. update world
        world.update();

        // 3. kirim state ke client
        server.broadcast_world(world);

        // 4. sleep sampai tick berikutnya
        auto tick_end = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(tick_end - tick_start).count();

        if (elapsed < TICK_TIME)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(TICK_TIME - elapsed));
        }
    }

    return 0;
}
