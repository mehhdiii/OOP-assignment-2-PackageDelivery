#include "truckDelivery.hpp"

Node* addNode(){ //function which allocates a dynamic memory for a new node
    Node * truck_info_adress = new Node; //creating a new node and storing its adress in head
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
        // int count_lines = 0 ; //this variable keeps track of which line is being read of drivers
        // cout << (head == NULL) << endl;
        // int loop_val =0;
        
         
        Node *truck_info;
        while (!file.eof()){ //if the file has not reached EOF then keep the loop running, otherwise break
            truck_info = addNode(); //creating a new truck;
            
            
    
            //filling the truck with all credentials according to driver.exe
            for(int count_lines= 0; count_lines<5; count_lines++){
            // cout << "loop count"<<count_lines << endl;
                if(count_lines==0){
                    file >> first_name;
                    file >> last_name;
                    (truck_info->truck).driver = first_name+" "+last_name; //assign the driver name to the class objects variable
                    // count_lines+=1;
                    // cout << "eof value: "<<file.eof() << endl;
                    cout << "Driver: " << truck_info->truck.driver<< endl;
                }
                else if (count_lines <5){
                    file >> number_data; //stores the incoming data from the input stream into the variable
                    // cout << number_data<< endl;
                    // cout << number_data<< endl;
                    // count_lines+=1;

                    //checking where to put the value of the incoming int
                    switch (count_lines)
                    {
                        case 1:
                            truck_info->truck.petrol = number_data;
                            cout << "Petrol: "<< truck_info->truck.petrol << endl;
                            break;
                        
                        case 2:
                            truck_info->truck.money = number_data;
                            cout << "Money: "<<truck_info->truck.money << endl;
                            break;
                        case 3:
                            truck_info->truck.fullMileage = number_data;
                            cout << "Full Milage: "<< truck_info->truck.fullMileage << endl;
                            break;
                        case 4:
                            truck_info->truck.emptyMileage = number_data;
                            cout << "Empty Milage: "<<truck_info->truck.emptyMileage << endl;
                            break;
                    }
                }
            }
            
            truck_info->truck.load(); //loading the truck
            cout << endl;
            //the new node has everything filled if you are here. Now, adding it to the linked list (liked list): not so much tbh!:P
            
            
            //building the linked list
            if (head==NULL){

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
    float total_fuel;
    while(node!=NULL){ //until the node value is null, you have not reached the end of linked list
        // cout << "driver: " << node->truck.driver << endl; //output the driver name
        total_fuel = node->truck.petrol + (node->truck.money)/2.73;
        node->truck.petrol = total_fuel; //refuling the truck 
        
        empty_fuel = 60/(node->truck.emptyMileage);
        loaded_fuel = 60/(node->truck.fullMileage);
        // cout <<"total fuel: "<< total_fuel << endl;
        // cout << "required fuel: " << empty_fuel+loaded_fuel<< endl;

        if(total_fuel<(empty_fuel+loaded_fuel) || total_fuel<50){//if true then remove from list

            cout << node->truck.driver<< ": failed"<< endl;
            node->truck.unload(); //unloading the truck
            prev_node->next = node->next;
            delete node;
            node = prev_node->next; //go to the next node

        }
        else{
            //pass
            cout << node->truck.driver<< ": Pass"<< endl;
            prev_node= node;
            node = node->next; //go to the next node
        }




        
    }
    cout << "\nCost calculation Done!"<<endl;
    // Node* nod1 = head;
    // cout << "Journey made, Now unloading:" << endl<< endl;
    // while(nod1!=NULL){ 
        
    //     cout << "Unloading the truck of: "<<nod1->truck.driver <<endl;
    //     for(int i=0; i<12; i++){
    //         cout << (nod1->truck).box[i].volume()<<endl;
    //     }
    //     nod1 = nod1->next;
    // }

}



void TruckDelivery::unloadTrucks(){
    ofstream file; //creating a new file
    file.open("Trip.txt"); //opening this file
    Node *node = head; // stores the value of current node
    Node *temp;
    cout << "\nUnloading all trucks..."<< endl;
    while(node!=NULL){
        temp = node->next;
        cout<< "truck driver: "<< node->truck.driver<<endl;
        if (temp!=NULL){//THERE IS A NEXT NODE: THEN
        //storing all data to the output file:
            file << node->truck.driver;
            file << '\n'<< node->truck.petrol;
            file << '\n'<< node->truck.money;
            file << '\n'<< node->truck.emptyMileage;
            file << '\n'<< node->truck.fullMileage<<"\n";

        }
        else{
            file << node->truck.driver;
            file << '\n'<< node->truck.petrol;
            file << '\n'<< node->truck.money;
            file << '\n'<< node->truck.emptyMileage;
            file << '\n'<< node->truck.fullMileage;
        }
        


        //unload the truck before deleting
        cout << "volume of box: "<< node->truck.box[0].volume() << endl; // same volume for all boxes in the array
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
        cout <<"Truck of " << n->truck.driver << "is on the way." <<endl;
        total_feul_available = n->truck.petrol; //the feul currently in truck 
        journey_feul = 60/(n->truck.fullMileage )+ 60/(n->truck.emptyMileage); //feul spent in journey

        //updating the feul:
        n->truck.petrol = total_feul_available - journey_feul;
        cout <<"Truck of " << n->truck.driver << "has reached its destination\n" <<endl;
        n = n->next;
    }


}