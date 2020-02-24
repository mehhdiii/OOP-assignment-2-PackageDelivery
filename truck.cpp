#include "truck.hpp"
#include<ctime>
void Truck::load(){
    //creating a list of boxes
    cout << "Loading Boxes...\n..." << endl;
    box_count = rand()%10+11;
    box = new Box[box_count];
    cout << "boxes loaded\n" <<endl;


}
void Truck::unload(){
    cout << "Unloading Boxes...\n..." << endl;
    delete []box;
    cout << "boxes unloaded\n" << endl;
    
}