#pragma once
#include <complex>

inline float floatLerp(float a, float b, float t) {
    return a + t * (b - a);
}

inline float floatBezierCurve(float start, float end, float controlPoint, float t) {
    const float t2 = t * t;
    return  pow((1.f - t), 2) * start + 2 * (1.f - t) * t * controlPoint + t2 * end;
}

inline float floatCatmullRom(float p0, float p1, float p2, float p3, float t) {
    const float t2 = t * t;
    const float t3 = t2 * t;
    return  0.5f * ( (2 * p1) + (-p0 + p2) * t + (2 * p0 - 5 * p1 + 4 * p2 - p3) * t2 
    + (-p0 + 3 * p1 - 3 * p2 + p3) * t3 );
}