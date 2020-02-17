#include "box.hpp"
#include<string>
#include <iostream>
using namespace std;

struct Truck

{
    string driver;
    int petrol;
    int money;
    int fullMileage;
    int emptyMileage;
    Box *box;

    void load(int numBox)
    {

    }
    void unload()
    {

    }

    float cost()
    {
        return 0.00;
    }
};

