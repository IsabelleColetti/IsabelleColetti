//***************************************************************************
//
//  Isabelle Coletti
//  z1900409
//  CSCI 340 Section 2
//
//  I certify that this is my own work and where appropriate an extension 
//  of the starter code provided for the assignment.
//
//***************************************************************************

#ifndef PARKING_H
#define PARKING_H

#include <string>
#include <iostream>
#include <deque>
#include <stack>

using std::cout;
using std::cin;
using std::endl;

/**
 * Parses the line read in.
 *
 * Parses the line read in and separates the type of action and license
 * plate into their respective variables. 
 * 
 * @param line A reference to a const string that contains the line read 
 *          in from stdin.
 * @param xact_type A reference to a character that should be filled with the 
 *          type of action, A for arrival and D for departure.
 * @param license A reference to a string that should be filled with the 
 *          license plate number.
 *
 ********************************************************************************/
void get_input_vals(const std::string &line, char &xact_type, std::string &license);

//class to make a car object with an id, license plate, and number of moves
class car
{
public:
    car(int id, const std::string &license) : id(id), license(license) {}

    /// Call this to increment the numbner of times the car has been moved.
    void move() { ++num_moves; }

    /// @return the number of times that the car has been moved.
    int get_num_moves() const { return num_moves; }

    /// @return A reference to the license for this car.
    const std::string &get_license() const { return license; }

    /// Overload the << so this can print itself.
    friend std::ostream& operator<<(std::ostream& lhs, const car& rhs)
    {
        lhs << "Car " << rhs.id << " with license plate \"" << rhs.license << "\"";
        return lhs;
    }

private:
    int id;                 ///< The ID number for this car (assigned by the garage)
    std::string license;    ///< license plate of this car.
    int num_moves = {0};    ///< how many times the car was moved within the garage.
};

//class to create a garage object with a next car id, parking lot limit, and parking lot deque
class garage
{
public:
        garage(size_t limit = 10) : parking_lot_limit(limit) {}

        /// @param license The license of the car that has arrived.
        void arrival(const std::string &license);

        /// @param license The license of the car that has departed.
        void departure(const std::string &license);

private:
        int next_car_id = { 1 };
        std::deque<car> parking_lot;
        size_t parking_lot_limit;
};

/**
 * Adds a car to the deque "parking lot".
 *
 * Creates a car object and prints a message announcing its arrival. If the
 * garage is full, prints an error message. If the garage is not full, then
 * the car is added to the deque "parking lot".
 *
 * @param license A reference to a const string that represents the license
 *          plate of the car to be added.
 *
 ********************************************************************************/
void garage::arrival(const std::string &license)
{
    //create a new car object
    car newCar(next_car_id, license);
    
    //increment the id for the next car
    next_car_id++;

    //print the car object to announce its arrival
    cout << newCar << " has arrived." << endl;

    //check to see if the parking lot is full
    if(parking_lot.size() < 10)
    {
        //if the lot is not full, add the new car to the back of the lot
        parking_lot.push_back(newCar);
    }
    else
    {
        //otherwise, if the lot is full, print a message indicating this
        cout << "    But the garage is full!" << endl;
    }
    cout << endl;
}

/**
 * Removes a car from the deque "parking lot".
 *
 * Tries to find a car in the deque with a matching license plate. If found,
 * then the car is moved out of the deque and any cars in front of it are
 * moved out into a stack and then back into the deque in their original
 * order. If the car is not found, prints an error message.
 *
 * @param license A reference to a const string that represents the license
 *          plate of the car to be removed.
 *
 ********************************************************************************/
void garage::departure(const std::string &license)
{
    //create a new temporary stack to hold all the cars that need to be moved
    std::stack<car> temp;

    //set found to false
    bool found = false;

    //loop through the entire parking lot deque
    for(auto it = parking_lot.begin(); it != parking_lot.end(); ++it)
    {
        //see if any elements have a matching license with the key
        if(it->get_license() == license)            //if a car has a matching license,
        {
            //set found to true
            found = true;

            //call the car's move function to increment the number of moves
            it->move();

            //print a message indicating that the car has departed.
            cout << *it << " has departed," << endl;

            //print using the correct formatting depending on the value of the number of moves
            if(it->get_num_moves() == 1)
                cout << "    car was moved " << it->get_num_moves() << " time in the garage." << endl;
            else
                cout << "    car was moved " << it->get_num_moves() << " times in the garage." << endl;

            //remove the car from the "parking lot" deque
            parking_lot.pop_front();

            //exit the loop so you don't continue searching the deque
            break;
        }
        else                //if the car's license plate does not match the key,
        {
            //call the car's move function to increment the number of moves
            it->move();

            //push the car onto the temporary stack
            temp.push(*it);

            //remove the car from the "parking lot" deque
            parking_lot.pop_front();
        }
    }

    //if a car with the key's license plate is not found,
    if(!found)
    {
        //print message indicating it was not found
        cout << "No car with license plate \"" << license << "\" is in the garage." << endl;
    }
    cout << endl;

    //move all the cars on the stack back into the "parking lot" deque
    while(temp.size() > 0)
    {
        //push the top car on the stack to the front of the deque
        parking_lot.push_front(temp.top());
        //remove the car from the stack
        temp.pop();
    }
}

#endif