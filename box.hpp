#pragma once
#include<random>
#include<iostream>
using namespace std;

class Box
{   
    public: 
        Box(); //constructor
        int volume(); //function to store the value of the volume of a box;
        void print_dim(); //prints the dimensions of the box
    private:
        int length;
        int width;
        int height;
    
    
};
