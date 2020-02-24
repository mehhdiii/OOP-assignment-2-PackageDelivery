#include "box.hpp"


Box::Box(){
    int x = rand()%10 +5;//catering to the lower limit
    int y = rand()%10 +8;//catering to the upper limit
    length =  x+y;
    //updating x and y for the second box
    x = rand()%10 +5;
    y = rand()%10 +8;
    width = x+y;
    //updating again:
    x = rand()%10 +5; 
    y = rand()%10 +8;   
    height = x+y;
    // cout << "box in !!"<< endl;
}
int Box::volume(){
    return length*width*height;
    //returns the volume of the box
}

void Box::print_dim(){
    cout << "Length: "<<length << " Width: "<<width<< " Height: "<< height<<endl;
}