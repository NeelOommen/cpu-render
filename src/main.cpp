#include <cstdio>

// #define STB_IMAGE_IMPLEMENTATION
// #include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
  #include "stb_image_write.h"

int main() {
    int width = 256;
    int height = 256;
    int channels = 3;
    auto* data = new unsigned char[width * height * channels];

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            auto r = double(x) / (width-1);
            auto g = double(y) / (height-1);
            auto b = 0.0;

            int idx = (y * width + x) * channels;
            data[idx + 0] = static_cast<unsigned char>(r * 255.999f);
            data[idx + 1] = static_cast<unsigned char>(g * 255.999f);
            data[idx + 2] = static_cast<unsigned char>(b * 255.999f);
        }
    }

    stbi_write_png("out.png", width,height, channels, data ,width*channels);
    std::puts("cpu-render");
    return 0;
}
