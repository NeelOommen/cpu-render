//
// Created by Neel Ittyerah Oommen on 23/05/26.
//

#include "ImageWrite.h"
#include "stb_image_write.h"


void ImageWrite::savePng(char const *filename, int width, int height, int numChannels, const void *data) {
    stbi_write_png(filename, width,height, numChannels, data ,width*numChannels);
}

void ImageWrite::savePng(char const *filename, int width, int height, int numChannels, std::vector<Colour> data) {
    auto* converted_data = new unsigned char[width * height * numChannels];
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            const int idx = (y * width + x) * numChannels;
            data[idx].write(converted_data, idx);
        }
    }
    savePng(filename, width, height, numChannels, converted_data);
    delete[] converted_data;
}