#include "SegmentManager.h"
#include "Screen.h"

SegmentManager::SegmentManager(Screen* screen) : screen(screen) {}

SegmentManager::SegmentManager(Screen* screen, std::vector<Point2D> s): screen(screen), segments(s) {}

void SegmentManager::init()
{
    if (segments.empty())
    {
        segments.push_back(Point2D(0,0));
        segments.push_back(Point2D(0,0));
    }
    
    activeSegment = segments.size() - 1;
}

void SegmentManager::addSegment(const Point2D& s)
{
    segments.push_back(s);
    activeSegment = segments.size() - 1;
}
void SegmentManager::addSegment()
{
    Point2D last = segments[segments.size() - 1];
    segments.push_back(last);
    activeSegment = segments.size() - 1;
}

void SegmentManager::removeActiveSegment()
{
    segments.erase(segments.begin() + activeSegment);
    if (activeSegment >= segments.size())
    {
        activeSegment = segments.size() - 1;
    }
    else if (activeSegment < 0)
    {
        activeSegment = 0;
    }
}

void SegmentManager::setActiveSegment(int index)
{
    activeSegment = index;
}

std::vector<Point2D> SegmentManager::getSegments() { return segments; }

int SegmentManager::getActiveSegmentIndex() { return activeSegment; }

Point2D SegmentManager::getActiveSegment() { return segments[activeSegment]; }

void SegmentManager::setActiveSegment(int x, int y) { segments[activeSegment] = Point2D(x, y); }

void SegmentManager::moveActiveSegment(int x, int y)
{
    Point2D p = segments[activeSegment];
    
    if (screen->isInScreen(p.xPos + x, p.yPos)) p.xPos += x;
    if (screen->isInScreen(p.xPos, p.yPos + y)) p.yPos += y;
    
    segments[activeSegment] = p;
}

void SegmentManager::activenextSegment() { activeSegment = (activeSegment + 1) % segments.size(); }

void SegmentManager::activePrevSegment() { activeSegment = (activeSegment - 1 + segments.size()) % segments.size(); }

void SegmentManager::reset() { segments.clear(); activeSegment = -1; }
