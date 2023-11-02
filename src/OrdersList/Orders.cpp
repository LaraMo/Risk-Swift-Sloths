#include <iostream>

#include "Orders.h"

using namespace std;

int Order::countOrderID = 0;        //start counter for orders at 0

Order::Order() {
    orderID = incrementCount();
    addDescription();
    setValid(false);
};

Order::Order(Order* o) {
    orderID = o->getOrderID();
    addDescription();
    setValid(false);
};

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

int Order::incrementCount() {
    return ++countOrderID;
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

Deploy::Deploy(Deploy *d) {
    setOrderID(d->getOrderID());
    this->addDescription();
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

Advance::Advance(Advance *a) {
    setOrderID(a->getOrderID());
    this->addDescription();
}

/**
* Checks player state and executes order
* @param currentState player's current state
*/
void Advance::execute(State* current) {
    if (current->getStateName().compare("executeorders")==0 && validate() == 1){
        cout << "Executing (Advance) order #" << getOrderID() << " ...\n";
    } else cout << "Can NOT execute (Advance) order #" << getOrderID() << " ...\n";
};

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

Bomb::Bomb(Bomb* a) {
    setOrderID(a->getOrderID());
    this->addDescription();
}

/**
* Checks player state and executes order
* @param currentState player's current state
*/
void Bomb::execute(State* current) {
    if (current->getStateName().compare("executeorders")==0 && validate() == 1){
        cout << "Executing (Bomb) order #" << getOrderID() << " ...\n";
    } else cout << "Can NOT execute (Bomb) order #" << getOrderID() << " ...\n";
};

void Bomb::addDescription() {
    this->description = "(Bomb) Destroy half of the army units located on a target territory. \n"
        "            This order can only be issued if a player has the bomb card in their hand.";
}

string Bomb::getDescription() {
    return this->description;
}

/************************************************************ Blockade **************************************************************/Blockade::Blockade() {
    this->addDescription();
}

Blockade::Blockade(Blockade* a) {
    setOrderID(a->getOrderID());
    this->addDescription();
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

Airlift::Airlift(Airlift *a) {
    setOrderID(a->getOrderID());
    this->addDescription();
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

Negotiate::Negotiate(Negotiate* a) {
    setOrderID(a->getOrderID());
    this->addDescription();
}

/**
* Checks player state and executes order
* @param currentState player's current state
*/
void Negotiate::execute(State* current) {
    if (current->getStateName().compare("executeorders")==0 && validate() == 1){
        cout << "Executing (Negotiate) order #" << getOrderID() << " ...\n";
    } else cout << "Can NOT execute (Negotiate) order #" << getOrderID() << " ...\n";
};

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
OrdersList::OrdersList(const OrdersList &originalOrderList){
    OL = new vector<Order*>;
    for(int i = 0 ;  i < originalOrderList.OL->size(); i++){
         OL->push_back(originalOrderList.OL->at(i));
    }
};

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
    auto it = find_if(ol.begin(), ol.end(), [o](Order* element) {
        return element == o;
    });

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






