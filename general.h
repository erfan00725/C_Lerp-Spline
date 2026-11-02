#pragma once
#include <complex>

inline float floatLerp(float a, float b, float t) {
    return a + t * (b - a);
}

inline float floatBezierCurve(float start, float end, float controlPoint, float t) {
    return  std::pow((1.f - t), 2.f) * start + 2 * (1.f - t) * t * controlPoint + t * t * end;
}