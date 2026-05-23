#include <cstdio>

// #define STB_IMAGE_IMPLEMENTATION
// #include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include "common/Colour.h"
#include "image/ImageWrite.h"

int main() {
    int width = 256;
    int height = 256;
    int channels = 3;
    auto* data = new unsigned char[width * height * channels];

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            int idx = (y * width + x) * channels;
            Colour pixel(static_cast<float>(x) / (width-1), static_cast<float>(y) / (height-1), 0.0);
            pixel.write(data, idx);
        }
    }

    ImageWrite::savePng("out.png", width,height, channels, data);
    std::puts("cpu-render");
    return 0;
}
