//
// Created by Neel Ittyerah Oommen on 31/05/26.
//

#include "Sphere.h"

#include <cmath>

float Sphere::does_hit(const ray& r) {
    /*
     *solving the the quadratic equation for the following:
     * (center - point)(center - point) = radius^2
     * if this equation is true, the ray intersects with the sphere.
     * when solving, if the discriminant is negative, the ray does not hit the sphere.
     * if it is 0, the ray intersects the sphere at 1 point -> it grazes the surface tangentially
     * if it is >0, the ray intersects it at 2 places (an entry and an exit),
     * so it intersects non tangentially
     */

    Vec3 oc = center - r.origin();
    float a = dot(r.direction(), r.direction());
    float b = -2.0f * dot(r.direction(), oc);
    float c = dot(oc, oc) - radius * radius;

    float discriminant = b*b - 4*a*c;

    if (discriminant < 0) {
        return -1.0f;
    }
    else {
        return (-b - std::sqrt(discriminant)) / (2.0f * a);
    }
}

Vec3 Sphere::normal_at(const Vec3& point) {
    return unitVector(point - center);
}
