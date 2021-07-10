#include <bits/stdc++.h>
#include "ParkingLot.h"
using namespace std;

void ParkingLot::createParkingLot(int givenSize){
    this->parkingSize = givenSize;
    this->carsParked = 0;
    availableSlots.assign(givenSize+1,0);
    cout<<"Created Parking of "<<givenSize<<" slots"<<endl;
  }


bool ParkingLot:: isFull(){
    return (this->parkingSize == this->carsParked);
  }


bool ParkingLot:: isEmpty(){
    if (this->carsParked == 0 and this->parkingSize != 0)
      return true;
    return false;
  }


void ParkingLot:: parkCarUtil(string regNo, int driverAge){
    if (this->parkingSize == 0) {
        cout<<"OOPS! parking not created yet"<<endl;
    } else if (this->isFull()) {
        cout<<"Sorry, parking lot is full"<<endl;
    }
    else{
      parkCar(regNo,driverAge);
    }
  }


void ParkingLot:: parkCar(string regNo, int driverAge){
  int allotedSlot = 0;
      for(int i = 1 ; i <= this->parkingSize ;i++){
        if(availableSlots[i] == 0){
          availableSlots[i] = i;
          allotedSlot = i;
          break;
        }
      }
      this->carsParked++;
      slotToRegNo[allotedSlot] = regNo;
      regNoToAge[regNo] = driverAge;
      carToSlot[regNo] = allotedSlot;
      ageToSlot[driverAge].push_back(allotedSlot);
      ageToRegNo[driverAge].push_back(regNo);
      cout<<"Car with vehicle registration number "<<regNo<<" has been parked at slot number "<<allotedSlot<<endl;
}


bool ParkingLot:: isvalidSlotNo(int slotNo){
  return (slotNo > 0 && slotNo <= this->parkingSize);
}

void ParkingLot::leaveParkingUtil(int slotNo){
    if(this->parkingSize == 0){
      cout<<"OOPS! parking not created yet"<<endl;
    }
    else if(isvalidSlotNo(slotNo)){
      cout<<"Slot number doesn't exist"<<endl;
    }
    else if(isEmpty()){
      cout<<"Parking lot is empty"<<endl;
    }else{
      leaveParking(slotNo);
    }
  }


void ParkingLot::leaveParking(int slotNo){
    if(availableSlots[slotNo] != 0){
        availableSlots[slotNo] = 0;
        string regNo = slotToRegNo[slotNo];
        int driverAge = regNoToAge[regNo];
        slotToRegNo.erase(slotNo);
        regNoToAge.erase(regNo);
        carToSlot.erase(regNo);
        vector<int>::iterator it;
        for(it = ageToSlot[driverAge].begin(); it != ageToSlot[driverAge].end(); it++){
          if(*it == slotNo){
            ageToSlot[driverAge].erase(it);
            break;
          }
        }
        vector<string>::iterator it2;
        for(it2 = ageToRegNo[driverAge].begin(); it2 != ageToRegNo[driverAge].end(); it2++){
          if(*it2 == regNo){
            ageToRegNo[driverAge].erase(it2);
            break;
          }
        }
        this->carsParked--;
        cout<<"Slot number "<<slotNo<<" vacated, the car with vehicle registration number \""<<regNo<<"\" left the space, the driver of the car was of age "<<driverAge<<endl;
      }
      else{
          cout<<"Slot number "<<slotNo<<" is already empty"<<endl;
      }

  }

  void ParkingLot::getRegistrationNumberFromAge(int driverAge){
    if (this->parkingSize == 0) {
        cout<<"OOPS! parking not created yet"<<endl;
    } else if(ageToRegNo[driverAge].size()>0){
        cout<<"The following are the registration number of cars with driver of age "<<driverAge<<endl;
        for(string registrationNo: ageToRegNo[driverAge]){
            cout<<registrationNo<<endl;
        }
    }
    else {
        cout<<"Not found"<<endl<<endl;
    } 
  }

  void ParkingLot::getSlotsFromAge(int driverAge){

    if (this->parkingSize == 0) {
        cout<<"OOPS! parking not created yet"<<endl;
    } else if (ageToSlot[driverAge].size()>0){
        cout<<"Following are the slots occupied by the drivers of age "<<driverAge<<endl;
        for(int parkingSlot:ageToSlot[driverAge]){
            cout<<parkingSlot<<" ";
        }
        cout<<endl;
    } else {
        cout<<"Not found"<<endl;
    }

  }


  void ParkingLot::getSlotsFromRegistrationNumber(string regNo){
    if (this->parkingSize == 0) {
        cout<<"OOPS! parking not created yet"<<endl<<endl;
    }else if(carToSlot[regNo]){
        cout<<carToSlot[regNo]<<endl;
    }
    else {
        cout<<"Not found"<<endl;
        cout<<endl;
    }
  }
