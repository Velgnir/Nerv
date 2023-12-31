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
   FileController();  // Default constructor


    void copy(std::string pathset){
        Copy_path = pathset;
        isCut = false;
    }
    void cut(std::string pathset){
        Copy_path = pathset;
        isCut = true;
    }


    void paste(const std::string& destinationFile);
    void remove(const std::string& destinationFile);

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
