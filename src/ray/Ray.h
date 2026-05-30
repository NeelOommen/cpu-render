//
// Created by Neel Ittyerah Oommen on 24/05/26.
//

#ifndef CPU_RENDER_RAY_H
#define CPU_RENDER_RAY_H

#include "common/Vec3.h"


class ray {
public:
    ray() {}
    ray(const Vec3 &origin, const Vec3 &direction): orig(origin), dir(direction) {}

    const Vec3& origin() const { return orig; }
    const Vec3& direction() const { return dir; }

    Vec3 at(float t) const {
        return orig + t * dir;
    }

private:

    Vec3 orig;
    Vec3 dir;
};


#endif //CPU_RENDER_RAY_H
