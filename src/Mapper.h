//
// Created by simone on 10.02.19.
//

#ifndef PNG_MAPPER_MAPPER_H
#define PNG_MAPPER_MAPPER_H

#include <memory>
#include "Png.h"
#include "Io.h"


class Mapper
{
  public:
    static void HankaSimoneTransformation(double scale, const std::filesystem::path& input,
                                          const std::filesystem::path& output);

  private:
    explicit Mapper(std::unique_ptr<Png>& input_png);
    std::unique_ptr<Png> map(double scale);

    std::unique_ptr<Png> input_png;
    std::unique_ptr<Png> output_png;
    double scale{1.f};

    ulong get_transformed_pixel_index(ulong pixel_index) const;
    void transform_pixel_coords(Vector2& vec) const;
    void copy_pixel_data(ulong pixel_index, ulong output_pixel_index) const;
};
#endif  // PNG_MAPPER_MAPPER_H
