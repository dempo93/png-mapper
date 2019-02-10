//
// Created by simone on 10.02.19.
//

#ifndef PNG_MAPPER_VECTOR2_H
#define PNG_MAPPER_VECTOR2_H

struct Vector2
{
    float x, y;
    Vector2(float x, float y) : x(x), y(y) {}
    Vector2& transform();
    Vector2& scale(const float scale);
    Vector2& scale(const float scale_x, const float scale_y);
    Vector2& translate(const float trans_x, const float trans_y);
    bool is_inside_circle(const Vector2& center, const float radius) const;
    bool is_outside_circle(const Vector2& center, const float radius) const;
};

#endif  // PNG_MAPPER_VECTOR2_H
