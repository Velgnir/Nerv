#include <memory>
#include <vector>
#include <algorithm>
#include <string>
// File.h
#ifndef FILE_H
#define FILE_H


class File {
public:
    virtual ~File() {}
    virtual void open(std::string path) = 0;
    //virtual void close() = 0;
    virtual std::vector<std::string> read(std::string path) = 0;
   // virtual void write() = 0;
};

#endif // FILE_H
