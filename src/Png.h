//
// Created by simone on 09.02.19.
//

#ifndef PNG_MAPPER_PNG_H
#define PNG_MAPPER_PNG_H

#include <string>
#include <vector>

class Png
{
  public:
    Png(uint32_t h, uint32_t w, uint32_t stride) : h(h), w(w), stride(stride) {}

    std::vector<u_char> rawdata{};
    uint32_t h{0};
    uint32_t w{0};
    uint32_t stride{0};
};

#endif  // PNG_MAPPER_PNG_H
