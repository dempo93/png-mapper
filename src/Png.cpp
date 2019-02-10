//
// Created by simone on 09.02.19.
//

#include "Png.h"

Vector2 Png::get_center() const { return Vector2(static_cast<float>(h) / 2, static_cast<float>(w) / 2); }

Vector2 Png::get_pixel_coords(const uint32_t buffer_index) const
{
    const auto pixel_index = (buffer_index / stride);
    const auto x = pixel_index / w;
    const auto y = pixel_index % w;
    return Vector2(x, y);
}

uint32_t Png::get_buffer_index(const Vector2 &pixel_coords) const
{
    return (lrint(pixel_coords.x) * w + lrint(pixel_coords.y)) * stride;
}
