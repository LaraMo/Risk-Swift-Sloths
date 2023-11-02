#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include "../GameEngine/GameEngine.h"

using namespace std;

class Order
{
public:

    Order();

    Order(Order* o);

    /**
    * Checks if valid for execution, invalid orders can exist
    */
    bool validate();
    
    /**
    * Checks player state and executes order
    */
    virtual void execute(State *currentState);

    /**
    * Increment countOrderID by 1
    */
    int incrementCount(); 

    void setOrderID(int id);

    int getOrderID();

    virtual void addDescription();

    virtual string getDescription();

    /**
    * Increment countOrderID by 1
    */
    void setValid(bool v);
protected:
    string description;
private:
    static int countOrderID;
    int orderID;
    bool valid;
    friend ostream& operator << (ostream& out, Order* o); // overide Stream insertion operator
};

class Deploy : public Order
{
public:
    Deploy();

    Deploy(Deploy* d);

    void execute(State *currentState);

    void addDescription();

    string getDescription();
};

class Advance : public Order
{
public:
    Advance();

    Advance(Advance* a);

    void execute(State *currentState);

    void addDescription();

    string getDescription();
private:
};

class Bomb : public Order
{
public:
    Bomb();

    Bomb(Bomb* a);

    void execute(State *currentState);
    
    void addDescription();
    
    string getDescription();
private:
};

class Blockade : public Order
{
public:
    Blockade();
   
    Blockade(Blockade* a);
    
    void execute(State *currentState);
    
    void addDescription();
    
    string getDescription();
private:
};

class Airlift : public Order
{
public:
    Airlift();
    
    Airlift(Airlift* a);
    
    void execute(State *currentState);
    
    void addDescription();
    
    string getDescription();
private:
};

class Negotiate : public Order
{
public:
    Negotiate();
    
    Negotiate(Negotiate* a);
    
    void execute(State *currentState);
    
    void addDescription();
    
    string getDescription();
private:
};

class OrdersList
{
public:
    OrdersList();
    
    //TODO: copy constructor

    virtual void addOrder(Order* o);

    /**
    * Moves order to new location in OL
    * @param pos new position 
    * @param id order ID of order to be moved
    */
    bool move(int pos, int id);
    
    bool remove(int id);
    
    vector <Order*> * getOL();

    int getIndex(vector<Order*> ol, Order *o);

    void executeAll(State *s);
    
    void deleteOrdersList();


    /**
     * Copy Constructor 
     */
    OrdersList(const OrdersList &originalOrderList);
  
private:
    vector<Order*> *OL;

    friend ostream& operator << (ostream& out, OrdersList* ol); // overide Stream insertion operator

};

/** 
* test driver A1
*/
void testOrdersLists();

