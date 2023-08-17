#ifndef FILEINLIST_H
#define FILEINLIST_H

#include <string>
#include <memory>
#include <vector>
#include "file.h"
#include <filesystem>

class FileInList
{
public:
    FileInList(std::string set_path, std::string set_name, int set_level);
    FileInList(const FileInList& other); // Copy constructor
    FileInList& operator=(const FileInList& other); // Assignment operator

    std::string path;
    std::string name;
    std::unique_ptr<File> FileTo;
    int level;
    bool status;
    

};

#endif // FILEINLIST_H
