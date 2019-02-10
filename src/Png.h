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
};

class Png
{
  public:
    Png(uint32_t h, uint32_t w, uint32_t stride) : h(h), w(w), stride(stride) {}
    Png(const Png& other) : h(other.h), w(other.w), stride(other.stride) {}

    std::vector<u_char> rawdata{};
    uint32_t h{0};

    uint32_t w{0};

    uint32_t stride{0};

    Vector2 get_pixel_coords(const uint32_t buffer_index) const;
    uint32_t get_buffer_index(const Vector2& pixel_coords) const;

    Vector2 get_center() const;

  private:
};

#endif  // PNG_MAPPER_PNG_H
