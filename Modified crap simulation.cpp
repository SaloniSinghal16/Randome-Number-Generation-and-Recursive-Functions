//
//  Modified crap simulation.cpp
//  HW_3
//
//  Created by Saloni Singhal on 11/13/21.
//

#include <iostream>
#include<ctime>
#include<iomanip>
#include <random>
using namespace std;

unsigned int rollDice();

int main(){
    enum class Status {CONTINUE, WON, LOST};
    default_random_engine engine{static_cast<unsigned int>(time(0))};
    
    
   
    
    unsigned int myPoint{0};
    Status gameStatus;
    unsigned int sumOfDice{rollDice()};
    
    switch (sumOfDice){
        case 7:
        case 11:
            gameStatus= Status::WON;
            break;
        case 2:
        case 3:
        case 12:
            gameStatus= Status::LOST;
            break;
        default:
            gameStatus=Status::CONTINUE;
            myPoint= sumOfDice;
            cout<< "Point is"<<myPoint<<endl;
            break;
    }
    
    while(Status::CONTINUE==gameStatus){
        sumOfDice=rollDice();
        
        if (sumOfDice==myPoint){
            gameStatus=Status::WON;
        }
        else{
            if(sumOfDice==7){
                gameStatus= Status::LOST;
            }
            }
        
    }
    if (Status::WON==gameStatus){
        cout<<"Player wins"<<endl;
    }
    else{
        cout<<"Player loses"<<endl;
    }
    return 0;
    }
  


unsigned int rollDice(){
    int die1{1+rand()%6};
    int die2{1+ rand()%6};
    int sum{die1 + die2};
    
    cout<<"Player rolled"<<die1<<"+"<<die2<<"="<<sum<<endl;
    return sum;
}
