#include "box.hpp"


Box::Box(){
    int x = rand()%10 +11;
    length = width = height = x;
    
    // cout << "box in !!"<< endl;
}
int Box::volume(){
    return length*width*height;

}

