#include "truck.hpp"
#include<ctime>
void Truck::load(){
    //creating a list of boxes
    cout << "Loading Boxes...\n..." << endl;
    box = new Box[12];
    cout << "boxes loaded\n" <<endl;
    // for(int x=0; x<18;x++)
    //     cout << "box volume: " << box[x].length <<endl;

}
void Truck::unload(){
    cout << "Unloading Boxes...\n..." << endl;
    delete []box;
    cout << "boxes unloaded\n" << endl;
    
}