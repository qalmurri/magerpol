class FileSystem {
public:
    static std::string read_text(const std::string& path);
    static bool write_text(const std::string& path, const std::string& content);

    static bool exists(const std::string& path);
};
