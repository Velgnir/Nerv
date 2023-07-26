#include <string>
#include <memory>
#include <vector>
#include "file.h"
#include <filesystem>
#ifndef FILEINLIST_H
#define FILEINLIST_H

class FileInList
{
public:
    FileInList(std::string path, std::string name, int set_level);
    FileInList(const FileInList& other); // Copy constructor
    FileInList& operator=(const FileInList& other); // Assignment operator

    std::string path;
    std::string name;
    std::unique_ptr<File> FileTo;
    bool status;
    int level;

};

#endif // FILEINLIST_H
