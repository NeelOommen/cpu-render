//
// Created by Neel Ittyerah Oommen on 23/05/26.
//

#ifndef CPU_RENDER_IMAGEWRITE_H
#define CPU_RENDER_IMAGEWRITE_H

#include <vector>
#include "common/Colour.h"

class ImageWrite {

    public:
    static void savePng(char const *filename, int width, int height, int numChannels, const void *data);
    static void savePng(char const *filename, int width, int height, int numChannels, std::vector<Colour> data);

};


#endif //CPU_RENDER_IMAGEWRITE_H
