//
// Created by simone on 10.02.19.
//

#include <cmath>
#include "Vector2.h"

Vector2& Vector2::transform()
{
    const auto x_f = (x / (std::sqrt(x * x + y * y) + 2));
    y = (y / (std::sqrt(x * x + y * y) + 2));
    x = x_f;
    return *this;
}

Vector2& Vector2::scale(const double scale) { return this->scale(scale, scale); }

Vector2& Vector2::scale(const double scale_x, const double scale_y)
{
    x = x * scale_x;
    y = y * scale_y;
    return *this;
}

Vector2& Vector2::translate(const double trans_x, const double trans_y)
{
    x = x + trans_x;
    y = y + trans_y;
    return *this;
}

bool Vector2::is_inside_circle(const Vector2& center, const double radius) const
{
    return (x - center.x) * (x - center.x) + (y - center.y) * (y - center.y) < radius * radius;
}

bool Vector2::is_outside_circle(const Vector2& center, const double radius) const
{
    return (x - center.x) * (x - center.x) + (y - center.y) * (y - center.y) > radius * radius;
}