//
// Created by simone on 07.02.19.
//

#include <iostream>
#include <algorithm>
#include "Io.h"

class Mapper
{

};

/**
 * (x/(sqrt(x^2+y^2)+2),y/(sqrt(x^2+y^2)+2))
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char *argv[])
{
    auto input_png = std::move(Io::import_from_path("/home/simone/Downloads/sample3.png"));
    if (input_png == nullptr) throw std::runtime_error("could not open file");

    auto out_png = std::make_unique<Png>(*input_png);
    out_png->rawdata.resize(input_png->rawdata.size());
    out_png->generate_boundary_circle();

    for (uint32_t pixel_index = 0; pixel_index < input_png->pixel_count(); ++pixel_index)
    {
        auto vec = input_png->get_pixel_coords(pixel_index)
                       .translate(-input_png->get_center().x, -input_png->get_center().y)
                       .scale(1.f, 1.f)
                       .transform()
                       .scale(static_cast<float>(out_png->h) / 2, static_cast<float>(out_png->w) / 2)
                       .translate(input_png->get_center().x, input_png->get_center().y);

        uint32_t output_pixel_index = input_png->get_pixel_index(vec);

        if (output_pixel_index < out_png->pixel_count())
        {
            const auto output_buffer_index = output_pixel_index * out_png->stride;
            const auto input_buffer_index = pixel_index * input_png->stride;

            std::copy_n(&input_png->rawdata[input_buffer_index], input_png->stride,
                        &out_png->rawdata[output_buffer_index]);
        }
        else
        {
            throw std::logic_error("transformation produced out of boundary index");
        }
    }
    Io::export_to_path("/tmp/sample.png", std::move(out_png));
    return 0;
}