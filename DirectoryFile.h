// TextFile.h
#ifndef DIRECTORY_FILE_H
#define DIRECTORY_FILE_H

#include "File.h"
#include <filesystem>
#include <iostream>
#include <vector>

class DirectoryFile : public File {
public:
    void open(std::string path) override {
        std::cout << "Opening dir file." << std::endl;
    }

    void close() override {
        std::cout << "Closing text file." << std::endl;
    }

    std::vector<std::string> read(std::string path) override {
        std::vector<std::string> result;
        if (std::filesystem::exists(path) && std::filesystem::is_directory(path)) {

            for(const auto& entry : std::filesystem::directory_iterator(path)){

                result.push_back(entry.path().filename().string());

            }
        }
        return result;
    }

    void write() override {
        std::cout << "Writing to text file." << std::endl;
    }
};

#endif // TEXT_FILE_H
