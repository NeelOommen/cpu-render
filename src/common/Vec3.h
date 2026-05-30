//
// Created by Neel Ittyerah Oommen on 24/05/26.
//

#ifndef CPU_RENDER_VEC3_H
#define CPU_RENDER_VEC3_H
#include <cmath>


class Vec3 {
public:
    float components[3];

    Vec3(): components{0.0f, 0.0f, 0.0f} {}
    Vec3(const float x, const float y, const float z): components{x, y, z} {}

    float x() const { return components[0]; }
    float y() const { return components[1]; }
    float z() const { return components[2]; }

    void x(const float val) { components[0] = val; }
    void y(const float val) { components[1] = val; }
    void z(const float val) { components[2] = val; }

    Vec3 operator-() const { return Vec3(-x(), -y(), -z()); }
    float operator[](const int index) const { return components[index]; }
    float& operator[](const int index)  { return components[index]; }

    Vec3& operator+=(const Vec3& addend) {
        components[0] += addend.components[0];
        components[1] += addend.components[1];
        components[2] += addend.components[2];
        return *this;
    }

    Vec3& operator+=(const float& addend) {
        components[0] += addend;
        components[1] += addend;
        components[2] += addend;
        return *this;
    }

    Vec3& operator*=(const float& multiplier) {
        components[0] += multiplier;
        components[1] += multiplier;
        components[2] += multiplier;
        return *this;
    }

    Vec3& operator/=(const float& divisor) {
        return *this *= 1/divisor;
    }

    float lengthSquared() const {
        return components[0] * components[0] + components[1] * components[1] + components[2] * components[2];
    }

    float length() const {
        return std::sqrt(lengthSquared());
    }

};

using point3 = Vec3;

inline Vec3 operator+( const Vec3& a, const Vec3& b ) {
    return Vec3(a[0] + b[0], a[1] + b[1], a[2] + b[2]);
}

inline Vec3 operator-( const Vec3& a, const Vec3& b ) {
    return Vec3(a[0] - b[0], a[1] - b[1], a[2] - b[2]);
}

inline Vec3 operator*( const Vec3& a, const Vec3& b ) {
    return Vec3(a[0] * b[0], a[1] * b[1], a[2] * b[2]);
}

inline Vec3 operator*( const Vec3& a, const float& b ) {
    return Vec3(a[0] * b, a[1] * b, a[2] * b);
}

inline Vec3 operator*( const float& b, const Vec3& a ) {
    return a * b;
}

inline Vec3 operator/( const Vec3& a, const float& b ) {
    return (1/b) * a;
}

inline float dot( const Vec3& a, const Vec3& b ) {
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

inline Vec3 cross( const Vec3& a, const Vec3& b ) {
    return Vec3(
        a[1] * b[2] - a[2] * b[1],
        a[2] * b[0] - a[0] * b[2],
        a[0] * b[1] - a[1] * b[0]
    );
}

inline Vec3 unitVector(const Vec3& v) {
    return v / v.length();
}

#endif //CPU_RENDER_VEC3_H
