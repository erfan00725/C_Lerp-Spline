#pragma once

#include <vector>
#include "structs.h"

class Screen;

class SegmentManager
{
    std::vector<Point2D> segments;
    int activeSegment = -1; 
    
    Screen* screen;

public:
    SegmentManager(Screen* screen);
    SegmentManager(Screen* screen, std::vector<Point2D> s);
    
    void init();
    void addSegment(const Point2D& s);
    void addSegment();
    void removeActiveSegment();
    void updateSegmentsOnScreen();
    void setActiveSegment(int index);
    std::vector<Point2D> getSegments();
    int getActiveSegmentIndex();
    Point2D getActiveSegment();
    int getSegmentsCount();
    void setActiveSegment(int x, int y);
    void moveActiveSegment(int x, int y);
    void activenextSegment();
    void activePrevSegment();
    void reset();
};
