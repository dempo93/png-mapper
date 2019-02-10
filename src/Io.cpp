//
// Created by simone on 09.02.19.
//

#include <pnglite.h>
#include "Io.h"


std::unique_ptr<Png> Io::import_from_path(const std::filesystem::path &path)
{
    png_init(nullptr, nullptr);

    auto png_raw = static_cast<png_t *>(malloc(sizeof(png_t)));
    if (png_open_file_read(png_raw, path.c_str()) != 0) return nullptr;

    auto png =std::make_unique<Png>(png_raw->height, png_raw->width, png_raw->bpp, png_raw->color_type);

    png->rawdata.resize(png_raw->height * png_raw->width * png_raw->bpp);
    png_get_data(png_raw, &png->rawdata[0]);
    png_close_file(png_raw);

    return std::move(png);
}

void Io::export_to_path(const std::filesystem::path &path,const std::unique_ptr<Png>& png)
{
    png_t png_raw;
    png_open_file_write(&png_raw, path.c_str());
    png_set_data(&png_raw, png->w, png->h, 8, png->color, &(png->rawdata[0]));
    png_close_file(&png_raw);
}
