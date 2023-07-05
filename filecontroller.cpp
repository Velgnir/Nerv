#include "filecontroller.h"
#include <iostream>
#include <filesystem>
#include <vector>
#include <string>

FileController::FileController()
{
    path = "C:\\";
    UpdateFiles();
    current_history_moment=0;
    History.push_back(path);
}

