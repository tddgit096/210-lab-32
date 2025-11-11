#include <iostream>
#include "Car.h"
#include <deque>

using namespace std;
/*
    .
    Any car at the end of any queue can switch lanes to a random lane that's not their original lane.

    The three possible operations and their probabilities are:
    46% probability that the car at the head of the queue pays its toll and leaves the queue
    39% probability that another car joins the queue
    15% probability that the rear car will shift lanes

    All these probability values need to be stored as constants defined in your program, never in hard-coding.
    If a lane is currently empty but there is still more time in the simulation, those probabilities will be just 50/50 if a new car enters the queue or not. Of course another car might shift lanes into it, but that's a different lane's business.

    Run the simulation for 20 time periods.

    In addition to your 10-minute commits, do an additional commit when reaching these milestones:

    [Milestone 2] Your code has created the array of deques, and tests operations on this complex data structure to validate it.

    [Milestone 3] Your code populates the plaza with 2 cars before the simulation runs. Output the current deque status per the sample output.

    [Milestone 4] Your code features the loop. Inside the loop, only code two probabilities: 50/50 of the car paying/leaving and of the car joining the deque. Your code should fully exercise the data structures.

    [Milestone 5] Your code supports lane switching and fully exercises the data structures.

    */
const int INITIALCARS = 2, SIMULATIONTIME = 20, LINES = 4; 
const int PAYPROBABILITY = 46, JOINPROBABILITY = 39;

void print_plaza(deque<Car>[],int);
void print_deque(deque<Car>);

int main(){
    srand(time(NULL));
    deque<Car> Toll;
    deque<Car> Plaza[LINES]; //array of tollbooths.
    int time = 1;

    Plaza[1].push_back(Car());
    Plaza[3].push_back(Car());
    Plaza[0].push_back(Car());
    Plaza[1].push_back(Car());
    Plaza[2].push_back(Car());

    print_plaza(Plaza,LINES);

/*
    //initial line
    for(deque<Car> C : Plaza){              //When the simulation starts, pre-populate the lanes with 2 cars like before. Each time period will now have operations happening on all lines
        for(int i=0;i< INITIALCARS;i++){
            C.push_back(Car());          //calling default car constructor returns randomized car.
        }
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
    }    */
    return 0;
}


void print_plaza(deque<Car> D[],int size){
    for(int i=0;i<size;i++){
        cout<<"Lane: "<<i+1<<endl;
        print_deque(D[i]);
    }
}

void print_deque(deque<Car> D){
    if(D.empty()){
        cout<<"\tEmpty.\n";
        return;
    }
    for(Car c: D){
        cout<<"\t";
        c.print();
    }
}