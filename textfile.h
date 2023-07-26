// TextFile.h
#ifndef TEXT_FILE_H
#define TEXT_FILE_H

#include "File.h"
#include <iostream>


class TextFile : public File {
public:
    void open(std::string path) override {
        std::string command = "start \"\" \"" + path + "\"";

        // Execute the shell command to open the image file
        int result = std::system(command.c_str());

        // Check if the command execution was successful
        if (result == 0) {
            std::cout << "Text file opened successfully." << std::endl;
        } else {
            std::cout << "Error opening text file." << std::endl;
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

#endif // TEXT_FILE_H
