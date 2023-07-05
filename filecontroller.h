#include <iostream>
#include <vector>
#include <filesystem>

#ifndef FILECONTROLLER_H
#define FILECONTROLLER_H


class FileController
{
private:
    std::string path;
    std::vector<std::string> FilesList;
public:
    FileController();

    bool UpdateFiles(){
        if (std::filesystem::exists(path) && std::filesystem::is_directory(path)) {
            FilesList.clear();
            for(const auto& entry : std::filesystem::directory_iterator(path)){

                FilesList.push_back(entry.path().filename().string());

            }
            return true;
        }
        return false;
    }

    void SetPath(std::string path_new){
        path = path_new;
    }
    std::vector<std::string> ShowFilesList(){
        return FilesList;
    }
    std::string ShowPath(){
        return path;
    }

    std::vector<std::string> History;
    int current_history_moment;

};

#endif // FILECONTROLLER_H
