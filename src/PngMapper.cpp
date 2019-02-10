//
// Created by simone on 07.02.19.
//

#include <iostream>
#include "Io.h"

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

    for (uint32_t i = 0; i < input_png->rawdata.size(); i += input_png->stride)
    {
        auto vec = input_png->get_pixel_coords(i);

        if (vec.is_inside_circle(out_png->get_center(), (std::min(out_png->h, out_png->w) / 2) + 1) &&
            vec.is_outside_circle(out_png->get_center(), (std::min(out_png->h, out_png->w) / 2) - 1))
        {
            out_png->rawdata[i] = 0xff;
            out_png->rawdata[i + 1] = 0x00;
            out_png->rawdata[i + 2] = 0xff;
            out_png->rawdata[i + 2] = 0xff;
        }

        vec.translate(-input_png->get_center().x, -input_png->get_center().y)
            .scale(1.f / 500, 1.f / 500)
            .transform()
            .scale(static_cast<float>(out_png->h) / 2, static_cast<float>(out_png->w) / 2)
            .translate(input_png->get_center().x, input_png->get_center().y);

        // std::cout << vec.x << "\t" << vec.y << std::endl;
        uint32_t output_index = input_png->get_buffer_index(vec);

        if (output_index < out_png->rawdata.size())
        {
            out_png->rawdata[output_index] = input_png->rawdata[i];
            out_png->rawdata[output_index + 1] = input_png->rawdata[i + 1];
            out_png->rawdata[output_index + 2] = input_png->rawdata[i + 2];
            out_png->rawdata[output_index + 3] = input_png->rawdata[i + 3];
        }
        else
        {
            throw std::logic_error("transformation produced out of boundary index");
        }
    }
    Io::export_to_path("/tmp/sample.png", std::move(out_png));
    return 0;
}