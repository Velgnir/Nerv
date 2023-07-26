#include "FileInList.h"
#include "textfile.h"
#include "ImageFile.h"
#include "DirectoryFile.h"
#include "ExeFile.h"

std::string getFileExtension(const std::string& filename) {
    size_t dotPos = filename.find_last_of(".");
    if (dotPos != std::string::npos) {
        return filename.substr(dotPos + 1);
    }
    return "dir";
}

FileInList::FileInList(std::string path, std::string name, int set_level){
    this->path = path;
    this->name = name;
    this->level = set_level;
    this->status = false;
    std::string file_type = getFileExtension(name);
    if(std::filesystem::is_directory(path))
    {
        FileTo = std::make_unique<DirectoryFile>();
    }else if(file_type=="txt")
    {
        FileTo = std::make_unique<TextFile>();
    }else if(file_type=="jpg" || file_type=="png")
    {
        FileTo = std::make_unique<ImageFile>();
    }
    else if(file_type=="exe")
    {
        FileTo = std::make_unique<ExeFile>();
    }
        // Add other cases as needed for other file types

}

FileInList::FileInList(const FileInList& other)
    : path(other.path), name(other.name), level(other.level), status(other.status)
{
    if (other.FileTo)
    {
        // Determine the actual dynamic type of the object and create the corresponding subclass
        if (dynamic_cast<TextFile*>(other.FileTo.get()))
        {
            FileTo = std::make_unique<TextFile>(*dynamic_cast<TextFile*>(other.FileTo.get()));
        }
        else if (dynamic_cast<ImageFile*>(other.FileTo.get()))
        {
            FileTo = std::make_unique<ImageFile>(*dynamic_cast<ImageFile*>(other.FileTo.get()));
        }
        else if (dynamic_cast<DirectoryFile*>(other.FileTo.get()))
        {
            FileTo = std::make_unique<DirectoryFile>(*dynamic_cast<DirectoryFile*>(other.FileTo.get()));
        }
        // Add other subclasses as needed
    }
}

FileInList& FileInList::operator=(const FileInList& other)
{
    if (this == &other)
    {
        return *this; // Handle self-assignment
    }

    path = other.path;
    name = other.name;
    level = other.level;
    status = other.status;

    if (other.FileTo)
    {
        // Determine the actual dynamic type of the object and create the corresponding subclass
        if (dynamic_cast<TextFile*>(other.FileTo.get()))
        {
            FileTo = std::make_unique<TextFile>(*dynamic_cast<TextFile*>(other.FileTo.get()));
        }
        else if (dynamic_cast<ImageFile*>(other.FileTo.get()))
        {
            FileTo = std::make_unique<ImageFile>(*dynamic_cast<ImageFile*>(other.FileTo.get()));
        }
        else if (dynamic_cast<DirectoryFile*>(other.FileTo.get()))
        {
            FileTo = std::make_unique<DirectoryFile>(*dynamic_cast<DirectoryFile*>(other.FileTo.get()));
        }
        // Add other subclasses as needed
    }
    else
    {
        FileTo.reset(); // If the other object has a null unique_ptr, reset this object's unique_ptr too.
    }

    return *this;
}

