#include "InputManager.h"

void InputManager::updateOnInput() const
{
    switch (key)
    {
    case 'w':
        if (sm->getRenderState() == SegmentManager::bezier)
        {
            sm->moveCurveWeightPosition(0, -1);
        }else
        {
            sm->moveActiveSegment(0, -1);
        }
        break;
    case 's':
        if (sm->getRenderState() == SegmentManager::bezier)
        {
            sm->moveCurveWeightPosition(0, 1);
        }else
        {
            sm->moveActiveSegment(0, 1);
        }
        break;
    case 'a':
        if (sm->getRenderState() == SegmentManager::bezier)
        {
            sm->moveCurveWeightPosition(-1, 0);
        }else
        {
            sm->moveActiveSegment(-1, 0);
        }
        break;
    case 'd':
        if (sm->getRenderState() == SegmentManager::bezier)
        {
            sm->moveCurveWeightPosition(1, 0);
        }else
        {
            sm->moveActiveSegment(1, 0);
        }
        break;
    case 'q':
        sm->activePrevSegment();
        break;
    case 'e':
        sm->activenextSegment();
        break;
    case 'c':
        sm->addSegment();
        break;
    case 'x':
        sm->removeActiveSegment();
        break;
    case 'f':
        sm->setRenderState(SegmentManager::bezier);
        break;
    case 'r':
        sm->setRenderState(SegmentManager::catmull_rom);
        break;
    default: ;
    }
}

bool InputManager::isExit() const
{
    if (key == 27 || key == 'p') return true;
    
    return false;
}
