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

    for(int i= 0; i<box_count; i++){//printing truck volume
            cout << "Box #" <<i<<": "<< endl;
            box->print_dim();
            cout << "volume: "<< box[i].volume() << endl; // 
        }
    delete []box;
    cout << "boxes unloaded\n" << endl;
    
}
void Truck::set_petrol(float p){
    petrol = p;
}
void Truck::set_driver(string d){
    driver =d;

}
void Truck::set_money(float m){
    money = m;
}
void Truck::set_fullMileage(float fm){
    fullMileage = fm;

}
void Truck::set_emptyMileage(float em){
    emptyMileage = em;
}



//get functions

float Truck::get_petrol(){
    return petrol;
}
string Truck::get_driver(){
    return driver ;

}
float Truck::get_money(){
    return money;
}
float Truck::get_fullMileage(){
    return fullMileage ;

}
float Truck::get_emptyMileage(){
    return emptyMileage ;
}

int Truck::get_box_count(){
    return box_count;
}
