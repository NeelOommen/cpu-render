//
// Created by Neel Ittyerah Oommen on 31/05/26.
//

#ifndef CPU_RENDER_RAY_HITTABLE_H
#define CPU_RENDER_RAY_HITTABLE_H

class ray;

class ray_hittable {
public:
    virtual ~ray_hittable() = default;

    virtual float does_hit(const ray& r) = 0;

};


#endif //CPU_RENDER_RAY_HITTABLE_H
