//
// Created by simone on 09.02.19.
//

#ifndef PNG_MAPPER_PNG_H
#define PNG_MAPPER_PNG_H

#include <string>
#include <vector>
#include <cmath>

struct Vector2
{
    float x, y;
    Vector2(float x, float y) : x(x), y(y) {}
    Vector2& transform()
    {
        const auto x_f = (x / (std::sqrt(x * x + y * y) + 2));
        y = (y / (std::sqrt(x * x + y * y) + 2));
        x = x_f;
        return *this;
    }
    Vector2& scale(const float scale_x, const float scale_y)
    {
        x = x * scale_x;
        y = y * scale_y;
        return *this;
    }
    Vector2& translate(const float trans_x, const float trans_y)
    {
        x = x + trans_x;
        y = y + trans_y;
        return *this;
    }
    bool is_inside_circle(const Vector2& center, const float radius) const
    {
        return (x - center.x) * (x - center.x) + (y - center.y) * (y - center.y) < radius * radius;
    }
    bool is_outside_circle(const Vector2& center, const float radius) const
    {
        return (x - center.x) * (x - center.x) + (y - center.y) * (y - center.y) > radius * radius;
    }
};

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
