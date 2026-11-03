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
    
    static Point2D bezierCurve(Point2D start, Point2D end, Point2D controlPoint, float t)
    {
        Point2D temp;
        temp.xPos = round(floatBezierCurve(start.xPos, end.xPos, controlPoint.xPos, t));
        temp.yPos = round(floatBezierCurve(start.yPos, end.yPos, controlPoint.yPos, t));
        return temp;
    }
    
    static Point2D catmullRom(Point2D p0, Point2D p1, Point2D p2, Point2D p3, float t)
    {
        Point2D temp;
        temp.xPos = round(floatCatmullRom(p0.xPos, p1.xPos, p2.xPos, p3.xPos, t));
        temp.yPos = round(floatCatmullRom(p0.yPos, p1.yPos, p2.yPos, p3.yPos, t));
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