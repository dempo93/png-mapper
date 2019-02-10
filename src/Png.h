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
    Png(ulong h, ulong w, ulong stride, ulong color) : h(h), w(w), stride(stride), color(color) {}
    Png(const Png& other) : h(other.h), w(other.w), stride(other.stride), color(other.color) {}

    std::vector<u_char> rawdata{};
    ulong h{0};
    ulong w{0};
    ulong stride{0};
    ulong color{0};

    Vector2 get_pixel_coords(const ulong buffer_index) const;
    ulong get_pixel_index(const Vector2& pixel_coords) const;
    Vector2 get_center() const;
    void generate_boundary_circle();
    ulong pixel_count() const { return rawdata.size() / stride; }
};

#endif  // PNG_MAPPER_PNG_H
