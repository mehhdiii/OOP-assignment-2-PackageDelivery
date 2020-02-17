#include<iostream>
#include "node.hpp"
#include<fstream>
#include<string>
using namespace std;

class TruckDelivery{
    Node *head;
public:
    string driver_name; 
    int number_data; //stores the value of the int type data in the file
    void loadTrucks(){
        ifstream file;
        file.open("drivers.txt");
        if (!file){
            cout << "File not opened!";
            exit(1);
        }
        int count_lines = 0 ; //this variable keeps track of which line is being read of drivers
        while (!file.eof()){ //if the file has not reached EOF then keep the loop running, otherwise break
            if(count_lines==0){
                getline(file, driver_name);
                // cout << driver_name << endl;
                
                Node truck_info; //creating a new node
                head = &truck_info; //assigning its adress to the head of the linked list
                (truck_info.truck).driver = driver_name; //assign the driver name to the class objects variable

 
            }
            else if (count_lines <5){

                file >> number_data; //stores the incoming data from the input stream into the variable
                // cout << number_data<< endl;
            }
            count_lines+=1;
            // else{
            //     count_lines = 0;
            // }
            
            
            
            

        }
    }
    void calculateCost();
    void makeJourney();
    void unloadTrucks();
};
	
