#include<iostream>
#include <cstdlib>
using namespace std;

class Dice{
    int diceCount;
    int min = 1;
    int max = 6;
    public:
    Dice(int diceCount){
        this->diceCount = diceCount;
    }
    int rollDice(){
        int totalSum = 0;
        int diceUsed = 0;
        while(diceUsed < diceCount){
            totalSum += 1 + (rand()%max);
            diceUsed++;
        }
        return totalSum;
    }
};