#pragma once

#include <vector>
#include "structs.h"

class Screen;

class SegmentManager
{
    vector<Point2D> segments;
    int activeSegment = -1; 
    
    Point2D bCurveWeight = Point2D(0,0);
    bool isCurveActiveSegment = false;
    
    Screen* screen;

public:
    SegmentManager(Screen* screen);
    SegmentManager(Screen* screen, vector<Point2D> s);
    
    void init();
    void addSegment(const Point2D& s);
    void addSegment();
    void removeActiveSegment();
    void updateSegmentsOnScreen();
    void setActiveSegment(int index);
    vector<Point2D> getSegments();
    int getActiveSegmentIndex();
    Point2D getActiveSegment();
    int getSegmentsCount();
    void setActiveSegment(int x, int y);
    void moveActiveSegment(int x, int y);
    void activenextSegment();
    void activePrevSegment();
    void reset();
    
    Point2D MovePoint(int x, int y,const Point2D& originalPoint ) const;
    
    bool getIsCurveActiveSegment() const {return isCurveActiveSegment;}
    
    void curveActiveSegment();
    void moveCurveWeightPosition(int x, int y);
};
