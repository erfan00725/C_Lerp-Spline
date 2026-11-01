#include <vector>
#include <conio.h>
#include <string>

#include "InputManager.h"
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
    
    InputManager im(&sm);
    
    while (true)
    {
        if (_kbhit())
        {
            if (im.updateKey()) break;
            
            im.updateOnInput();
            
            screen.clearScreen();
            screen.resetPoints();

            sm.updateSegmentsOnScreen();
            
            string bottomDescription = "active segment: " + to_string(sm.getActiveSegment().xPos) + ", " + to_string(sm.getActiveSegment().yPos) + "\nscreen size: " + to_string(screen.getScreenSizeX()) + " , " + to_string(screen.getScreenSizeY());
            screen.setBottomDescription(bottomDescription);
            
            screen.printScreen();
        }
    }


    return 0;
}