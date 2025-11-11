#include <iostream>
#include "Car.h"
#include <deque>

using namespace std;

const int INITIALCARS = 2;
/*
[Milestone 2] Your code successfully incorporates a loop that runs until the deque is empty. Inside the loop, you branch based on the probabilities.
*/
void print_deque(deque<Car>);

int main(){
    srand(time(NULL));
    deque<Car> Toll;
    int time = 1;
    for(int i=0;i< INITIALCARS;i++){
        Toll.push_back(Car());    //calling default car constructor returns randomized car.
    }
    cout<<"Initial queue:\n";

    while(!Toll.empty()){
        //printing:
        cout<<"Time: "<< time <<" Operation: ";
        if(rand()%55<100){    //55% probability that the car at the head of the line pays its toll and leaves the toll booth
            cout<<"Car Paid: ";
               
        }    
    
    }





    //45% probability that another car joins the line for the toll booth

    //run until deque is empty
    //after each simulation, display queue via car's print method
    return 0;
}

void print_deque(deque<Car> D){
    cout<<"Queue:\n";
    if(D.empty()){
        cout<<"\tEmpty.\n";
        return;
    }
    for(Car c: D){
        cout<<"\t";
        c.print();
    }
}