#ifndef EXEFILE_H
#define EXEFILE_H

#include "File.h"
#include <filesystem>
#include <iostream>
#include <vector>


class ExeFile : public File {
public:
    void open(std::string path) override {

       std::string command = "start \"\" \"" + path + "\"";

        // Execute the shell command to open the image file
        int result = std::system(command.c_str());

        // Check if the command execution was successful
        if (result == 0) {
            std::cout << "Exe file opened successfully." << std::endl;
        } else {
            std::cout << "Error opening exe file." << std::endl;
        }
    }

    void close() override {
        std::cout << "Closing text file." << std::endl;
    }

    std::vector<std::string> read(std::string path) override {
        return {};
    }

    void write() override {
        std::cout << "Writing to text file." << std::endl;
    }
};

#endif // EXEFILE_H