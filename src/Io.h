//
// Created by simone on 09.02.19.
//

#ifndef PNG_MAPPER_IO_H
#define PNG_MAPPER_IO_H

#include <string>
#include <memory>
#include <filesystem>
#include "Png.h"

class Io
{
  public:
    static std::unique_ptr<Png> import_from_path(const std::filesystem::path &path);
    static void export_to_path(const std::filesystem::path &path, const std::unique_ptr<Png>& png);
};

#endif  // PNG_MAPPER_IO_H
