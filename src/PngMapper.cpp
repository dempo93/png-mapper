//
// Created by simone on 07.02.19.
//

#include "Io.h"

int main(int argc, const char *argv[])
{
    auto png= Io::import_from_path("/home/simone/3yourmind/png-mapper/test-files/png.png");
    png->rawdata.resize(120000);
    for (int i = 0; i < png->w; i++)
    {
        for (int j = 0; j < png->h; j++)
        {
            if ((i - 100) * (i - 100) + (j - 100) * (j - 100) > 9800 && (i - 100) * (i - 100) + (j - 100) * (j - 100) < 10200)
            {
                png->rawdata[3 * (200 * i + j)] = 0;
                png->rawdata[3 * (200 * i + j) + 1] = 0;
                png->rawdata[3 * (200 * i + j) + 2] = 0;
            }
            else
            {
                png->rawdata[3 * (200 * i + j)] = 255;
                png->rawdata[3 * (200 * i + j) + 1] = 255;
                png->rawdata[3 * (200 * i + j) + 2] = 255;
            }
        }
    }
    Io::export_to_path("/tmp/sample.png",std::move(png));
    return 0;
}