
#include "filecontroller.h"
#include <iostream>
#include <filesystem>
#include <vector>
#include <string>
#include "mainwindow.h"
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
void FileController::paste(const std::string& destinationFile) {
    // Perform the cut (rename) operation
    if(isCut){
        if (std::filesystem::exists(Copy_path)) {
            std::filesystem::rename(Copy_path, path_plus_name(Copy_path,destinationFile));
            //qDebug("Paste");
            //qDebug() << path_plus_name(Copy_path,destinationFile);
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
}void FileController::remove(const std::string& destinationFile) {
    if (std::filesystem::exists(destinationFile)) {
        std::filesystem::remove(destinationFile);
    } else {
        std::cout << "File does not exist at the specified path." << std::endl;
    }

}