#include<iostream>
using namespace std;

class Player{
     public:
     string id;
     int currPosition;
     Player(string id,int pos){
        this->id = id;
        this->currPosition = pos;
     }
};