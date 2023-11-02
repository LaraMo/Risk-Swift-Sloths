#pragma once
#include <string>
#include <vector>
#include <time.h>
#include <iostream>

using namespace std;
/*********************************************TO DO *************************************************/
/**
 * global vector that stores the players depending on the number of players entered by user
 * and can be reduced as the number of players will get dropped as the game goes on until one player remains
 * who will be the winner
 * so something like
 * vector<Player*> players;
 * ask user to enter no of players loop to create the players and add them to the vector
 * keep track of dropping the players depending on what happens with the orders from Order class
 * maybe this will be in Asg3 am just thinking because this is the only way the game state will be winstate
*/
    
/************************************************************ State **************************************************************/
class State{
public:
/**
 * Default Constructor
 */
    State();
/**
 * Destructor
 */
    ~State();
/**
 * Constructor with an argument(s)
 */
    State(string name);
/**
 * Assignment Operator
 */
    State& operator=(const State& other);
/**
 * Copy Constructor
 */
    State(const State& other);
/**
 * overide Stream insertion operator
 */
    friend ostream& operator<<(ostream& out, State* s);

    string getStateName();

private:
    string stateName;
};

/************************************************************ Transition **************************************************************/
class Transition{
public:
/**
 * Default Constructor
 */
	Transition();
/**S
 * Destructor
 */
    ~Transition();
/**
 * Constructor with with an argument(s)
 */
	Transition(State*  initialState, string requiredCommand, State*  finalState);
/**
 * Assignment Operator
 */
	Transition& operator=(const Transition& other);
/**
 * Copy Constructor
 */
    Transition(const Transition& other);
/**
 * overide Stream insertion operator
 */
    friend ostream& operator<<(ostream& out, Transition* t);

    string getCommand();

    State * getCurrentState();
    
    State * getNextState();

private:
    State* currentState;
    string command;
    State* nextState;
};
/**
 * This method initializes the game states and then stores them in a Vector
 */
    vector<State*> initializeGameStates();
/**
 * This method initializes the game transitions and then stores them in a Vector
 */
    vector<Transition*> initializeGameTransitions();
/************************************************************ GameEngineDriver **************************************************************/
void testGameStates();