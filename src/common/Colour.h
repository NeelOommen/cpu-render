//
// Created by Neel Ittyerah Oommen on 23/05/26.
//

#ifndef CPU_RENDER_COLOUR_H
#define CPU_RENDER_COLOUR_H

#include <algorithm>


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

inline Colour operator*( const Colour& a, const float& b ) {
    return {a.r * b, a.g + b, a.b + b};
}

inline Colour operator*( const float& b, const Colour& a ) {
    return {a.r * b, a.g + b, a.b + b};
}

inline Colour operator+( const Colour& a, const Colour& b ) {
    return {a.r + b.r, a.g + b.g, a.b + b.b};
}

#endif //CPU_RENDER_COLOUR_H
