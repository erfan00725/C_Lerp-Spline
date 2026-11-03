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


void SegmentManager::updateSegmentsOnScreen()
{
    if (getSegments().size() >= 2)
    {
        for (int k = 0; k < getSegments().size() - 1; ++k)
        {
            Point2D p1 = getSegments()[k];
            Point2D p2 = getSegments()[k + 1];
            
            int p0i = max(0, k-1);
            Point2D p0 = getSegments()[p0i];
            int p3i = min(static_cast<int>(getSegments().size() - 1), k+2);
            Point2D p3 = getSegments()[p3i];
                    
            int dx = abs(p2.xPos - p1.xPos);
            int dy = abs(p2.yPos - p1.yPos);
            int  steps = max(max(dx, dy), 1);
    
            for (int i = 0; i < steps; ++i)
            {
                const float t = static_cast<float>(i) / static_cast<float>(steps);
                Point2D p;
                if (state == bezier && k == activeSegment)
                {
                    p = Point2D::bezierCurve(p1, p2, bCurveWeight, t);
                }else if (state == catmull_rom)
                {
                    p = Point2D::catmullRom(p0, p1, p2, p3, t);
                }else
                {
                    p = Point2D::lerp(p1, p2, t);
                }
                screen->setPoint(p, '*');
            }
        }
                
        Point2D p = getActiveSegment();
        screen->setPoint(p, '#');
                
    } else
    {
        if (!getSegments().empty())
        {
            Point2D p = getSegments()[0];
            screen->setPoint(p, '#');
        }
                
    }
}

std::vector<Point2D> SegmentManager::getSegments() { return segments; }

int SegmentManager::getActiveSegmentIndex() { return activeSegment; }

Point2D SegmentManager::getActiveSegment() { return segments[activeSegment]; }

int SegmentManager::getSegmentsCount()
{
    return segments.size();
}

void SegmentManager::setActiveSegment(int x, int y) { segments[activeSegment] = Point2D(x, y); }

void SegmentManager::moveActiveSegment(int x, int y)
{
    segments[activeSegment] = MovePoint(x,y, segments[activeSegment]);
}

void SegmentManager::activenextSegment() { activeSegment = (activeSegment + 1) % segments.size(); }

void SegmentManager::activePrevSegment() { activeSegment = (activeSegment - 1 + segments.size()) % segments.size(); }

void SegmentManager::reset() { segments.clear(); activeSegment = -1; }

Point2D SegmentManager::MovePoint(int x, int y, const Point2D& originalPoint) const
{
    Point2D p = originalPoint;
    
    if (screen->isInScreen(p.xPos + x, p.yPos)) p.xPos += x;
    if (screen->isInScreen(p.xPos, p.yPos + y)) p.yPos += y;
    
    return p;
}

void SegmentManager::setRenderState(RenderState s)
{
    if (state == s)
    {
        state = lerp;
        return;
    }
    
    state = s;

    if (state == bezier)
    {
        bCurveWeight = getActiveSegment();
    }
}

void SegmentManager::moveCurveWeightPosition(int x, int y)
{
    bCurveWeight = MovePoint(x,y, bCurveWeight);
}
