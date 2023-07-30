#ifndef SYMLINK_H
#define SYMLINK_H
class SymlinkFile : public File {
public:
    void open(std::string path) override {
#ifdef _WIN32
        std::string command = "start \"\" \"" + path + "\"";

        // Execute the shell command to open the image file
        int result = std::system(command.c_str());

        // Check if the command execution was successful
        if (result == 0) {
            std::cout << "Exe file opened successfully." << std::endl;
        } else {
            std::cout << "Error opening exe file." << std::endl;
        }
#elif __linux__
        system(path.c_str());
#endif


    }

    std::vector<std::string> read(std::string path) override {
        return {};
    }
};
#endif // SYMLINK_H
