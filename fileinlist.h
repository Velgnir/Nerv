#include <string>
#include <iostream>
#include <vector>
#include <filesystem>
#include <iostream>
#include <vector>
#ifndef FILEINLIST_H
#define FILEINLIST_H


class FileInList
{
public:
    FileInList(std::string path, std::string name, int set_level);
    std::string path;
    std::string name;
    bool status;
    int level;
    std::vector<std::string>  FilesAt();

};

#endif // FILEINLIST_H
