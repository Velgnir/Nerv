#include "fileinlist.h"
#include "Blockfile.h"
#include "CharacterFile.h"
#include "DirectoryFile.h"
#include "RegularFile.h"
#include "OtherFiles.h"
#include "Symlink.h"
#include "FifoFile.h"
#include "SocketFile.h"
std::string getFileExtension(const std::string& filename) {
    size_t dotPos = filename.find_last_of(".");
    if (dotPos != std::string::npos) {
        return filename.substr(dotPos + 1);
    }
    return "dir";
}

FileInList::FileInList(std::string set_path, std::string set_name, int set_level)
    : path(std::move(set_path)), name(std::move(set_name)),  level(set_level),status(false)
{
    std::string file_type = getFileExtension(name);
        // Add other cases as needed for other file types
    if (std::filesystem::is_directory(path) ) {
        FileTo = std::make_unique<DirectoryFile>();
        //std::cout << "File is a directory file." << std::endl;
    } else if (std::filesystem::is_regular_file(path)) {
        FileTo = std::make_unique<RegularFile>();
       // std::cout << "File is a regular file." << std::endl;
    } else if (std::filesystem::is_block_file(path)) {
        FileTo = std::make_unique<BlockFile>();
        //std::cout << "File is a block device." << std::endl;
    } else if (std::filesystem::is_character_file(path)) {
        FileTo = std::make_unique<CharacterFile>();
       // std::cout << "File is a character device." << std::endl;
    } else if (std::filesystem::is_fifo(path)) {
        FileTo = std::make_unique<FifoFile>();
       // std::cout << "File is a FIFO (Named Pipe)." << std::endl;
    } else if (std::filesystem::is_socket(path)) {
        FileTo = std::make_unique<SocketFile>();
       // std::cout << "File is a socket." << std::endl;
    } else if (std::filesystem::is_symlink(path)) {
        FileTo = std::make_unique<SymlinkFile>();
       // std::cout << "File is a symbolic link." << std::endl;
    } else {
        FileTo = std::make_unique<OtherFile>();
       // std::cout << "Unknown file type." << std::endl;
    }
}

FileInList::FileInList(const FileInList& other)
    : path(other.path), name(other.name), level(other.level), status(other.status)
{
    if (other.FileTo)
    {
        // Determine the actual dynamic type of the object and create the corresponding subclass
        if (dynamic_cast<BlockFile*>(other.FileTo.get()))
        {
            FileTo = std::make_unique<BlockFile>(*dynamic_cast<BlockFile*>(other.FileTo.get()));
        }
        else if (dynamic_cast<CharacterFile*>(other.FileTo.get()))
        {
            FileTo = std::make_unique<CharacterFile>(*dynamic_cast<CharacterFile*>(other.FileTo.get()));
        }
        else if (dynamic_cast<DirectoryFile*>(other.FileTo.get()))
        {
            FileTo = std::make_unique<DirectoryFile>(*dynamic_cast<DirectoryFile*>(other.FileTo.get()));
        }else if (dynamic_cast<RegularFile*>(other.FileTo.get()))
        {
            FileTo = std::make_unique<RegularFile>(*dynamic_cast<RegularFile*>(other.FileTo.get()));
        }else if (dynamic_cast<FifoFile*>(other.FileTo.get()))
        {
            FileTo = std::make_unique<FifoFile>(*dynamic_cast<FifoFile*>(other.FileTo.get()));
        }else if (dynamic_cast<SocketFile*>(other.FileTo.get()))
        {
            FileTo = std::make_unique<SocketFile>(*dynamic_cast<SocketFile*>(other.FileTo.get()));
        }else if (dynamic_cast<SymlinkFile*>(other.FileTo.get()))
        {
            FileTo = std::make_unique<SymlinkFile>(*dynamic_cast<SymlinkFile*>(other.FileTo.get()));
        }else{
            FileTo = std::make_unique<OtherFile>(*dynamic_cast<OtherFile*>(other.FileTo.get()));
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
        if (dynamic_cast<BlockFile*>(other.FileTo.get()))
        {
            FileTo = std::make_unique<BlockFile>(*dynamic_cast<BlockFile*>(other.FileTo.get()));
        }
        else if (dynamic_cast<CharacterFile*>(other.FileTo.get()))
        {
            FileTo = std::make_unique<CharacterFile>(*dynamic_cast<CharacterFile*>(other.FileTo.get()));
        }
        else if (dynamic_cast<DirectoryFile*>(other.FileTo.get()))
        {
            FileTo = std::make_unique<DirectoryFile>(*dynamic_cast<DirectoryFile*>(other.FileTo.get()));
        }else if (dynamic_cast<RegularFile*>(other.FileTo.get()))
        {
            FileTo = std::make_unique<RegularFile>(*dynamic_cast<RegularFile*>(other.FileTo.get()));
        }else if (dynamic_cast<FifoFile*>(other.FileTo.get()))
        {
            FileTo = std::make_unique<FifoFile>(*dynamic_cast<FifoFile*>(other.FileTo.get()));
        }else if (dynamic_cast<SocketFile*>(other.FileTo.get()))
        {
            FileTo = std::make_unique<SocketFile>(*dynamic_cast<SocketFile*>(other.FileTo.get()));
        }else if (dynamic_cast<SymlinkFile*>(other.FileTo.get()))
        {
            FileTo = std::make_unique<SymlinkFile>(*dynamic_cast<SymlinkFile*>(other.FileTo.get()));
        }else{
            FileTo = std::make_unique<OtherFile>(*dynamic_cast<OtherFile*>(other.FileTo.get()));
        }
        // Add other subclasses as needed
    }
    else
    {
        FileTo.reset(); // If the other object has a null unique_ptr, reset this object's unique_ptr too.
    }

    return *this;
}

