class Player
{
public:
    Player();

    void update();
    void setVelocity(float vx, float vy);

private:
    float x;
    float y;

    float vx;
    float vy;
};
