#ifndef OTHERFILES_H
#define OTHERFILES_H
#include "includes/file.h"
#include <iostream>

class OtherFile : public File {
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
        std::cout << "Reading text file." << std::endl;
        return {};
    }

};
#endif // OTHERFILES_H

