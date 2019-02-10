//
// Created by simone on 07.02.19.
//

#include "Io.h"
#include "Mapper.h"


/**
 * (x/(sqrt(x^2+y^2)+2),y/(sqrt(x^2+y^2)+2))
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char* argv[])
{
    auto input_png = std::move(Io::import_from_path("/home/simone/Downloads/sample3.png"));
    if (input_png == nullptr) throw std::runtime_error("could not open file");

    Mapper mapper(input_png);
    Io::export_to_path("/tmp/sample.png", mapper.map(0.1));
    return 0;
}