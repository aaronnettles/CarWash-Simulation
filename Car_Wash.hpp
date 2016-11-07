/**
 *  Matthew Hunt
 *  Aaron Nettles
 *  Justin Smith
 *  Christopher Jones
 *
 *  Data Structures with Dr. Zhao
 *  Project 2: Car Wash Simulation
 *  19MAR2016
 */

#ifndef CAR_WASH_HPP_INCLUDED
#define CAR_WASH_HPP_INCLUDED

#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>

#include "Queue.hpp"

// car wash simulator class
class Car_Wash {

    // number of car wash stations
	int number_of_stations;

    // number of cars each wash station can enqueue
    int cars_per_station;

    // vector of queues holding wash probabilities
	std::vector< Queue<double> > stations;

    // generates a random proportion number between 0 and 1
    double random_proportion();

    // simulation for multiple car wash stations with
    // an int for total time, an int for wash time,
    // and a double for proportion probability
    // of getting a wash for each vehicle
    void simulation(int, int, double);

public:

	// constructors
    // default number of stations is 2
    // and default size of car queues is 30 each
    Car_Wash();

    // takes in int for number of stations
    // and uses default size of car queues
    Car_Wash(int);

    // takes in int for number of stations
    // and int for size of car queues
    Car_Wash(int, int);

    // copy constructor
    Car_Wash(const Car_Wash&);

    // copy assigner
    Car_Wash& operator = (const Car_Wash&);

    // destructor
    ~Car_Wash();

    // user interface
    void interface();
    
};

// generates a random proportion number between 0 and 1
double Car_Wash::random_proportion() {
    return double(rand() % 100) / 100.0;
}

// simulation for multiple car wash stations with
// an int for total time, an int for wash time,
// and a double for proportion probability
// of getting a wash for each vehicle
void Car_Wash::simulation(int total_time, int wash_time, double proportion) {
    int cars_washed = 0;
    int cars_turned_away = 0;
    int cars_away_at_closing = 0;
    int total_wait_time = 0;
    int cars_in_queues = 0;

    double comparison_proportion = 0;
    bool turned_away = false;

    for(int i = 0; i <= total_time; ++i) {
        total_wait_time += cars_in_queues;

        if(i % wash_time == 0) { // if time is 0 or a multiple of the wash time, proceed
            for(int j = 0; j < stations.size(); ++j) { // check each queue for a car
                if(!stations[j].empty()) {
                    stations[j].pop(); // get vehicle from line
                    ++cars_washed; // wash vehicle
                    --cars_in_queues;
                }
            }
        }

        comparison_proportion = Car_Wash::random_proportion();
        if(comparison_proportion < proportion) { // if comparison proportion is less than proportion, proceed
            turned_away = true;

            for(int j = 0; j < stations.size(); ++j) {
                if(!stations[j].full()) {
                    stations[j].push(comparison_proportion);
                    turned_away = false;
                    ++cars_in_queues;
                }
            }

            if(turned_away == true) {
                ++cars_turned_away;
            }
        }

        if(i == total_time) {
            for(int j = 0; j < stations.size(); ++j) {
                while(stations[j].pop()) { // empty the queues of remaining vehicles
                    ++cars_turned_away;
                    ++cars_away_at_closing;
                }
            }
        }
    }

    std::cout << "\nnumber of vehicles washed: " << cars_washed;
    std::cout << "\nnumber of vehicles turned away: " << cars_turned_away;
    if(cars_washed > 0) {
        std::cout << "\naverage waiting time: ";
        std::cout << total_wait_time / (cars_washed + cars_away_at_closing);
    }
    std::cout << std::endl;
}

// constructors
// default number of stations is 2
// and default size of car queues is 30 each
Car_Wash::Car_Wash()
    : number_of_stations(2)
    , cars_per_station(30)
    , stations(2, Queue<double>(30))
{}

// takes in int for number of stations
// and uses default size of car queues
Car_Wash::Car_Wash(int s)
    : number_of_stations(s)
    , cars_per_station(30)
    , stations(s, Queue<double>(30))
{}

// takes in int for number of stations
// and int for size of car queues
Car_Wash::Car_Wash(int s, int q)
    : number_of_stations(s)
    , cars_per_station(q)
    , stations(number_of_stations, Queue<double>(cars_per_station))
{}

// copy constructor
Car_Wash::Car_Wash(const Car_Wash& CW)
    : number_of_stations(CW.number_of_stations)
    , cars_per_station(CW.cars_per_station)
    , stations(number_of_stations, Queue<double>(cars_per_station))
{}

// copy assigner
Car_Wash& Car_Wash::operator = (const Car_Wash& CW) {
    number_of_stations = CW.number_of_stations;
    cars_per_station = CW.cars_per_station;
    stations = CW.stations;

    return *this;
}

// destructor
// memory deallocation is dealt with by the stations vector
// and the individual queues it contains
Car_Wash::~Car_Wash() {}

// user interface
void Car_Wash::interface() {
    srand(time(NULL));

    char choice = 'y';

    int total_time, wash_time;
    double proportion;

    std::cout << "\nDo you wish to run a car-wash simulation? (y/n) ";
    std::cin >> choice;

    while(choice == 'y' || choice == 'Y') {
        std::cout << "\nEnter the total time for the simulation: ";
        std::cin >> total_time;

        std::cout << "Enter the wash time for each vehicle: ";
        std::cin >> wash_time;

        std::cout << "Enter the proportion probability that a driver will seek to recieve a washing: ";
        std::cin >> proportion;

        Car_Wash::simulation(total_time, wash_time, proportion);

        std::cout << "\nDo you wish to run another car-wash simulation? (y/n) ";
        std::cin >> choice;
    }
}


#endif // CAR_WASH_HPP_INCLUDED