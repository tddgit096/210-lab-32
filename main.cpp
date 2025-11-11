#include <iostream>
#include "Car.h"
#include <deque>

using namespace std;

const int INITIALCARS = 2;
/*
[Milestone 1] Your code successfully creates a std::deque and populates it with two Car objects. Your code should exercise appropriate deque methods on those objects.
[Milestone 2] Your code successfully incorporates a loop that runs until the deque is empty. Inside the loop, you branch based on the probabilities.
*/


int main(){
    deque<Car> Toll;
    for(int i=0;i< INITIALCARS;i++){
        Toll.push_back(Car());    //calling default car constructor returns randomized car.
    }

    for(Car c : Toll){//DEBUG CODE
        c.print();
    }

    //55% probability that the car at the head of the line pays its toll and leaves the toll booth
    //45% probability that another car joins the line for the toll booth

    //run until deque is empty
    //after each simulation, display queue via car's print method
    return 0;
}