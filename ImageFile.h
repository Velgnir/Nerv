// ImageFile.h
#ifndef IMAGE_FILE_H
#define IMAGE_FILE_H

#include "File.h"
#include <iostream>

class ImageFile : public File {
public:
    void open(std::string path) override {
        // Replace "example.jpg" with the path to your image file

// Build the shell command to open the image file with the default program
// On Windows, the "start" command is used to open files with the default program.
// On Linux and macOS, the "xdg-open" command is used for the same purpose.
        std::string command = "start \"\" \"" + path + "\"";

        // Execute the shell command to open the image file
        int result = std::system(command.c_str());

        // Check if the command execution was successful
        if (result == 0) {
            std::cout << "Image file opened successfully." << std::endl;
        } else {
            std::cout << "Error opening image file." << std::endl;
        }
    }

    void close() override {
        std::cout << "Closing text file." << std::endl;
    }

    std::vector<std::string> read(std::string path) override {
        std::cout << "Reading text file." << std::endl;
        return {};
    }

    void write() override {
        std::cout << "Writing to text file." << std::endl;
    }
};

#endif // IMAGE_FILE_H
