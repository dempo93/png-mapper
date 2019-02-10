//
// Created by simone on 07.02.19.
//

#include "Mapper.h"
#include <filesystem>
#include <regex>
#include <iostream>

/**
 * (x/(sqrt(x^2+y^2)+2),y/(sqrt(x^2+y^2)+2))
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char* argv[])
{
    if (argc == 4)
    {
        const std::filesystem::path input_path(argv[1]);
        const std::filesystem::path output_path(argv[2]);
        const std::string scale_literal(argv[3]);

        const bool is_float = std::regex_match(scale_literal, std::regex("(0)?([.])[0-9]+"));
        const bool input_exists = std::filesystem::exists(input_path);
        const bool output_dir_exists = std::filesystem::exists(output_path.parent_path());

        if (is_float && input_exists && output_dir_exists)
        {
            const double scale = std::stod(scale_literal);
            Mapper::HankaSimoneTransformation(scale, input_path, output_path);
            return EXIT_SUCCESS;
        }
    }
    std::cout << "Wrong arguments\nUsage: png-mapper [INPUT: path to png file] [OUTPUT: path to png file] [SCALE: "
                 "float between 0 and 1]\n";
    return EXIT_SUCCESS;
}