#pragma once
#include<iostream>
#include "node.hpp"
#include<fstream>
#include<string>
using namespace std;

class TruckDelivery{
    Node *head =NULL;
public:
    string first_name, last_name; 
    float number_data; //stores the value of the number type data in the file
    void loadTrucks();
    void calculateCost();
    void makeJourney();
    void unloadTrucks();
};
	
