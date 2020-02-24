#include "box.hpp"

#include <iostream>
using namespace std;

class Truck

{
    public:

        string driver;
        float petrol;
        float money;
        float fullMileage;
        float emptyMileage;
        Box *box;
        int box_count;

        void load();
        void unload();
    // float cost();

};

