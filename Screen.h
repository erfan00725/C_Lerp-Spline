#pragma once

#include <vector>
#include <string>
#include "structs.h"

using namespace std;

class Screen
{
    int playgroundSizeX = 20;
    int playgroundSizeY = 10;
        
    vector<vector<char>> screen;
        
    string bottomDescription;
    string topDescription;
    
public:
    Screen(int x, int y);
    Screen();
    
    vector<vector<char>> getScreen();
    void setPoint(int x, int y, char c);
    void setPoint(Point2D p, char c);
    void resetPoints();
    void clearScreen();
    int getScreenSizeX() const;
    int getScreenSizeY() const;
    bool isInScreen(int x, int y) const;
    void setBottomDescription(const string& description);
    void setTopDescription(const string& description);
    void printScreen() const;
    
};
