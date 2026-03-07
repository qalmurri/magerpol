#pragma once

class Session {

public:

    Session(int id);

    void receive();
    void send();

private:

    int id;

};
