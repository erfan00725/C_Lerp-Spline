#pragma once

#include <iostream>
#include <cmath>
#include <string>

#include "general.h"

using namespace std;

struct Point2D {
    int xPos = 0;
    int yPos = 0;
        
    Point2D () = default;
    Point2D (int x, int y): xPos(x), yPos(y) {}

    static Point2D lerp(Point2D a, Point2D b, float t) {
        Point2D temp;

        temp.xPos = round(floatLerp(a.xPos, b.xPos, t));
        temp.yPos = round(floatLerp(a.yPos, b.yPos, t));
            
        return temp;
    }
        
    bool operator==(const Point2D& other) const {
        return xPos == other.xPos && yPos == other.yPos;
    }
        
    friend ostream& operator<<(ostream& os, const Point2D& p) {
        os << p.xPos << ' ' << p.yPos;
        return os;
    }
};