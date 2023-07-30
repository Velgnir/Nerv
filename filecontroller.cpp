
#include "filecontroller.h"
#include <iostream>
#include <filesystem>
#include <vector>
#include <string>

namespace fs = std::filesystem;

FileController::FileController()
{
#ifdef _WIN32
    path = "C:\\";
#elif __linux__
    path = "/";
#endif

    UpdateFiles();
    current_history_moment=0;
    History.push_back(path);
}

std::string FileController::path_plus_name(const std::string& sourceDir, const std::string& destDir) {

    // Check if sourceDir is a valid directory

    fs::path pathObj(sourceDir);
#ifdef _WIN32
    return destDir+"\\"+pathObj.filename().string();
#elif __linux__
   return destDir+"/"+pathObj.filename().string();
#endif



    //return destDir;
}
