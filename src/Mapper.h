//
// Created by simone on 10.02.19.
//

#ifndef PNG_MAPPER_MAPPER_H
#define PNG_MAPPER_MAPPER_H

#include <algorithm>
#include <memory>
#include <cassert>
#include "Png.h"

class Mapper
{
public:
    Mapper(std::unique_ptr<Png>& input_png) : input_png(std::move(input_png))
    {
        output_png = std::make_unique<Png>(*(this->input_png));
        output_png->rawdata.resize(this->input_png->rawdata.size());
        output_png->generate_boundary_circle();
    }

    std::unique_ptr<Png> map(float scale)
    {
        this->scale = scale;

        for (uint32_t input_pixel_index = 0; input_pixel_index < input_png->pixel_count(); ++input_pixel_index)
        {
            const auto output_pixel_index = get_transformed_pixel_index(input_pixel_index);

            assert(output_pixel_index < output_png->pixel_count());

            copy_pixel_data(input_pixel_index, output_pixel_index);
        }

        return std::move(output_png);
    }

    void copy_pixel_data(uint32_t pixel_index, uint32_t output_pixel_index) const
    {
        const auto output_buffer_index = output_pixel_index * output_png->stride;
        const auto input_buffer_index = pixel_index * input_png->stride;

        std::copy_n(&input_png->rawdata[input_buffer_index], input_png->stride,
                    &output_png->rawdata[output_buffer_index]);
    }

    uint32_t get_transformed_pixel_index(uint32_t pixel_index) const
    {
        auto vec = input_png->get_pixel_coords(pixel_index);
        transform_pixel_coords(vec);
        uint32_t output_pixel_index = input_png->get_pixel_index(vec);
        return output_pixel_index;
    }

    void transform_pixel_coords(Vector2& vec) const
    {
        vec.translate(-input_png->get_center().x, -input_png->get_center().y)
                .scale(scale)
                .transform()
                .scale(static_cast<float>(output_png->h) / 2, static_cast<float>(output_png->w) / 2)
                .translate(input_png->get_center().x, input_png->get_center().y);
    }

private:
    std::unique_ptr<Png> input_png;
    std::unique_ptr<Png> output_png;
    float scale{1.f};
};
#endif //PNG_MAPPER_MAPPER_H