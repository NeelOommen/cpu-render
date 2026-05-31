//
// Created by Neel Ittyerah Oommen on 31/05/26.
//

#include "Sphere.h"

bool Sphere::does_hit(const ray& r) {
    Vec3 oc = center - r.origin();
    float a = dot(r.direction(), r.direction());
    float b = -2.0f * dot(r.direction(), oc);
    float c = dot(oc, oc) - radius * radius;

    float discriminant = b*b - 4*a*c;
    return (discriminant >= 0);
}