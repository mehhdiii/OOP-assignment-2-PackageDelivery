#include "truckDelivery.hpp"

Node* TruckDelivery::addNode(){ //function which allocates a dynamic memory for a new node
    Node * truck_info_adress = new Node; //creating a new node object
    return truck_info_adress;
}

void TruckDelivery::loadTrucks(){
    cout << "Reading File..." <<endl; 
    ifstream file;
        file.open("drivers.txt");
        if (!file){ //check if file has opened
            cout << "File not opened!";
            exit(1);
        }
        
        
         
        Node *truck_info;
        while (!file.eof()){ //if the file has not reached EOF then keep the loop running, otherwise break
            truck_info = addNode(); //creating a new node object;
            
            
    
            //filling the truck with all credentials according to driver.exe
            for(int count_lines= 0; count_lines<5; count_lines++){
            // cout << "loop count"<<count_lines << endl;
                if(count_lines==0){
                    file >> first_name;
                    file >> last_name;
                    (truck_info->truck).set_driver(first_name+" "+last_name); //assign the driver name to the class objects variable
                    cout << "Driver: " << truck_info->truck.get_driver()<< endl;
                }
                else if (count_lines <5){
                    file >> number_data; //stores the incoming data from the input stream into the variable
                    //checking where to put the value of the incoming int
                    switch (count_lines)
                    {
                        case 1:
                            truck_info->truck.set_petrol(number_data);
                            cout << "Petrol: "<< truck_info->truck.get_petrol() << endl;
                            break;
                        
                        case 2:
                            truck_info->truck.set_money(number_data);
                            cout << "Money: "<<truck_info->truck.get_money() << endl;
                            break;
                        case 3:
                            truck_info->truck.set_fullMileage(number_data);
                            cout << "Full Milage: "<< truck_info->truck.get_fullMileage() << endl;
                            break;
                        case 4:
                            truck_info->truck.set_emptyMileage(number_data);
                            cout << "Empty Milage: "<<truck_info->truck.get_emptyMileage() << endl;
                            break;
                    }
                }
            }
            
            truck_info->truck.load(); //loading the truck
            cout << endl;
            //the new node has everything filled if you are here. Now, adding it to the linked list (liked list): not so much tbh!:P
            
            
            //building the linked list
            if (head==NULL){//if null then the node is the first element of the linked list

                head= truck_info;
                truck_info->next = NULL;

                // cout << head->truck.driver << endl;
            }
            else{
                //adding the node to the linked list
                truck_info->next = head;
                // cout << "the last element was: "<<truck_info->next->truck.driver << endl;
                head = truck_info;
            }
        }
        cout << "Loading complete!\n" << endl;
    }
void TruckDelivery::calculateCost(){
    cout << "Now calculating Cost...\n"<< endl;
    Node *prev_node;    
    Node *node = head;
    float empty_fuel;
    float loaded_fuel;
    int distance = 60;
    float total_fuel_with_money;
    float req_petrol_with_money;
    float spent_money;
    while(node!=NULL){ //until the node value is null, you have not reached the end of linked list
        // cout << "driver: " << node->truck.driver << endl; //output the driver name
        
        //Rule followed: if the tank cannot be filled to full extent, the truck cannot make journey!!
        total_fuel_with_money = (node->truck.get_money())/2.73;
        req_petrol_with_money = 50-node->truck.get_petrol();
        spent_money = req_petrol_with_money*2.73;
        //consumtion of petrol during journey
        empty_fuel = 60/(node->truck.get_emptyMileage());
        loaded_fuel = 60/(node->truck.get_fullMileage());


        if(total_fuel_with_money < req_petrol_with_money){//if true then remove from list

            cout << node->truck.get_driver()<< ": failed"<< endl;
            node->truck.unload(); //unloading the truck
            prev_node->next = node->next;
            delete node;
            node = prev_node->next; //go to the next node

        }
        else{
            //pass
            cout << node->truck.get_driver()<< ": Pass"<< endl;
            //update his petrol stats and money:
            node->truck.set_money(node->truck.get_money()-spent_money);
            node->truck.set_petrol(node->truck.get_petrol()+req_petrol_with_money);
            prev_node = node;
            node = node->next; //go to the next node
        }




        
    }
    cout << "\nCost calculation Done!"<<endl;


}



void TruckDelivery::unloadTrucks(){
    ofstream file; //creating a new file
    file.open("Trip.txt"); //opening this file
    Node *node = head; // stores the value of current node
    Node *temp;
    cout << "\nUnloading all trucks..."<< endl;
    int len_of_box; //length of the array of boxes
    while(node!=NULL){
        temp = node->next;
        cout<< "truck driver: "<< node->truck.get_driver()<<endl;

        if (temp!=NULL){//THERE IS A NEXT NODE: THEN
        //storing all data to the output file:
            file << node->truck.get_driver();
            file << '\n'<< node->truck.get_petrol();
            file << '\n'<< node->truck.get_money();
            file << '\n'<< node->truck.get_emptyMileage();
            file << '\n'<< node->truck.get_fullMileage()<<"\n";

        }
        else{
            file << node->truck.get_driver();
            file << '\n'<< node->truck.get_petrol();
            file << '\n'<< node->truck.get_money();
            file << '\n'<< node->truck.get_emptyMileage();
            file << '\n'<< node->truck.get_fullMileage();
        }
        


        //unload the truck before deleting
        
        
        
        
        node->truck.unload();
        delete node;
        node = temp;
        
    }

    cout << "Done unloading!" <<endl;


}

void TruckDelivery::makeJourney(){
    cout << "Making Journey...\n" <<endl;
    Node * n = head; // starting truck;
    int total_feul_available;
    int journey_feul;
    while(n!=NULL){
        cout <<"Truck of " << n->truck.get_driver() << " is on the way." <<endl;
        total_feul_available = n->truck.get_petrol(); //the feul currently in tank 
        journey_feul = 60/(n->truck.get_fullMileage())+ 60/(n->truck.get_emptyMileage()); //feul spent in journey

        //updating the feul:
        n->truck.set_petrol(n->truck.get_petrol()-journey_feul);
        cout <<"Truck of " << n->truck.get_driver() << " has reached its destination\n" <<endl;
        n = n->next;
    }


}