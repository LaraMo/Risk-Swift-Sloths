#include "Orders.h"
#include "../CardsDeck/Cards.h"
#include "../Player/Player.h"
#include "../Map/Map.h"

void testOrdersLists() {
    cout << "\n************************************\n"
        << "Time to test Orders and OrdersList!! \n"
        << "************************************\n\n";

    cout << "\n\n---------> Test 1: Create Orders and OrdersList <---------\n\n\n";

    cout << "...Creating orders of every type... \n";
    Order* o1 = new Order();
    Deploy* d1 = new Deploy();
    Advance* a1 = new Advance();
    Bomb* b1 = new Bomb();
    Blockade* blk1 = new Blockade();
    Airlift* air1 = new Airlift();
    Negotiate* n1 = new Negotiate();
    cout << "Orders of type: Order, Deploy, Advance, Bomb, Blockade, Airlift and Negotiate have been created. \n\n";

    cout << "...Creating an OrdersList... \n";
    OrdersList *OL = new OrdersList();
    cout << "Ordrslist has been created \n\n";

    cout << "...Adding Orders to OrdersList....\n";
    OL->addOrder(o1);
    OL->addOrder(d1);
    OL->addOrder(a1);
    OL->addOrder(b1);
    OL->addOrder(blk1);
    OL->addOrder(air1);
    OL->addOrder(n1);
    cout << "Orders have been added to OrdersList \n\n";

    cout << "...Printing Orders List with ostream:....\n\n";
    cout << OL;



    cout << "\n\n---------> Test 2: Create Copies of Each Order <---------\n\n\n";

    cout << "...Creating copies of each Order... \n";
    Order* o1Copy = new Order(o1);
    Deploy* d1Copy = new Deploy(d1);
    Deploy* d1Copy2 = d1;
    Advance* a1Copy = new Advance(a1);
    Bomb* b1Copy = new Bomb(b1);
    Blockade* blk1Copy = new Blockade(blk1);
    Airlift* air1Copy = new Airlift(air1);
    Negotiate* n1Copy = new Negotiate(n1);
    cout << "Copies of each Order have been created. \n\n";

    OrdersList *OLCopy = new OrdersList();

    cout << "...Adding copies of Orders in a new OrdersList:...\n";
    OLCopy->addOrder(o1Copy);
    OLCopy->addOrder(d1Copy);
    OLCopy->addOrder(a1Copy);
    OLCopy->addOrder(b1Copy);
    OLCopy->addOrder(blk1Copy);
    OLCopy->addOrder(air1Copy);
    OLCopy->addOrder(n1Copy);
    cout << "Copies of Orders added.\n\n";

    cout << "...Printing Copy OrdersList...\n";
    cout << OLCopy;



    cout << "\n\n---------> Test 3: Validate <---------\n\n\n";

    cout << "...Setting order (parent class) to valid ...\n";
    o1->setValid(true);
    cout << "Order is now valid\n\n";

    cout << "...Seeting deploy to valid ...\n";
    d1->setValid(true);
    cout << "Deploy is now valid\n\n";

    cout << "...Setting blockade to valid ...\n";
    blk1->setValid(true);
    cout << "blockade is now valid\n\n";

    cout << "...Printing OrdersList with new valid Orders ...\n\n";
    cout << OL;


    cout << "\n\n---------> Test 4: Execute <---------\n\n\n";

    cout << "...Exectuing orders:... \n";
    cout << "Note: - only valid Orders can be executed\n";
    cout << "      - All orders are in proper state\n\n";
    
    State* sTest = new State("executeorders");

    cout << "...Executing order(parent class)...\n";
    o1->execute(sTest);
    cout << "\n";
    cout << "...Executing Deploy ...\n";
    d1->execute(sTest);
    cout << "\n";
    cout << "...Execting Advance ...\n";
    a1->execute(sTest);
    cout << "\n";
    cout << "...Executing Bomb ...\n";
    b1->execute(sTest);
    cout << "\n";
    cout << "...Executing Blockaid ...\n";
    blk1->execute(sTest);
    cout << "\n";
    cout << "...Executing Airlift ...\n";
    air1->execute(sTest);
    cout << "\n";
    cout << "..Executing Negotiate ...\n";
    n1->execute(sTest);
    cout << "\n\n";


    cout << "\n\n---------> Test 5: Remove Orders <---------\n\n\n";

    cout << "Removing orders 5, 6 and 7 from Orderslist \n";
    if (OL->remove(5)) cout << "Removed order #5 \n"; else cout << "Did NOT remove order #5\n";
    if (OL->remove(6)) cout << "Removed order #6 \n"; else cout << "Did NOT remove order #6\n";
    if (OL->remove(7)) cout << "Removed order #7 \n"; else cout << "Did NOT remove order #7\n";
    if (OL->remove(9)) cout << "Removed order #9 \n"; else cout << "Did NOT remove order #9\n";
    cout << OL;



    cout << "\n\n---------> Test 6: Move Orders <---------\n\n\n";

    cout << '\n' << "Testing Move() that are out of bounds or don't exist\n";
    if (OL->move(0, 4)) cout << "Moving order #4 to position 0\n"; else cout << "Can NOT move order #4 to position 0\n";
    if (OL->move(-2, 4)) cout << "Moving order #4 to position -2\n"; else cout << "Can NOT move order #4 to position -2\n";
    if (OL->move(10, 4)) cout << "Moving order #4 to position 10\n"; else cout << "Can NOT move order #4 to position 10\n";

    cout << '\n' << "Moving orders\n";
    if (OL->move(1, 4)) cout << "Moving order #4 to position 1\n"; else cout << "Can NOT move order #4 to position 1\n";
    cout << OL << '\n';
    if (OL->move(4, 1)) cout << "Moving order #1 to position 4\n"; else cout << "Can NOT move order #4 to position 3\n";
    cout << OL << '\n';
    if (OL->move(2, 3)) cout << "Moving order #2 to position 3\n"; else cout << "Can NOT move order #4 to position 3\n";
    cout << OL;
   
    cout << "\n\n---------> Test 7: Execute Player Orders <---------\n\n\n";
   
    vector<Territory*> tOL;
    Hand* hOL = new Hand();
    OrdersList *pOL = new OrdersList();
    
    //Initializing Territory adjeceny list
    Territory* t1OL = new Territory("UK", 1, 2, 0);
    Territory* t2OL = new Territory("USA", 2, 3, 0);
    tOL.push_back(t1OL);
    tOL.push_back(t2OL);

    //Create player orders
    Order* pOr1 = new Order();
    Deploy* pD1 = new Deploy();
    Advance* pA1 = new Advance();
    Bomb* pB1 = new Bomb();

    //Add player order to orders list
    pOL->addOrder(pOr1);
    pOL->addOrder(pD1);
    pOL->addOrder(pA1);
    pOL->addOrder(pB1);

    cout << "...Creating state executeorders...\n";
    State* pStateOL = new State("executeorders");
    cout << "Created execute orders.\n\n";

    cout << "...Creating player with t adjeceny list, Hand, and order list..\n";
    Player* p = new Player(tOL, hOL, pOL, 1, pStateOL);
    cout << "Created player.\n\n";

    cout << "...Printing Players orders..\n";
    cout << "-------------------------------\n";
    cout << p->getOrdersList();

    cout << "...Setting players 2nd and 4th orders to valid..\n";
    p->getOrdersList()->getOL()->at(1)->setValid(true);
    p->getOrdersList()->getOL()->at(3)->setValid(true);
    cout << "Players 2nd and 4th orders are valid.\n\n";


    cout << "If Player is inside execute  rders state and will be able to execute!\n\n";
    cout << "...Executing players orders...\n";
    cout << "-------------------------------\n";
    p->getOrdersList()->executeAll(p->getState());


    cout << "\n\n---------> Test 8: Deep Copy Constructor <---------\n\n\n";

    cout << "...Creating OrdersList";
    cout << "...Creating orders of every type... \n";
    Order* o2 = new Order();
    Deploy* d2 = new Deploy();
    Advance* a2 = new Advance();
    Bomb* b2 = new Bomb();
    cout << "Orders of type: Order, Deploy, Advance, Bomb"; 
    cout << "...Creating an OrdersList... \n";
    OrdersList* OL2 = new OrdersList();
    cout << "Ordrslist has been created \n\n";

    cout << "...Adding Orders to OrdersList....\n";
    OL2->addOrder(o2);
    OL2->addOrder(d2);
    OL2->addOrder(a2);
    OL2->addOrder(b2);
    cout << "Orders have been added to OrdersList \n\n";

    cout << "...Printing Orders List with ostream:....\n\n";
    cout << OL2;

    cout <<"...Creating copy of order list...\n";
    OrdersList* OL2Copy = new OrdersList(OL2);

    cout << "...Printing COPY Orders List with ostream:....\n\n";
    cout << OL2Copy;

    cout << "...comparing order pointer addresses ...\n";
    cout << "...address from ORIGINAl list ...\n";
    for (auto it2 = OL2->getOL()->begin(); it2 != OL2->getOL()->end(); it2++)
    {
        cout << &*it2 << "\n";
    }
    cout << "...address from COPY list ...\n";
    for (auto it2 = OL2Copy->getOL()->begin(); it2 != OL2Copy->getOL()->end(); it2++)
    {
        cout << &*it2 <<"\n";
    }



    cout << "\n\n---------> Test 9: Deleting Pointers <---------\n\n\n";

    cout << "...Test 8: Deleting pointers..\n";
    delete OL;
    OL = NULL;
    delete OLCopy;
    OLCopy = NULL;
    delete t1OL;
    t1OL = NULL;
    delete t2OL;
    t2OL = NULL;
    // delete hOL --> hand deletion is managed by the player as it belongs to it;
    hOL = NULL;
    delete p;
    p = NULL;
    // delete pStateOL --> state will be also deleted by the player;
    pStateOL = NULL;
    delete sTest;
    sTest = NULL;
    delete OL2;
    OL2 = NULL;
    delete OL2Copy;
    OL2Copy = NULL;

    cout << "Pointers deleted.\n\n";
};



/************************************************************ Test Driver 2 **************************************************************/

void testOrderExecution() {
    cout <<  "\n*****************************\n"
            << "Time to test OrderExecution!! \n"
            << "*****************************\n\n";
    
    // issueORders
    // go to each player ask then pick to add orders in the following sequence
    // pick 1 card > all Deploy > all Executions

    // execute orders
    // must be in following sequence
    // round-robin = one player order at a time from each player, back and forth
    // A. 1 card order of each player
    // B. 1 deploy per person at a time
    // C. 1 advance each player at a time 

    // *** Test FLow *** 
    // Phase 1: set-up
    // 1. Load Map
    // 2. Create two players

    // Phase 2: test each order
    // test Deploy: 
    // show that fails if player tries to move reinforcemnts to wrong location

    cout << "********** Preliminary Phase *********\n\n"


         << "---------> Load Map: Europe <---------\n\n";

    cout <<"...Loading Map of Europe...\n";
    MapLoader* loader = new MapLoader();
    Map* map1 = loader->loadMap("Map/MapFolder/Europe.map");
    cout <<"Map of Europe Loaded.\n\n";
    
    // cout << "...Printing contents...\n";
    // map1->printMapSummary();
    // cout << "Map printed.\n\n";

    cout << "...Validating contents...\n";
    map1->validate();




    cout << "\n\n---------> Create Player 1 <---------\n\n\n";

    vector<Territory*> t;
    Hand* h = new Hand();
    OrdersList* pOL = new OrdersList();

    cout << "...Creating state executeorders (must be in this state to execute orders)...\n";
    State* pState = new State("executeorders");
    cout << "Created state executeorders.\n\n";

    cout << "...Creating player 1 with t adjeceny list, Hand, and order list..\n";
    Player* p1 = new Player(t, h, pOL, 1, pState); // 1 is id
    cout << "Created player.\n\n";

    cout << p1;

    auto printBoolValue = [](bool b) { if (b) return "VALID\n"; else return "NOT VALID\n"; };



    
    cout << "\n\n************** Testing Phase ************\n\n"


             << "---------> Test 1: Deploy  <---------\n\n\n";

    cout << "...Assign Denmark as starting Terrirtory to player 1...\n\n";
    Territory* denmark = map1->getTerritory("Denmark");
    p1->addTerritory(denmark);
    
    cout << "...Assigning 10 reinforecments to player 1 ...\n";
    p1->addReinforcement(10);

    cout << "...Confirm Denamrk owner ID and player ID match...\n";
    cout << denmark;
    cout <<"Player 1 | ID: " <<p1->getID() <<"\n\n";
    if(denmark->getOwnerId()==p1->getID())
        cout <<"We can see owner ID and player ID match.\n\n";
    else 
        cout << "We can see owner ID and player ID do NOT match.\n\n";

    cout << "...Creating a GOOD Deploy Order to Denmark ...\n";
    Deploy* d1 = new Deploy(p1, denmark, 5);

    cout << "...Creating a BAD Deploy Order to Scotland ...\n";
    Territory* scotland = map1->getTerritory("Scotland");
    Deploy* d2 = new Deploy(p1, scotland, 5);

    cout << "...Creating a BAD Deploy Order to with 0 reinforcments ...\n";
    Deploy* d3 = new Deploy(p1, denmark, 0);

    cout << "...Creating a BAD deploy Player does not have enough reinforcments ...\n\n";
    Deploy* d4 = new Deploy(p1, denmark, 50);

    cout << "...Testing if Deploys are Valid() ...\n";
    cout << "Denmark Deploy is " << printBoolValue(d1->validate());
    cout << "Scotland Deploy is " << printBoolValue(d2->validate());
    cout << "Denmark Deploy with 0 reinforcnments Deploy is " << printBoolValue(d3->validate());
    cout << "Denmark Deploy with 50 reinforcnments Deploy is " << printBoolValue(d3->validate()) << "\n";

    cout << "...Issueing Deploys to Player 1 ...\n";
    p1->issueOrder(d1);
    p1->issueOrder(d2);
    p1->issueOrder(d3);
    p1->issueOrder(d4); 

    cout << "...Show Player 1 has Deploys and 10 reinforcments ...\n\n";
    cout << p1;

    cout << "...Executing all order for player 1 ...\n\n";
    p1->getOrdersList()->executeAll();

    cout << "...Show Player 1 has Deploys and 5 reinforcments ...\n\n";
    cout << p1;

    cout << "...Testing WRONG state will NOT execute ...\n\n";
    p1->getState()->setStateName("BadState");

    cout << "...Attempting execute while in WRONG state ...\n"
         << "Executing (Deploy) #" << p1->getOrdersList()->getOL()->at(0)->getOrderID() << " | ";
    p1->getOrdersList()->getOL()->at(0)->execute(); // execute first order in player OrdersList
    cout << "\n";

    cout << "...Changeing state back to executeorders  ...\n\n";
    p1->getState()->setStateName("executeorders");

    cout << "...Deleting Player 1 OrdersList...\n\n";
    p1->getOrdersList()->deleteOrdersList();

    cout << "...Deleting Player 1 Territories...\n\n";
    p1->eraseTerritory(denmark);



    
    cout << "\n\n---------> Test 2: Advance <---------\n\n\n";

    cout << "...Assiging Player 1 Denmark...\n\n";
    Territory* t2denmark = map1->getTerritory("Denmark");
    p1->addTerritory(t2denmark);

    cout << "...Set Denmark 10 Army forces...\n\n";
    t2denmark->setArmyCount(30);

    cout << "...Denmark is adjacent too the following...\n";
    for (auto t : t2denmark->getAdjacencyList()) { cout << t->getName() << " | "; }
    cout << "\n\n";

    cout << "...Assign Southen Sweden to Player 1 and West Germany to aribitrary Player 2...\n\n";
    Territory* t2sweden = map1->getTerritory("Southern Sweden");
    Territory* t2germany = map1->getTerritory("West Germany");
    p1->addTerritory(t2sweden);
    t2germany->setOwnerId(2);

    cout << "...Assign Sweden 5 forces and Germany 5 forces...\n\n";
    t2sweden->setArmyCount(5);
    t2germany->setArmyCount(5);

    cout << "...Print Territories...\n\n";
    cout << t2denmark // p1 owns
        << t2sweden // p1 owns
        << t2germany; // p1 does NOT own

    cout << "...Create Advance orders ...\n";
    cout << "...Creating GOOD Advance, player will add army to owned Territory ...\n";
    Advance* a1 = new Advance(p1, t2denmark, t2sweden, 5);
    cout << "...Creating GOOD Advance, player will attack Germany ...\n";
    Advance* a2 = new Advance(p1, t2denmark, t2germany, 5);
    cout << "...Creating BAD Adavance, player does not own Germany ...\n";
    Advance* a3 = new Advance(p1, t2germany, t2germany, 5);
    cout << "...Creating VALID/BAD Adavance, source Territory does Not have enough army to give to owned target ...\n";
    Advance* a4 = new Advance(p1, t2denmark, t2sweden, 50);
    cout << "...Creating GOOD Advance, player will lose the battle  ...\n";
    Territory* t2norway = map1->getTerritory("Norway");
    Territory* t2scotland = map1->getTerritory("Scotland");
    p1->addTerritory(t2scotland);
    t2scotland->setArmyCount(5);
    t2norway->setArmyCount(20);
    t2norway->setOwnerId(2);
    Advance* a5 = new Advance(p1, t2scotland, t2norway, 5);

    cout << "\n\n...Testing if Advances are Valid() ...\n";
    cout << "Advance to owned Sweden is: " << printBoolValue(a1->validate());
    cout << "Advance to attack Germany is: " << printBoolValue(a2->validate());
    cout << "Advance p1 does NOT own Source germany is: " << printBoolValue(a3->validate());
    cout << "Advance owned source does not have enough Army for ownd target: " << printBoolValue(a4->validate());
    cout << "Advance owned source but will LOSE battle: " << printBoolValue(a4->validate()) << "\n";

    cout << "...Issueing Deploys to Player 1 ...\n";
    p1->issueOrder(a1);
    p1->issueOrder(a2);
    p1->issueOrder(a3);
    p1->issueOrder(a4);
    p1->issueOrder(a5);

    cout << "...Executing all order for player 1 ...\n";
    p1->getOrdersList()->executeAll();

    cout << "...Printing player hand to confirm has received a card ...\n";
    cout<< p1->getHand();

    cout<<"...Printing scotland to show has now owner anymore...\n";
    cout << t2scotland;

    cout <<"...Deleteing pointers..\n";
    cout << "...Deleting Player 1 OrdersList...\n\n";
    p1->getOrdersList()->deleteOrdersList();

    cout << "...Deleting Player 1 Territories...\n\n";
    p1->eraseTerritory(t2denmark);
    p1->eraseTerritory(t2sweden);
    



    cout << "\n\n---------> Test 3: Bomb <---------\n\n\n";

    cout << "..Player 1 ownes of denmark and sothern sweden...\n\n";
    Territory* t3denmark = map1->getTerritory("Denmark");
    Territory* t3sweden = map1->getTerritory("Southern Sweden");
    p1->addTerritory(t3denmark);
    p1->addTerritory(t3sweden);

    cout << "...Denmark is adjacent too the following...\n\n";
    for (auto t : t3denmark->getAdjacencyList()) { cout << t->getName() << " | "; }
    cout << "\n\n";

    cout << "...Southen sweden is adjacent too the following...\n\n";
    for (auto t : t3sweden->getAdjacencyList()) { cout << t->getName() << " | "; }
    cout << "\n\n";

    cout << "...Create territory adjecent to player to bomb norway with army 15...\n\n";
    Territory* t3norway = map1->getTerritory("Norway");
    t3norway->setOwnerId(2);
    t3norway->setArmyCount(15);

    cout << "...Create territory NO owner...\n\n";
    Territory* t3russia = map1->getTerritory("Northern Russia");

    cout << "...Create territory NOT adjecent...\n\n";
    Territory* t3latvia = map1->getTerritory("Latvia");
    t3latvia->setOwnerId(2);

    cout << "...Create Bomb orders ...\n";
    cout << "...Creating GOOD Bomb, player will half Norway ...\n";
    Bomb* b1 = new Bomb(p1, t3norway);
    cout << "...Creating BAD Bomb, territory has no ownwer ...\n";
    Bomb* b2 = new Bomb(p1, t3russia);
    cout << "...Creating BAD Bomb, territory is not adjacent ...\n";
    Bomb* b3 = new Bomb(p1, t3latvia);
    cout << "...Creating BAD Bomb, player owns territory ...\n";
    Bomb* b4 = new Bomb(p1, t3sweden);

    cout << "\n\n...Testing if Bombs are Valid() ...\n";
    cout << "Bomb adjacent Norway, player does not own: " << printBoolValue(b1->validate());
    cout << "Bomb trying territory no owner: " << printBoolValue(b2->validate());
    cout << "Bomb NOT adjacent territory: " << printBoolValue(b3->validate());
    cout << "Bomb territory player owns: " << printBoolValue(b4->validate()) << "\n";

    cout << "...Issueing Bombs to Player 1 ...\n";
    p1->issueOrder(b1);
    p1->issueOrder(b2);
    p1->issueOrder(b3);
    p1->issueOrder(b4);

    cout << "...Executing all order for player 1 ...\n";
    p1->getOrdersList()->executeAll();

    cout << "...Deleting Player 1 OrdersList...\n\n";
    p1->getOrdersList()->deleteOrdersList();

    cout << "...Deleting Player 1 Territories...\n\n";
    p1->eraseTerritory(t3denmark);
    p1->eraseTerritory(t3sweden);




    cout << "\n\n---------> Test 4: Blockade <---------\n\n\n";

    cout << "..Player 1 ownes of denmark and has Army 20 ...\n\n";
    Territory* t4denmark = map1->getTerritory("Denmark");
    p1->addTerritory(t4denmark);
    t4denmark->setArmyCount(20);

    cout << "...Create Sweden player 1 does NOT own...\n\n";
    Territory* t4sweden = map1->getTerritory("Southern Sweden");

    cout << "...Create Neutral player #999...\n\n";
    Player* pNeutral = new Player(t, h, pOL, 999, pState);

    cout << "...Create Blockade orders ...\n";
    cout << "...Creating GOOD Blockade, player will double Denmark and assign to NEUTRAL player ...\n";
    Blockade *bl1 = new Blockade(p1, pNeutral, t4denmark);
    cout << "...Creating BAD Blockade, player does not own Territory...\n";
    Blockade *bl2 = new Blockade(p1, pNeutral, t4sweden);

    cout << "\n\n...Testing if Blockade are Valid() ...\n";
    cout << "Blockade player owns Territory: " << printBoolValue(bl1->validate());
    cout << "Blockade player does not own Territory: " << printBoolValue(bl2->validate())<<"\n";

    cout << "...Issueing Blockade to Player 1 ...\n";
    p1->issueOrder(bl1);
    p1->issueOrder(bl2);

    cout << "...Executing all order for player 1 ...\n";
    p1->getOrdersList()->executeAll();

    cout << "...Printing New Neutral Blockade Territory ...\n";
    cout << t4denmark;

    cout << "...Deleting Player 1 OrdersList...\n\n";
    p1->getOrdersList()->deleteOrdersList();

    cout << "...Deleting Player 1 Territories...\n\n";
    p1->eraseTerritory(t4denmark);
    p1->eraseTerritory(t4sweden);




    cout << "\n\n---------> Test 5: Airlift <---------\n\n\n";

    cout << "..Player 1 ownes of denmark and sweden ...\n\n";
    Territory* t5denmark = map1->getTerritory("Denmark");
    Territory* t5sweden = map1->getTerritory("Southern Sweden");
    p1->addTerritory(t5denmark);
    p1->addTerritory(t5sweden);

    cout << "..Adding 10 army to Denmark  and  ...\n\n";
    t5denmark->addToArmyCount(10);
    t5sweden->addToArmyCount(20);

    cout << "..Creating territory player does NOT own ...\n\n";
    Territory* t5scotland = map1->getTerritory("Scotland");

    cout << "...Create Airlift orders ...\n";
    cout << "...Creating GOOD Airlift, player will move Army Denmark to sweden...\n";
    Airlift* air1 = new Airlift(p1, t5denmark, t5sweden, 5);
    cout << "...Creating Bad Airlift, player does not own Source...\n";
    Airlift* air2 = new Airlift(p1, t5scotland, t5sweden, 5);
    cout << "...Creating Bad Airlift, player does not own Source...\n";
    Airlift* air3 = new Airlift(p1, t5denmark, t5scotland, 5);
    cout << "...Creating Bad Airlift, player is asking to move more army unites then source owns...\n";
    Airlift* air4 = new Airlift(p1, t5denmark, t5sweden, 30);

    cout << "\n\n...Testing if Airlift are Valid() ...\n";
    cout << "Airlift player owns source and target: " << printBoolValue(air1->validate());
    cout << "Airlift player does not own Source: " << printBoolValue(air2->validate());
    cout << "Airlift player does not own Target: " << printBoolValue(air3->validate());
    cout << "Airlift source does NOT have enough army units " << printBoolValue(air4->validate())<<"\n";


    cout << "...Issueing Airlift to Player 1 ...\n";
    p1->issueOrder(air1);
    p1->issueOrder(air2);
    p1->issueOrder(air3);
    p1->issueOrder(air4);

    cout << "...Executing all orders for player 1 ...\n";
    p1->getOrdersList()->executeAll();

    cout << "...Deleting Player 1 OrdersList...\n\n";
    p1->getOrdersList()->deleteOrdersList();

    cout << "...Deleting Player 1 Territories...\n\n";
    p1->eraseTerritory(t5denmark);
    p1->eraseTerritory(t5sweden);


// TODO FIX BUG
/*
    cout << "\n\n---------> Test 6: Negotiate <---------\n\n\n";
    
    cout << "..Creating player 2...\n";
    vector<Territory*> t2;
    Hand* h2 = new Hand();
    OrdersList* pOL2 = new OrdersList();
    State* pState2 = new State("executeorders");
    Player* p2 = new Player(t2, h2, pOL2, 2, pState2); // 1 is id
    cout << "Created player 2.\n\n";

    // denmark adj Southern sweden, west germany
    // Sothern sweden adj denmark, poland;

    cout << "..Creating Territories Denamrk, Sweden, Germany, and Poland...\n\n";
    Territory* t6denmark = map1->getTerritory("Denmark");
    Territory* t6sweden = map1->getTerritory("Southern Sweden");
    Territory* t6germany = map1->getTerritory("West Germany");
    Territory* t6poland = map1->getTerritory("Poland");

    cout <<"...Assigning Player 1 to Denmark, Germany, and Player 2 to Sweden, Poland...\n\n";
    p1->addTerritory(t6denmark);
    p1->addTerritory(t6germany);
    p2->addTerritory(t6sweden);
    p2->addTerritory(t6poland);

    cout << "...Assigning reinforcemants and army forces...\n\n";
    p1->setReinforcement(50);
    p2->setReinforcement(50);
    t6denmark->setArmyCount(50);
    t6sweden->setArmyCount(50);

    cout << "...Create Negotiate Orders...\n";
    cout << "...Creating GOOD Negotiate, player 1 and player 2 Advanves aginst eachother will be deleted...\n";
    Negotiate* n1 = new Negotiate(p1, p2);
    cout << "...Creating BAD Negotiate, player 1 and player 2 are the same player\n";
    Negotiate* n2 = new Negotiate(p1, p1);

    cout << "\n\n...Testing if Negotiates are Valid() ...\n";
    cout << "Negotiate different player source and target: " << printBoolValue(n1->validate());
    cout << "Negotiate same player source and target: " << printBoolValue(n2->validate()) <<"\n";

    cout << "...Create Deploy Orders for filler to not be deleted...\n";
    cout <<"...Creating 2 deploys player 1 to germany ...\n";
    Deploy* deploy1 = new Deploy(p1, t6germany, 5);
    Deploy* deploy2 = new Deploy(p1, t6germany, 5);
    cout << "...Creating 2 deploys player 2 to poland ...\n\n";
    Deploy* deploy3 = new Deploy(p2, t6poland, 5);
    Deploy* deploy4 = new Deploy(p2, t6poland, 5);
  
    cout << "...Create Advance Orders attacking own another to be deleted...\n";
    cout << "...Creating Advance to be deleted\n\n";
    Advance* advance1 = new Advance(p1,t6denmark, t6sweden, 5);
    Advance* advance2 = new Advance(p1, t6denmark, t6sweden, 5);
    Advance* advance3 = new Advance(p2, t6sweden, t6denmark, 5);
    Advance* advance4 = new Advance(p2, t6sweden, t6denmark, 5);

    cout << "...Issue Orders to player 1 and player 2...\n\n";
    p1->issueOrder(n1); // good
    p1->issueOrder(n2); // bad
    p1->issueOrder(deploy1);
    p1->issueOrder(deploy2);
    p1->issueOrder(advance1);
    p1->issueOrder(advance2);

    p2->issueOrder(deploy3);
    p2->issueOrder(deploy4);
    p2->issueOrder(advance3);
    p2->issueOrder(advance4);

    cout << "...Printing player 1 and player 2 OrdersList...\n";
    cout << "...Player 1...\n";
    cout << p1->getOrdersList();
    cout << "...Player 2...\n";
    cout << p2->getOrdersList();

    cout << "...Executing all orders for player 1 ...\n";
    cout << "...Will see Advance orders are NOT executed because deleted ...\n";
    p1->getOrdersList()->executeAll();

    cout << "...Showing Advance Orders attaking each player have been deleted!...\n";
    cout << "...Player 1...\n";
    cout << p1->getOrdersList();
    cout << "...Player 2...\n";
    cout << p2->getOrdersList();

    cout << "...Deleting Player 1 OrdersList...\n\n";
    p1->getOrdersList()->deleteOrdersList();

    cout << "...Deleting Player 2 OrdersList...\n\n";
    p2->getOrdersList()->deleteOrdersList();
    
    cout << "...Deleting Player 1 Territories...\n\n";
    p1->eraseTerritory(t6denmark);
    p1->eraseTerritory(t6germany);

    cout << "...Deleting Player 2 Territories...\n\n";
    p2->eraseTerritory(t6sweden);
    p2->eraseTerritory(t6poland);


*/

    cout << "\n\n---------> Deleting Pointers <---------\n\n\n";

    cout<<"...Deleting player 1...\n\n";
    delete p1;
    p1 = NULL;
    cout << "...Deleting map 1...\n\n";
    delete map1;
    map1 = NULL;

    // cout << "...Deleting Player 2...\n\n";
    // delete p2;
    // p2 = NULL;

}