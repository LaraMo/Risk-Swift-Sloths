#pragma once
#include <time.h>

#include <iostream>
#include <string>
#include <vector>

#include "../CardsDeck/Cards.h"
#include "../GameEngine/GameEngine.h"
#include "../Map/Map.h"
#include "../OrdersList/Orders.h"

using namespace std;

/************************************************************ Player **************************************************************/

class Player {
 private:
  int id;
  vector<Territory*> territories;
  Hand* hand;
  OrdersList* orderList;
  State* state;

  /**
   * Helper method to print the list of territories to attack/defended
   */
  friend ostream& operator<<(ostream& out,
                             Player* o);  // overide Stream insertion operator
  void printTerritories(vector<Territory*> territories);

 public:
  /**
   * Constructor with with an argument list
   */
  Player(vector<Territory*>, Hand*, OrdersList*, int, State*);

  /**
   * Default Constructor
   */
  Player();

  /**
   * Copy Constructor
   */
  Player(const Player&);

  /**
   * Destructor
   */
  ~Player();

  OrdersList* getOrdersList();

  State* getState();

  void setState(State* newState);

  /**
   * Returns a random list of territories that are assigned to the user which
   * they would like to defend
   */
  vector<Territory*> toDefend();

  /**
   * Returns a random list of territories that the user would like to attack
   */
  vector<Territory*> toAttack();

  /**
   * Take in an order and add it into the OrderList
   */
  OrdersList* issueOrder(Order* o);
};

/************************************************************ PlayerDriver **************************************************************/
void testPlayers();