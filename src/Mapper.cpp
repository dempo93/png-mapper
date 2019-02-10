//
// Created by simone on 10.02.19.
//

#include <cassert>
#include <algorithm>
#include "Mapper.h"

Mapper::Mapper(std::unique_ptr<Png>& input_png) : input_png(std::move(input_png))
{
    output_png = std::make_unique<Png>(*(this->input_png));
    output_png->rawdata.resize(this->input_png->rawdata.size());
    output_png->generate_boundary_circle();
}

std::unique_ptr<Png> Mapper::map(double scale)
{
    this->scale = scale;

    for (ulong input_pixel_index = 0; input_pixel_index < input_png->pixel_count(); ++input_pixel_index)
    {
        const auto output_pixel_index = get_transformed_pixel_index(input_pixel_index);

        assert(output_pixel_index < output_png->pixel_count());

        copy_pixel_data(input_pixel_index, output_pixel_index);
    }

    return std::move(output_png);
}

void Mapper::copy_pixel_data(ulong pixel_index, ulong output_pixel_index) const
{
    const auto output_buffer_index = output_pixel_index * output_png->stride;
    const auto input_buffer_index = pixel_index * input_png->stride;

    std::copy_n(&input_png->rawdata[input_buffer_index], input_png->stride,
                &output_png->rawdata[output_buffer_index]);
}

ulong Mapper::get_transformed_pixel_index(ulong pixel_index) const
{
    auto vec = input_png->get_pixel_coords(pixel_index);
    transform_pixel_coords(vec);
    ulong output_pixel_index = input_png->get_pixel_index(vec);
    return output_pixel_index;
}

void Mapper::transform_pixel_coords(Vector2& vec) const
{
    vec.translate(-input_png->get_center().x, -input_png->get_center().y)
            .scale(scale)
            .transform()
            .scale(static_cast<double>(output_png->h) / 2, static_cast<double>(output_png->w) / 2)
            .translate(input_png->get_center().x, input_png->get_center().y);
}