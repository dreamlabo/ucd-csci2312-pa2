#include <iostream>
#include "point.h"
using namespace std;
using Clustering::Point;


int main()
{
    //Initialize Constructor #1

    int numDimensions = 3;
    Point p1(numDimensions);

    std::cout << p1;

    return 0;
}


