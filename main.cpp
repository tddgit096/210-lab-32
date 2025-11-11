#include <iostream>
#include "Car.h"
#include <deque>

using namespace std;

const int INITIALCARS = 2;

void print_deque(deque<Car>);

int main(){
    srand(time(NULL));
    deque<Car> Toll;
    int time = 1;
    for(int i=0;i< INITIALCARS;i++){
        Toll.push_back(Car());          //calling default car constructor returns randomized car.
    }
    cout<<"Initial queue:\n";
    print_deque(Toll);     
    while(!Toll.empty()){               //run until deque is empty
        cout<<"Time: "<< time <<" Operation: ";
        if(rand()%100<55){              //55% probability that the car at the head of the line pays its toll and leaves the toll booth
            cout<<"Car Paid: ";
            Toll.front().print();
            Toll.pop_front();
        }
        else{
            cout<<"Joined lane: ";      //45% probability that another car joins the line for the toll booth
            Toll.back().print();
            Toll.push_back(Car());
        }
        print_deque(Toll);              //after each simulation, display queue via car's print method
        time++;
    }
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