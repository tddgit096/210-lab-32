#include <iostream>
#include "Car.h"
#include <deque>

using namespace std;

const int INITIALCARS = 2, SIMULATIONTIME = 20, LINES = 4; 
const int PAYPROBABILITY = 46, JOINPROBABILITY = 39, JOINPROBEMPTY = 50;

void print_plaza(deque<Car>[],int);
void print_deque(deque<Car>);
int find_best_lane(deque<Car>[],int, int);//returns the lane with the least cars

int main(){
    srand(time(NULL));
    deque<Car> Plaza[LINES]; //array of toll-lines.
    int time = 1;

    //initial line
    for(int i=0;i<LINES;i++){              //When the simulation starts, pre-populate the lanes with 2 cars like before. Each time period will now have operations happening on all lines
        for(int j=0;j< INITIALCARS;j++){
            Plaza[i].push_back(Car());          //calling default car constructor returns randomized car.
        }
    }
    cout<<"Initial queue:\n";
    print_plaza(Plaza,LINES);

    //Begin Simulation
    for(int time=1;time<SIMULATIONTIME+1;time++){
        cout<<"Time: "<< time <<endl;
        for(int i=0;i<LINES;i++){
            cout<<"   Lane: "<<i+1<<"\t";
            if(Plaza[i].empty()){              //If a lane is currently empty but there is still more time in the simulation, those probabilities will be just 50/50 if a new car enters the queue or not.
                if(rand()%100<JOINPROBEMPTY){
                    cout<<"Joined lane: ";   
                    Plaza[i].push_back(Car());
                    Plaza[i].back().print();
                }
                else{
                    cout<<endl;
                }
                continue;
            }
            //store result
            int result = rand()%100;

            if(result<PAYPROBABILITY){
                cout<<"Paid: ";
                Plaza[i].front().print();
                Plaza[i].pop_front();
            }
            else if(result<(JOINPROBABILITY+PAYPROBABILITY)){   
                cout<<"Joined lane: ";   
                Plaza[i].push_back(Car());
                Plaza[i].back().print();
            }
            else{
                if(Plaza[i].size()==1){
                    cout<<endl;
                    continue;    //it's the only car in the spot,so technically it's last but it's also first, so reasonably it will wait to be helped.
                }
                cout<<"Switched lane: "; 
                Plaza[i].back().print();
                Car C = Plaza[i].back();                               //copy the car
                Plaza[i].pop_back();                                    //remove it from the initial list
                Plaza[find_best_lane(Plaza,LINES,i)].push_back(C);    //find the least clogged line, then send it to the back.
            }
        }
        print_plaza(Plaza,LINES);                //after each simulation, display the entire structure.
    }
    return 0;
}


void print_plaza(deque<Car> P[],int size){ //prints array of deque<Car>
    for(int i=0;i<size;i++){
        cout<<"Lane: "<<i+1<<endl;
        print_deque(P[i]);                  //hands it off to print_deque, for each lane
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

int find_best_lane(deque<Car>P[],int size,int initial){//returns the lane index with the least cars
    int minVals[2]; //Find the 2 indices with the 2 lowest values. Why 2? in case the lowest value is actually our own lane. We want to avoid "switching" to our own lane.
    int minIndex
    int minValue = P[initial].size();   //set to initial value to exclude it from our searches (A car shouldn't switch to the same lane it left)
    int minIndex = initial;
    for(int i=0;i<size;i++){
        if(i==initial)                  //exclude our own line.
            continue;
        if(minValue>P[i].size()){       //check for smaller value
            minValue=P[i].size();
            minIndex = i;
        }
    }
    return minIndex;
}