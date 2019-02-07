//
// Created by simone on 07.02.19.
//

#include "png-lite/pnglite.h"
#include <iostream>
#include <memory>
#include <vector>

class Png{

public:
    void import_from_path(const std::string& path);
    void export_to_path(const std::string& path);
    std::vector<std::vector<char>> png_image;
};

void Png::import_from_path(const std::string &path) {
    png_t png;

    png_open_file(&png,path.c_str());
    png_get_data(png,)
}

void Png::export_to_path(const std::string &path) {

}

int main(int argc, const char *argv[])
{
    std::unique_ptr<png_t> png;




    png_get_data()
    return 0;
}