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
    auto input_png = std::move(Io::import_from_path("/home/simone/3yourmind/png-mapper/test-files/sample.png"));
    if (input_png == nullptr) throw std::runtime_error("could not open file");

    auto out_png = std::make_unique<Png>(*input_png);
    out_png->rawdata.resize(input_png->rawdata.size());

    for (uint32_t i = 0; i < input_png->rawdata.size(); i += 3)
    {
        auto vec = input_png->get_pixel_coords(i);
        vec.translate(-input_png->get_center().x, -input_png->get_center().y)
            .transform()
            .scale(static_cast<float>(input_png->h) / 2, static_cast<float>(input_png->w) / 2)
            .translate(input_png->get_center().x, input_png->get_center().y);

        //        std::cout << vec.x << "\t" << vec.y << std::endl;
        uint32_t output_index = input_png->get_buffer_index(vec);

        if (output_index < out_png->rawdata.size())
        {
            out_png->rawdata[output_index] = input_png->rawdata[i];
            out_png->rawdata[output_index + 1] = input_png->rawdata[i + 1];
            out_png->rawdata[output_index + 2] = input_png->rawdata[i + 2];
        }
        else
        {
            throw std::logic_error("transformation produced out of boundary index");
        }
    }

    Io::export_to_path("/tmp/sample.png", std::move(out_png));
    return 0;
}