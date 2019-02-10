//
// Created by simone on 10.02.19.
//

#ifndef PNG_MAPPER_VECTOR2_H
#define PNG_MAPPER_VECTOR2_H

struct Vector2
{
    double x, y;
    Vector2(double x, double y) : x(x), y(y) {}
    Vector2& transform();
    Vector2& scale(const double scale);
    Vector2& scale(const double scale_x, const double scale_y);
    Vector2& translate(const double trans_x, const double trans_y);
    bool is_inside_circle(const Vector2& center, const double radius) const;
    bool is_outside_circle(const Vector2& center, const double radius) const;
};

#endif  // PNG_MAPPER_VECTOR2_H
