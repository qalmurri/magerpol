#pragma once

struct PlayerDiedEvent {
    int player_id;
};

struct PlayerDamagedEvent {
    int player_id;
    int damage;
};
