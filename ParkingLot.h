#ifndef CLION_PARKINGLOT_H
#define CLION_PARKINGLOT_H
#include <bits/stdc++.h>
using namespace std;

class ParkingLot{
  private:
  int parkingSize = 0;
  int carsParked = 0;
  //vector<int>availableSlots;

  public:
    vector<int> availableSlots;
    map<int,string> slotToRegNo;
    map<string,int> regNoToAge;
    map<string,int> carToSlot;
    map<int,vector<int>> ageToSlot;
    map<int,vector<string>> ageToRegNo;

  //constructor function for initialisation
  void createParkingLot(int givenSize);
  bool isFull();
  bool isEmpty();
  void parkCar(string regNo, int driverAge); 
  bool isvalidSlotNo(int slotNo);
  void leaveParking(int slotNo);
  void getRegistrationNumberFromAge(int driverAge);
  void getSlotsFromAge(int driverAge);
  void getSlotsFromRegistrationNumber(string regNo);
  void parkCarUtil(string regNo, int driverAge);
  void leaveParkingUtil(int slotNo);

};
#endif