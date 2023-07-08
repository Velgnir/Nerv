#include "fileinlist.h"

FileInList::FileInList(std::string set_path, std::string set_name,int set_level)
{
    path = set_path;
    name = set_name;
    status = false;
    level = set_level;
}
std::vector<std::string> FileInList::FilesAt() {
    std::vector<std::string> result;
    if (std::filesystem::exists(path) && std::filesystem::is_directory(path)) {

        for(const auto& entry : std::filesystem::directory_iterator(path)){

            result.push_back(entry.path().filename().string());

        }
    }
    return result;
}
