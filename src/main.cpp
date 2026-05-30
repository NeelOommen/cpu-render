#include <cstdio>

// #define STB_IMAGE_IMPLEMENTATION
// #include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include "common/Colour.h"
#include "image/ImageWrite.h"
#include "common/Vec3.h"
#include "ray/Ray.h"

Colour ray_colour(const ray& r) {
    Vec3 unit_dir = unitVector(r.direction());
    float a = 0.5f*(unit_dir.y() + 1.0f);

    return (1.0f-a)*Colour(1.0f, 1.0f, 1.0f) + a*Colour(0.5f, 0.7f, 1.0f);
}

int main() {
    float aspect_ratio = 16.0f / 9.0f;

    int width = 400;
    int height = int(width / aspect_ratio);
    height = (height < 1) ? 1: height; //clamp to min 1

    float focal_length = 1.0f;
    float viewport_height = 2.0f;
    float viewport_width = viewport_height * (float(width) / height);
    Vec3 camera_center = Vec3(0.0f, 0.0f, 0.0f);

    Vec3 v_u = Vec3(viewport_width, 0.0f, 0.0f);
    Vec3 v_v = Vec3(0.0f, -viewport_height, 0.0f);

    Vec3 pixel_d_u = v_u / width;
    Vec3 pixel_d_v = v_v / height;

    Vec3 viewport_upper_left = camera_center - Vec3(0.0f, 0.0f, focal_length) - v_u/2 - v_v/2;

    Vec3 p00_loc = viewport_upper_left + 0.5f * (pixel_d_u + pixel_d_v);


    int channels = 3;
    auto* data = new unsigned char[width * height * channels];

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            int idx = (y * width + x) * channels;

            Vec3 pixel_center = p00_loc + (x * pixel_d_u) + (y * pixel_d_v);
            Vec3 ray_dir = pixel_center - camera_center;
            ray r(camera_center, ray_dir);

            ray_colour(r).write(data, idx);
        }
    }

    ImageWrite::savePng("out.png", width,height, channels, data);
    std::puts("cpu-render");
    return 0;
}
