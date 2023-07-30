#include <iostream>
#include <vector>
#include <filesystem>
#ifdef _WIN32
    #include <Windows.h>
#endif
//
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include <filesystem>
#include "fileinlist.h"
#include "qdebug.h"
#ifndef FILECONTROLLER_H
#define FILECONTROLLER_H


class FileController
{
private:
    std::string path;
    std::string Copy_path;

    std::string path_plus_name(const std::string& sourceDir, const std::string& destDir);

public:
    bool isCut;
    //maybe rewrite later
    std::vector<FileInList> Files_browser;
    std::vector<FileInList> FilesList;
   // std::vector<THE_file> buttons;
    FileController();

    void copy(std::string path){
        Copy_path = path;
        isCut = false;
    }
    void cut(std::string path){
        Copy_path = path;
        isCut = true;
    }


    void paste(const std::string& destinationFile) {
        // Perform the cut (rename) operation
        if(isCut){
        if (std::filesystem::exists(Copy_path)) {
            std::filesystem::rename(Copy_path, path_plus_name(Copy_path,destinationFile));
            qDebug("Paste");
            qDebug() << path_plus_name(Copy_path,destinationFile);
        } else {
            std::cout << "Source file does not exist at the specified path." << std::endl;
        }
        }else{
        if (std::filesystem::exists(Copy_path) && std::filesystem::exists(destinationFile)) {
            std::ifstream source(Copy_path, std::ios::binary);
            std::ofstream dest(path_plus_name(Copy_path,destinationFile), std::ios::binary);
            dest << source.rdbuf();

            // Add these lines to close the file streams
            source.close();
            dest.close();
        } else {
            std::cout << "File does not exist at the specified path." << std::endl;
        }
        }
    }
    void remove(const std::string& destinationFile) {
        if (std::filesystem::exists(destinationFile)) {
            std::filesystem::remove(destinationFile);
        } else {
            std::cout << "File does not exist at the specified path." << std::endl;
        }
    }

    bool UpdateFiles(){
        if (std::filesystem::exists(path) && std::filesystem::is_directory(path)) {
            FilesList.clear();
            for(const auto& entry : std::filesystem::directory_iterator(path)){
                FileInList* new_one = new FileInList(path,entry.path().filename().string(),0);
                FilesList.push_back(*new_one);

            }
            return true;
        }
        return false;
    }

    void SetPath(std::string path_new){
        path = path_new;
    }
    std::string ShowPath(){
        return path;
    }
    std::vector<std::string> ShowFilesList(){
        std::vector<std::string> result;
        for(auto el: FilesList){
            result.push_back(el.name);
        }
        return result;
    }

    std::vector<std::string> History;
    int current_history_moment;

};

#endif // FILECONTROLLER_H
