//
// Created by simone on 09.02.19.
//

#ifndef PNG_MAPPER_PNG_H
#define PNG_MAPPER_PNG_H

#include <string>
#include <vector>
#include "Vector2.h"

class Png
{
  public:
    Png(uint32_t h, uint32_t w, uint32_t stride, uint32_t color) : h(h), w(w), stride(stride), color(color) {}
    Png(const Png& other) : h(other.h), w(other.w), stride(other.stride), color(other.color) {}

    std::vector<u_char> rawdata{};
    uint32_t h{0};
    uint32_t w{0};
    uint32_t stride{0};
    uint32_t color{0};

    Vector2 get_pixel_coords(const uint32_t buffer_index) const;
    uint32_t get_pixel_index(const Vector2 &pixel_coords) const;
    Vector2 get_center() const;
    void generate_boundary_circle();
    uint32_t pixel_count(){ return rawdata.size()/stride;}
};

#endif  // PNG_MAPPER_PNG_H
