//
// Created by Neel Ittyerah Oommen on 31/05/26.
//

#ifndef CPU_RENDER_SPHERE_H
#define CPU_RENDER_SPHERE_H

#include "ray_hittable.h"
#include "common/Vec3.h"
#include "ray/Ray.h"

class Vec3;

class Sphere : public ray_hittable {
public:

    Sphere(const Vec3& c, float r) : center(c), radius(r) {}

    float does_hit(const ray& r) override;

    Vec3 normal_at(const Vec3& point);

private:
    Vec3 center;
    float radius;

};


#endif //CPU_RENDER_SPHERE_H
