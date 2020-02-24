#include "box.hpp"

#include <iostream>
using namespace std;

class Truck

{
        string driver;
        float petrol;
        float money;
        float fullMileage;
        float emptyMileage;
        Box *box;
        int box_count;
    public:
        void load();
        void unload();
        void set_petrol(float);
        void set_driver(string);
        void set_money(float);
        void set_fullMileage(float);
        void set_emptyMileage(float);

        //get functions:
        float get_petrol();
        string get_driver();
        float get_money();
        float get_fullMileage();
        float get_emptyMileage();
        int get_box_count();


};

