#include <iostream>
#include<cassert>
using namespace std;
#include"airplane.h"
#include"garage.h"

int main()
{
    Airplane** airplanes = new Airplane * [Airplane::MAXCOUNT]{};
    Airplane* a1 = new Airplane("Model", "White", 10.5, 120);
    Airplane* a2 = new Airplane("Model2", "White2", 10.55, 130);
    Airplane* a3 = new Airplane("Model3", "White2", 10.55, 150);
    Airplane* a4 = new Airplane("Model4", "White4", 10.55, 180);
    Airplane* a5 = new Airplane("Model5", "White5", 10.55, 180);
    //Airplane* a6 = new Airplane("Model6", "White6", 10.55, 180);
    airplanes = new Airplane * []{a1,a2,a3,a4,a5,/*a6 ==Error*/};
    Garage* g =new Garage(airplanes,"Garage", "Baku");
    g->print();
    cout << endl;

    cout << "GET AIRPLANE BY ID" << endl;
    g->getAirplaneById(2)->print();
    cout << endl;

    cout << "AIRPLANE CAPACITY GREATER THAN" << endl;
    Airplane** greater = g->getAirplanesCapacityGreaterThan(130);
    for (size_t i = 0; i < 3; i++)
    {
        greater[i]->print();
        cout << endl;
    }
    cout << endl;

    cout << "GET AIRPLANE BY COLOR"<<endl;
    Airplane** samecolor = g->getAirplanesByColor("White2");
    for (size_t i = 0; samecolor[i]!=nullptr; i++)
    {
        samecolor[i]->print();
        cout << endl;
    }
    cout << endl;
    cout << "GET CAPACITY GREATER THAN" << endl;
    Airplane** biggerCapacity = g->getAirplanesCapacityGreaterThan(130);
    for (size_t i = 0; biggerCapacity[i]!=nullptr; i++)
    {
        biggerCapacity[i]->print();
        cout << endl;
    }

}
