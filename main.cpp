#include<bits/stdc++.h>
#include "ParkingLot.h"
using namespace std;

#define ll long long 
const int mod = 1e9 + 7;

int main() {
    //code
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    string command;
    //ParkingLot parkingLot = new ParkingLot
    ParkingLot parkingLot;
    while(cin>>command){ 
        if(command=="Create_parking_lot"){
            int lotcount;
            cin>>lotcount;
            parkingLot.createParkingLot(lotcount);
        }
        else if(command=="Park"){
            string regno;
            string notReq;
            int age;
            cin>>regno>>notReq>>age;
            parkingLot.parkCarUtil(regno,age);
        }
        else if(command=="Slot_numbers_for_driver_of_age"){
            int age;
            cin>>age;
            parkingLot.getSlotsFromAge(age);
        }
        else if(command=="Slot_number_for_car_with_number"){
            string regno;
            cin>>regno;
            parkingLot.getSlotsFromRegistrationNumber(regno);
        }
        else if(command=="Leave"){
            int slotNo;
            cin>>slotNo;
            parkingLot.leaveParking(slotNo);
        }
        else if(command=="Vehicle_registration_number_for_driver_of_age"){
            int age;
            cin>>age;
            parkingLot.getRegistrationNumberFromAge(age);
        }
    }
    return 0;
}