#include <iostream>

#include "Orders.h"

using namespace std;

int Order::countOrderID = 0;        //start counter for orders at 0

Order::Order() {
    orderID = incrementCount();
    addDescription();
    setValid(false);
};

Order::Order(const Order* o) {
    orderID = incrementCount();
    addDescription();
    setValid(false);
    cout <<"hi grom order copy constructor\n";
};

Order::~Order(){
    cout<< "Order ID#: " << getOrderID() << " is deleted.\n\n";
}

Order* Order::clone() const {
    return new Order(this);
}

/**
* Checks if valid for execution, invalid orders can exist
*/
bool Order::validate() {
    return this->valid;
};

/**
* Checks player state and executes order
* @param currentState player's current state
*/
void Order::execute(State* currentState) {
    if (currentState->getStateName().compare("executeorders") == 0 && validate() == 1) {
        cout << "Executing order #" << getOrderID() << " ...\n";
    }else cout << "Can NOT execute order #" << getOrderID() << " ...\n";
};

void Order::execute(){};

int Order::incrementCount() {
    return ++countOrderID;
};

int Order::getCount() {
    return countOrderID;
};


void Order::setOrderID(int id) {
    orderID = id;
}

int Order::getOrderID() {
    return orderID;
}

void Order::addDescription() {
    this->description = "(Order Class)";
}

string Order::getDescription() {
    return this->description;
}

void Order::setValid(bool v) {
    this->valid = v;
}

/**
* @brief Stream insertion operator
* Will ouptut to console everytime "cout <<" is used on Order Object
* like toString but directly from cout<<
*/
ostream& operator << (ostream& out, Order* o)
{
    /*
    * Lambda expresion: If true return "true", b/c c++ will return 1
    */
    auto printBoolValue = [](bool b) { if (b) return "true"; else return "false"; };

    out << "OrderID: #" << o->getOrderID() << "\n"
        << "Descrption: " << o->getDescription() << "\n"
        << "Is valid: " << printBoolValue(o->validate()) << "\n\n";
    return out;
}

/************************************************************ Deploy **************************************************************/
Deploy::Deploy() {
    this->addDescription();
}

Deploy::Deploy(const Deploy *d) {
    setOrderID(getCount());
    this->addDescription();
}

Deploy* Deploy::clone() const {
    return new Deploy(this);
}

/**
* Checks player state and executes order
* @param currentState player's current state
*/
void Deploy::execute(State* current) {
    if (current->getStateName().compare("executeorders")==0 && validate() == 1){
        cout << "Executing (Deploy) order #" << getOrderID() << " ...\n";
    } else cout << "Can NOT execute (Deploy) order #" << getOrderID() << " ...\n";
};

/**
* A deploy order tells a certain number of army units taken from the reinforcement 
* pool to deploy to a target territory owned by the player issuing this order.
* @param deployTo territory player is deploying
* @param tOwned territories player has under control
* @param numReinforcements number of available reinforcments
* 
*/
void Deploy::execute(){
    // Order valid, if target territory does not belond to Player
    // if vector<Territory*> attacking != vector<Territory*> defending

    // 

}

void Deploy::addDescription() {
    this->description = "(Deploy) Move a certain number of army units from the current player's \n"
        "            reinforcement pool to one of the current player's territories.";
}

string Deploy::getDescription() {
    return this->description;
}

/************************************************************ Advance **************************************************************/
Advance::Advance() {
    this->addDescription();
}

Advance::Advance(const Advance* a) {
    setOrderID(getCount());
    this->addDescription();
}

Advance* Advance::clone() const {
    return new Advance(this);
}

/**
* Checks player state and executes order
* @param currentState player's current state
*/
void Advance::execute(State* current) {
    if (current->getStateName().compare("executeorders")==0 && validate() == 1){
        cout << "Executing (Advance) order #" << getOrderID() << " ...\n";
    } else cout << "Can NOT execute (Advance) order #" << getOrderID() << " ...\n";
}

void Advance::execute() {}

void Advance::addDescription() {
    this->description = "(Advance) Move a certain number of army units from one territory \n"
            "            (source territory) to another territory (target territory).";
}

string Advance::getDescription() {
    return this->description;
}

/************************************************************ Bomb **************************************************************/
Bomb::Bomb() {
    this->addDescription();
}

Bomb::Bomb(const Bomb* b) {
    setOrderID(getCount());
    this->addDescription();
}

Bomb* Bomb::clone() const{
    return new Bomb(this);
}

/**
* Checks player state and executes order
* @param currentState player's current state
*/
void Bomb::execute(State* current) {
    if (current->getStateName().compare("executeorders")==0 && validate() == 1){
        cout << "Executing (Bomb) order #" << getOrderID() << " ...\n";
    } else cout << "Can NOT execute (Bomb) order #" << getOrderID() << " ...\n";
}

void Bomb::execute(){}

void Bomb::addDescription() {
    this->description = "(Bomb) Destroy half of the army units located on a target territory. \n"
        "            This order can only be issued if a player has the bomb card in their hand.";
}

string Bomb::getDescription() {
    return this->description;
}

/************************************************************ Blockade **************************************************************/
Blockade::Blockade() {
    this->addDescription();
}

Blockade::Blockade(const Blockade* a) {
    setOrderID(getCount());
    this->addDescription();
}

Blockade* Blockade::clone() const{
    return new Blockade(this);
}

/**
* Checks player state and executes order
* @param currentState player's current state
*/
void Blockade::execute(State* current) {
    if (current->getStateName().compare("executeorders")==0 && validate() == 1){
        cout << "Executing (Blockade) order #" << getOrderID() << " ...\n";
    } else cout << "Can NOT execute (Blockade) order #" << getOrderID() << " ...\n";
};

void Blockade::execute() {}

void Blockade::addDescription() {
    this->description = "(Blockade) Triple the number of army units on a target territory and make it a neutral territory. \n"
        "            This order can only be issued if a player has the blockade card in their hand.";
}

string Blockade::getDescription() {
    return this->description;
}

/************************************************************ Airlift **************************************************************/
Airlift::Airlift() {
    this->addDescription();
}

Airlift::Airlift(const Airlift* a) {
    setOrderID(getCount());
    this->addDescription();
}

Airlift* Airlift::clone() const{
    return new Airlift(this);
}

/**
* Checks player state and executes order
* @param currentState player's current state
*/
void Airlift::execute(State* current) {
    if (current->getStateName().compare("executeorders")==0 && validate() == 1){
        cout << "Executing (Airlift) order #" << getOrderID() << " ...\n";
    } else cout << "Can NOT execute (Airlift) order #" << getOrderID() << " ...\n";
};

void Airlift::execute() {}

void Airlift::addDescription() {
    this->description = "(Airlift) Advance a certain number of army units from one from one territory (source territory) to another territory \n"
        "            (target territory). This order can only be issued if a player has the airlift card in their hand.";
}

string Airlift::getDescription() {
    return this->description;
}

/************************************************************ Negotiate **************************************************************/
Negotiate::Negotiate() {
    this->addDescription();
}

Negotiate::Negotiate(const Negotiate* a) {
    setOrderID(getCount());
    this->addDescription();
}

Negotiate* Negotiate::clone() const{
    return new Negotiate(this);
}

/**
* Checks player state and executes order
* @param currentState player's current state
*/
void Negotiate::execute(State* current) {
    if (current->getStateName().compare("executeorders")==0 && validate() == 1){
        cout << "Executing (Negotiate) order #" << getOrderID() << " ...\n";
    } else cout << "Can NOT execute (Negotiate) order #" << getOrderID() << " ...\n";
}

void Negotiate::execute() {}

void Negotiate::addDescription() {
    this->description = "(Negotiate) prevent attacks between the current player and another target player until the end of \n"
        "            the turn. This order can only be issued if a player has the diplomacy card in their hand.";
}

string Negotiate::getDescription() {
    return this->description;
}

/************************************************************ OrdersList **************************************************************/
OrdersList::OrdersList(){
    OL = new vector<Order*>;
}

/**
 * Copy Constructor 
 */
OrdersList::OrdersList(const OrdersList *originalOrderList){
    OL = new vector<Order*>;
    for(int i = 0 ;  i < originalOrderList->OL->size(); i++){
        OL->push_back(originalOrderList->OL->at(i)->clone());
    }

    // for(const auto o : originalOrderList->OL){
    //     OL->push_back(o->clone());
    // }
}; 

OrdersList::~OrdersList(){
    cout <<"...Deleting Orders in OrdersList...\n\n";
    for (auto o : *OL) {
        delete o;   // deallocate memory
        o = NULL;   // prevent dangling pointer error
    }
    cout <<"OrdersList deleted.\n\n";
}

void OrdersList::addOrder(Order *o){
    OL->push_back(o);
}

/**
* Moves order to new location in OL
* @param pos new position
* @param id order ID of order to be moved
*/
bool OrdersList::move(int pos, int id){
    int index;
    // post out of bounds
    int size = OL->size();
    if (pos == 0 || pos < 0 || pos > size) {
        cout << "From move(): position " << pos << " does not exist\n";
        return false;
    }
    // pos = 1, send to front of list
    if (pos == 1) {
        // 0 1 2 3 4 5
        // x y z a b c
        for (auto o : *OL) {
            if (o->getOrderID() == id) {
                index = getIndex(*OL,o);
                OL->erase(OL->begin()+index); // remove Order from List
                OL->insert(OL->begin(),o); // place in front
                return true;
            }
        }
    }
    // pos = last
    if (pos == size) {
        for (auto o : *OL) {
            if (o->getOrderID() == id) {
                index = getIndex(*OL, o);
                OL->erase(OL->begin() + index); // remove Order from List
                OL->push_back(o); // place in back
                return true;
            }
        }
    }
    // first position is >=2
    for (auto o : *OL) {
        if (o->getOrderID() == id) {
            index = getIndex(*OL, o);
            OL->erase(OL->begin() + index); // remove Order from List
            OL->insert(OL->begin()+(pos-1),o); // use insert from list std
            return true;
        }
    }
    return false;
}

bool OrdersList::remove(int id) { 
    int index;
    for (auto o : *OL) {
    if (o->getOrderID() == id) {
            index = getIndex(*OL,o);
            OL->erase(OL->begin()+index); 
            delete o;
            o = NULL;
            return true;
        }
    }
    cout<< "From remove(): Order#" << id << " does not exist\n";
    return false;
}

vector <Order*> * OrdersList::getOL(){
    return OL;
}

int OrdersList::getIndex(vector<Order*> ol, Order *o)
{
    auto it = find(ol.begin(), ol.end(), o);

    if (it != ol.end()) // if element is found 
    {
        int index = it - ol.begin();
        return index;
    }
    else {
        cout << "-1\n";
        return -1;
    }
}

void OrdersList::executeAll(State* s) {
    for (auto o : *getOL()) {
        o->execute(s);
    }
    cout << "\n";
}

void OrdersList::deleteOrdersList(){
    for (auto o : *getOL()) {
        delete o;   // deallocate memory
        o = NULL;   // prevent dangling pointer error
    }
}

ostream& operator << (ostream& out, OrdersList* ol) {
    vector<Order*>::iterator it;
    vector<Order*> OL = *ol->getOL();
    cout << "The OrdersList contains \n------------------------\n";
    int pos = 0;
    for (it = OL.begin(); it != OL.end(); it++)
    {
        cout << "pos: " << ++pos << "\n";
        out << *it;
    }
    return out;
}






