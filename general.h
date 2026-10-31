#pragma once

inline float floatLerp(float a, float b, float t) {
    return a + t * (b - a);
}