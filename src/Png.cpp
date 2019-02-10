//
// Created by simone on 09.02.19.
//

#include "Png.h"

Vector2 Png::get_center() const { return Vector2(static_cast<float>(h) / 2, static_cast<float>(w) / 2); }

Vector2 Png::get_pixel_coords(const uint32_t pixel_index) const
{
    const auto x = pixel_index / w;
    const auto y = pixel_index % w;
    return Vector2(x, y);
}

uint32_t Png::get_pixel_index(const Vector2 &pixel_coords) const
{
    return (lrint(pixel_coords.x) * w + lrint(pixel_coords.y));
}

void Png::generate_boundary_circle()
{
    for (uint32_t i = 0; i < pixel_count(); ++i)
    {
        auto vec = get_pixel_coords(i);

        if (vec.is_inside_circle(get_center(), (std::min(h, w) / 2) + 1) &&
            vec.is_outside_circle(get_center(), (std::min(h, w) / 2) - 1))
        {
            rawdata[i*stride] = 0xff;
            rawdata[i*stride + 1] = 0x00;
            rawdata[i*stride + 2] = 0xff;
            if (stride == 4) rawdata[i*stride + 3] = 0xff;
        }
    }
}
