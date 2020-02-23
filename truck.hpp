#include "box.hpp"

#include <iostream>
using namespace std;

class Truck

{
    public:

        string driver;
        int petrol;
        int money;
        int fullMileage;
        int emptyMileage;
        Box *box;

        void load();
        void unload();
    // float cost();

};

