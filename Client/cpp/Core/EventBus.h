class EventBus {
public:

    template<typename Event>
    static void subscribe(std::function<void(const Event&)> handler) {

        auto& handlers = get_handlers<Event>();
        handlers.push_back(handler);
    }

    template<typename Event>
    static void emit(const Event& event) {

        auto& handlers = get_handlers<Event>();

        for (auto& handler : handlers) {
            handler(event);
        }
    }

private:

    template<typename Event>
    static std::vector<std::function<void(const Event&)>>& get_handlers() {
        static std::vector<std::function<void(const Event&)>> handlers;
        return handlers;
    }
};
