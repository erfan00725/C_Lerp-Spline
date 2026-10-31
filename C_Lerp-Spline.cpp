#include <algorithm>
#include <vector>
#include <conio.h>
#include <string>

#include "Screen.h"
#include "structs.h"
#include "SegmentManager.h"

using namespace std;

int main()
{
    int playgroundSize = 60;
    
    Point2D startPos(2,3);
    Point2D endPos(5,8);
    
    Screen screen(playgroundSize, playgroundSize / 2);
    
    string topDescription = "Move with WASD | add with C | remove with X | switch with QE | exit with P";
    screen.setTopDescription(topDescription);

    SegmentManager sm(&screen ,{startPos,endPos});
    sm.init();
    
    while (true)
    {
        if (_kbhit())
        {
            int key = _getch();
            
            if (key == 27 || key == 'p') break;
            
            screen.clearScreen();
            screen.resetPoints();

            switch (key)
            {
                case 'w':
                    sm.moveActiveSegment(0, -1);
                break;
                case 's':
                    sm.moveActiveSegment(0, 1);
                break;
                case 'a':
                    sm.moveActiveSegment(-1, 0);
                break;
                case 'd':
                    sm.moveActiveSegment(1, 0);
                break;
                case 'q':
                    sm.activePrevSegment();
                break;
                case 'e':
                    sm.activenextSegment();
                break;
                case 'c':
                    sm.addSegment();
                break;
                case 'x':
                    sm.removeActiveSegment();
                break;
                default: ;
            }

            
            if (sm.getSegments().size() >= 2)
            {
                for (int k = 0; k < sm.getSegments().size() - 1; ++k)
                {
                    Point2D startPos = sm.getSegments()[k];
                    Point2D endPos = sm.getSegments()[k + 1];
                    
                    int dx = abs(endPos.xPos - startPos.xPos);
                    int dy = abs(endPos.yPos - startPos.yPos);
                    int  steps = max(max(dx, dy), 1);
    
                    for (int i = 0; i < steps; ++i)
                    {
                        const float t = static_cast<float>(i) / static_cast<float>(steps);
                        Point2D p = Point2D::lerp(startPos, endPos, t);
                        screen.setPoint(p, '*');
                    }
                }
                
                Point2D p = sm.getActiveSegment();
                screen.setPoint(p, '#');
                
            } else
            {
                if (!sm.getSegments().empty())
                {
                    Point2D p = sm.getSegments()[0];
                    screen.setPoint(p, '#');
                }
                
            }
            
            string bottomDescription = "active segment: " + to_string(sm.getActiveSegment().xPos) + ", " + to_string(sm.getActiveSegment().yPos) + "\nscreen size: " + to_string(screen.getScreenSizeX()) + " , " + to_string(screen.getScreenSizeY());
            screen.setBottomDescription(bottomDescription);
            
            screen.printScreen();
        }
    }


    return 0;
}