class Time {
public:
    static double now();
    static double since_start();

private:
    static std::chrono::time_point<std::chrono::steady_clock> start_time;
};
