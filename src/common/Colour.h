//
// Created by Neel Ittyerah Oommen on 23/05/26.
//

#ifndef CPU_RENDER_COLOUR_H
#define CPU_RENDER_COLOUR_H

#include <algorithm>
#include <cstdint>


struct Colour {
    float r,g,b;

    Colour(float r,float g,float b) : r(r), g(g), b(b) {}

    unsigned char to_byte(float v) const {
        return static_cast<unsigned char>(std::clamp(v, 0.0f, 1.0f) * 255.999f);
    }

    void write(unsigned char* target, int index) const {
        target[index + 0] = to_byte(r);
        target[index + 1] = to_byte(g);
        target[index + 2] = to_byte(b);
    }
};


#endif //CPU_RENDER_COLOUR_H
