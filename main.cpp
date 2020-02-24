#include <iostream>
#include "truckDelivery.hpp"

using namespace std;

int main()
{
    TruckDelivery delivery;
    delivery.loadTrucks();
    delivery.calculateCost();
    delivery.makeJourney();
    delivery.unloadTrucks();
    return 0;
}
