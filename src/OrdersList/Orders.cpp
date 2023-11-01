#include <iostream>
#include <cstdlib>

#include "Orders.h"
#include "../Player/Player.h"

using namespace std;

int Order::countOrderID = 0;        //start counter for orders at 0
bool Order::pGivenCardThisTurn = false;

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
bool Order::validate(){ return false;}

bool Order::getValid() {
    return this->valid;
};

void Order::setValid(bool v) {
    this->valid = v;
}

/**
* Checks player state and executes order
* @param currentState player's current state
*/
void Order::execute(State* currentState) {
    if (currentState->getStateName().compare("executeorders") == 0 && getValid() == 1) {
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

string Order::getOrderName(){return "Order";}

void Order::setPlayerGivenCardThisTurn(bool b){pGivenCardThisTurn = b;}

bool Order::getPlayerGivenCardThisTurn() { return pGivenCardThisTurn; }

bool Order::pOwnsTerr(Player* p, Territory* t){
    return (t->getOwnerId() == p->getID());
}

bool Order::terrIsAdjP(Territory *t1, Territory *t2){
    for (auto adj : t1->getAdjacencyList()) {
        // true: if valid and territory name matches name in players list territories
        if (adj->getName().compare(t2->getName()) == 0) {
            return true;
        }
    }
    return false;
}

bool Order::terrHasOwner(Territory* t){
    if(t->getOwnerId()<=0)
        return false;
    return true;
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

    out << o->getOrderName()
        << " | ID: #" << o->getOrderID()
        << " | Valid: " << printBoolValue(o->getValid()) << "\n\n";
    return out;
}

/************************************************************ Deploy **************************************************************/
Deploy::Deploy() {
    this->addDescription();
}

Deploy::Deploy(Player* p, Territory* terrToDeploy, int numReinToDeploy) {
    this->p = p;
    this->terrToDeploy = terrToDeploy;
    this->numReinToDeploy = numReinToDeploy;
    setValid(validate());
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
    if (current->getStateName().compare("executeorders")==0 && getValid() == 1){
        cout << "Executing (Deploy) order #" << getOrderID() << " ...\n";
    } else cout << "Can NOT execute (Deploy) order #" << getOrderID() << " ...\n";
};

/*
* Checks if Deploy is valid and Player owns Territory to deploy,
* then adds reinforcments.
*/
void Deploy::execute() {

    if(getValid()){
        if (!(p->getState()->getStateName().compare("executeorders") == 0)){
            cout << "Can NOT execute Deploy " << this->terrToDeploy->getName()
                << " | Player #" << p->getID() << " is not in Execute Orders State\n";
            return; //exit function
        }
        p->subtractReinforcemnts(numReinToDeploy);
        terrToDeploy->addToArmyCount(numReinToDeploy);
        cout << "Deploy executed | Player #" << p->getID() << " now has "
            << terrToDeploy->getArmyCount() << " reinforcments in Territory "
            << this->terrToDeploy->getName() <<"\n";
    }
    else if(this->numReinToDeploy==0){
        cout << "Can NOT execute Deploy " << this->terrToDeploy->getName()
             << " | Deploy has 0 reinforcments\n";
    }else if(!pOwnsTerr(p,terrToDeploy)){
        cout << "Can NOT execute Deploy " << this->terrToDeploy->getName()
            << " | Player #" << p->getID() << " does NOT own territory\n";
    }
    else if (!pHasEnoughRein()) { //player has enough reinforcemnts
        cout << "Can NOT execute Deploy " << this->terrToDeploy->getName()
             << " | Player #" << p->getID() << " does NOT enough have reinforcments\n";
    }
}

/**
 * @brief return true and Deploy is valid and Player owns Territory to deploy
 */
bool Deploy::validate(){
    if (this->numReinToDeploy == 0)
        return false;
    if (!pHasEnoughRein()) { //player has enough reinforcemnts
        return false;
    }
    if(pOwnsTerr(p, terrToDeploy))
        return true;
    return false;
}

bool Deploy::pHasEnoughRein(){ return (p->getReinforcement() - numReinToDeploy >= 0);}

void Deploy::addDescription() {
    this->description = "(Deploy) Move a certain number of army units from the current player's \n"
        "            reinforcement pool to one of the current player's territories.";
}

string Deploy::getDescription() {
    return this->description;
}

string Deploy::getOrderName() { return "Deploy"; }

/************************************************************ Advance **************************************************************/
Advance::Advance() {
    this->addDescription();
}

Advance::Advance(const Advance* a) {
    setOrderID(getCount());
    this->addDescription();
}


Advance::Advance(Player* p, Territory* terrSource, Territory* terrTarget, int numReinToAdvnce) {
    this->p = p;
    this->terrSource = terrSource;
    this->terrTarget = terrTarget;
    this->numReinToAdvnce = numReinToAdvnce;
    setValid(validate());
    setPlayerGivenCardThisTurn(false);
}

Advance* Advance::clone() const {
    return new Advance(this);
}

/**
* Checks player state and executes order
* @param currentState player's current state
*/
void Advance::execute(State* current) {
    if (current->getStateName().compare("executeorders")==0 && getValid() == 1){
        cout << "Executing (Advance) order #" << getOrderID() << " ...\n";
    } else cout << "Can NOT execute (Advance) order #" << getOrderID() << " ...\n";
}

/*
* 
*/
void Advance::execute() {
    if(this->getValid()){ // advance is valid
        if (!(p->getState()->getStateName().compare("executeorders") == 0)) { // player in execute phase
            cout << "Can NOT execute Advance " << this->terrTarget->getName()
                << " | Player #" << p->getID() << " is not in Execute Orders State\n";
            return; //exit function
        }
        if(pOwnsTerr(p,this->terrTarget)){ // player owns target
           if(terrSource->getArmyCount() < numReinToAdvnce){ //check source has enough reinforcments to give to target
               cout << "Can NOT execute Advance " << this->terrSource->getName()
                    << " | The number of Army units to Advance is greater than Source Terriotory has. \n";
                return ; //exit function
           }
            terrSource->subFromArmy(numReinToAdvnce);
            terrTarget->addToArmyCount(numReinToAdvnce);
            cout << "Advance executed (player owns both Territories) | "
                <<terrSource->getName() << " has army of " << terrSource->getArmyCount() <<", "
                << terrTarget->getName() <<" has army of " << this->terrTarget->getArmyCount() << "\n";
        
        } else if (!pOwnsTerr(p, this->terrTarget)) { // player does not own target
            int winner = battle();
            cout << "...The battle has ended printing both Terriories after battle...\n"
                << terrSource
                << terrTarget;
            if(winner == 1){
                occupyConqueredTerr();
                cout << "Advance executed (player attacks target) | player " <<p->getID() 
                    << " has occupied " << this->terrTarget->getName() << " with " 
                    << this->terrSource->getArmyCount() << " army ";
                //TODO: each player can not receive more than one card per turn, maybe check if any more advnces in OL per person
                if(!Order::getPlayerGivenCardThisTurn()){ //if not given card this turn  
                    string newCard = givePLayerNewCard();
                    cout << "| Player given " << newCard <<" card";
                    Order::setPlayerGivenCardThisTurn(true);
                }else{
                    cout << "| Player already given card. ";
                }
                cout<<"\n";
            }
            if (winner == 0){
                cout << "Advance executed (player attacks target) | player " << p->getID()
                    << " has NOT occupied " << this->terrTarget->getName() << " and has 0 army in "
                    << this->terrSource->getName();
                //TODO: if attakicking army loses, set territory to NO owner?
                p->eraseTerritory(this->terrSource); // set attacking army Territory to no owner 
            } 
        }
    }
    else {
        cout << "Can NOT execute Advance " << this->terrSource->getName()
        << " | Player does not own source \n";
    }
}

/**
 * @brief Valid if Territory is adjacant and player owns Source Territory
 */
bool Advance::validate() {
    if(terrIsAdjP(this->terrSource,this->terrTarget) && pOwnsTerr(p,this->terrSource))
        return true;
    return false;
}

/**
* Simulates battle between Source and Targer Territories, source attacks first. 
* RoundRobin style Source and Target will have a 60% adn 70% chance
* of winning an attack or defend, and the resulting army will lose 1
* of their army forces until one territory reaches 0 armies. 
* @return int 1 if source wins (target army = 0), 0 target wins (source army = 0)
*          if 2, error;
*/
int Advance::battle(){
    cout <<"... Enetering battle ...\n";
    srand((unsigned)time(NULL)); // set seed for random number
    while(this->terrSource->getArmyCount()>0 && this->terrTarget->getArmyCount()>0){ // stop when one Territory has 0 army
        int random = (rand() % 10) + 1; // random number between 1-10
        if(random <= 6) // source attack succesful
            this->terrTarget->subFromArmy(1); // -1 army from target  
        
        random = (rand() % 10) + 1; // call agan for target defence
        if(random <= 7) // defend succesffy 
            this->terrSource->subFromArmy(1); // -1 army from source
    }
    if(this->terrTarget->getArmyCount() == 0)
        return 1;
    if (this->terrSource->getArmyCount() == 0)
        return 0;
    return 2;
}

/**
* Move all army units from Source Territory to Target Territory, 
* and declare attacking Player ownership of Target Territory. 
*/
void Advance::occupyConqueredTerr(){
    this->terrTarget->setArmCount(this->terrSource->getArmyCount()); // move source army into target Territory
    this->terrTarget->setOwnerId(this->terrSource->getId()); // ownership transfer from target to source
}

string Advance::givePLayerNewCard() {
    srand((unsigned)time(NULL)); // set seed for random number
    int r = (rand() % 4) + 1; // random number between 1-5
    
    string cardName;
    if(r == 1)
        cardName = "Bomb";
    if(r == 2)
        cardName = "Blockade";
    if(r == 3)
        cardName = "Airlift";
    if(r == 4)
        cardName = "Deplomacy";
    
    Card* c = new Card(cardName);
    p->getHand()->addCard(c);
    return cardName;
}

void Advance::addDescription() {
    this->description = "(Advance) Move a certain number of army units from one territory \n"
            "            (source territory) to another territory (target territory).";
}

string Advance::getDescription() {
    return this->description;
}

string Advance::getOrderName() { return "Advance"; }

/************************************************************ Bomb **************************************************************/
Bomb::Bomb() {
    this->addDescription();
}

Bomb::Bomb(const Bomb* b) {
    setOrderID(getCount());
    this->addDescription();
}

Bomb::Bomb(Player* p, Territory* terrTarget){
    this->p = p;
    this->terrTarget = terrTarget;
    setValid(validate());
}

Bomb* Bomb::clone() const{
    return new Bomb(this);
}

/**
* Checks player state and executes order
* @param currentState player's current state
*/
void Bomb::execute(State* current) {
    if (current->getStateName().compare("executeorders")==0 && getValid() == 1){
        cout << "Executing (Bomb) order #" << getOrderID() << " ...\n";
    } else cout << "Can NOT execute (Bomb) order #" << getOrderID() << " ...\n";
}

void Bomb::execute(){
    if(getValid()){
        halfArmyUnits(this->terrTarget);
        cout << "Bomb executed | "
            << terrTarget->getName() << " army is havled, and is now " 
            << terrTarget->getArmyCount() << "\n";
    }
    if(!terrHasOwner(terrTarget)){
        cout << "Bomb can NOT be executed | "
            << terrTarget->getName()
            << " does not have an owner";
    }
    else if(p->ownsTerritory(this->terrTarget)){
        cout << "Bomb can NOT be executed | "
            << "player owns" <<terrTarget->getName()
            << terrTarget->getArmyCount() << "\n";
    }
    else if(!terrTargetIsAdjP()) {
        cout << "Bomb can NOT be executed | "
            << "player has no adjacent territories to" << terrTarget->getName()
            << "\n";
    }
}

bool Bomb::validate(){
    if(p->ownsTerritory(this->terrTarget))
        return false;
    if(!terrTargetIsAdjP())
        return false;
    if(!terrHasOwner(terrTarget))
        return false;
    return true;
}

bool Bomb::terrTargetIsAdjP(){
    for (auto t : p->getTerritories()){
        for (auto adj: t->getAdjacencyList()){
            if (adj->getName().compare(this->terrTarget->getName()) == 0)
                return true;
        }
    }
    return false;
}

void Bomb::halfArmyUnits(Territory *t){
    int armySize = t->getArmyCount();
    if(armySize%2 == 0){
        armySize = armySize / 2;
    }else{
        armySize = (armySize / 2) + 1; //round upp
    }
    t->setArmCount(armySize);
}

void Bomb::addDescription() {
    this->description = "(Bomb) Destroy half of the army units located on a target territory. \n"
        "            This order can only be issued if a player has the bomb card in their hand.";
}

string Bomb::getDescription() {
    return this->description;
}

string Bomb::getOrderName() { return "Bomb"; }

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
    if (current->getStateName().compare("executeorders")==0 && getValid() == 1){
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

string Blockade::getOrderName() { return "Blockade"; }

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
    if (current->getStateName().compare("executeorders")==0 && getValid() == 1){
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

string Airlift::getOrderName() { return "Airlift"; }

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
    if (current->getStateName().compare("executeorders")==0 && getValid() == 1){
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

string Negotiate::getOrderName() { return "Negotiate"; }

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

void OrdersList::executeAll() {
    for (auto o : *getOL()) {
        cout << "Order #" << o->getOrderID() << "\n";
        o->execute();
    }
    cout << "\n";
}

void OrdersList::executeNextOrder(State* s) {
    auto it = *getOL()->begin();
    it->execute();
    cout << "\n";
}

void OrdersList::deleteOrdersList(){
    for (auto o : *getOL()) {
        delete o;   // deallocate memory
        o = NULL;   // prevent dangling pointer error
    }
    getOL()->clear();
}

ostream& operator << (ostream& out, OrdersList* ol) {
    vector<Order*>::iterator it;
    vector<Order*> OL = *ol->getOL();
    cout << "The OrdersList contains \n------------------------\n";
    int pos = 0;
    for (it = OL.begin(); it != OL.end(); it++)
    {
        out << "pos: " << ++pos
            << " | Order: " << *it;
    }
    return out;
}






