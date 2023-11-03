#include "LoggingObserver.h"

#include "../OrdersList/Orders.h"

#include "../Player/Player.h"

#include "../CardsDeck/Cards.h"

/************************************************************ Subject ************************************************************/
/**
 * Attach to view
 */
void Subject::attach(Observer * observer) {
  observers.push_back(observer);
}

/**
 * Detach from view
 */
void Subject::detach(Observer * observer) {
  observers.remove(observer);
}

/**
 * Notify all observers that a change has been made in the state
 */
void Subject::notify(ILoggable * loggable) {
  // create an iterator
  list < Observer * > ::iterator i = observers.begin();
  for (; i != observers.end(); i++) {
    ( * i) -> update(loggable);
  }
}
/************************************************************ LogObserver ************************************************************/
void LogObserver::update(ILoggable * loggable) {
  string log = loggable -> stringToLog();
  cout << log;
  printToFileHelper(log);
}

void LogObserver::printToFileHelper(string log) {

  // Create an ofstream object to work with a file
  ofstream outputFile;
  // Append instead of overwrite
  outputFile.open("gamelog.txt", ios_base::app);

  // Check if the file is successfully opened
  if (outputFile.is_open()) {
    // Write data to the file
    outputFile << log;

    // Close the file when you're done with it
    outputFile.close();
  }
}
/************************************************************ LoggingDriver ************************************************************/

void testLoggingObserver() {
  // create the log observer
  LogObserver* logger = new LogObserver();

  // create test components (territory, hand, state, orderlist)
  vector <Territory*> territoryList;
  vector <Territory*> territoryList2;
  Territory* territory1 = new Territory("UK", 5, 3, 10);
  Territory* territory2 = new Territory("Bulgaria", 6, 3, 6);
  territoryList.push_back(territory2);
  territoryList2.push_back(territory1);

  State* executeordersState = new State("executeorders");

  Hand* h = new Hand();

  OrdersList* o = new OrdersList;

  Player* p = new Player(territoryList, h, o, 1, executeordersState);
  Player* p2 = new Player(territoryList2, h, o, 2, executeordersState);

  // instead of repeating code, I create an array of Order* and attach the loger + execute the orders in a loop
  const int numberOfOrders = 4; // todo: make 6

 // TODO: test the accuracy of the tests + finish bomb + blocade
  Order* orderArray[numberOfOrders] = {
    new Deploy(p, territory2, 3),
    new Advance(p, territory1, territory2, 3), 
    // new Bomb(p, territory1),
    // new Blockade(p, p2, territory1)
    new Airlift(p, territory1, territory2, 2),
    new Negotiate(p, p2)
  };

  /**
   * Set the order to valid by default
   * Attach logger to each order
   * Execute the order - expect the console and the file to be filled with logs
   */
  for (int i = 0; i < numberOfOrders; i++) {
    Order* order = orderArray[i];
    order->setValid(true);
    order->attach(logger);
    order->execute();

  }

  // test add the order to the player's orderlist 
  Deploy* d = new Deploy(p, territory2, 3);
  // attach modal to view 
  o->attach(logger);
  p->issueOrder(d); // should call Order::addOrder and notify the observer

  // avoid dangeling pointers
  for (int i = 0; i < numberOfOrders; i++) {
    Order* order = orderArray[i];
    delete order;
    order = NULL;
  }

  delete territory2;
  territory2 = NULL;

  delete territory1;
  territory1 = NULL;

  delete p; // will delete all items that were passed to players constructor such as territories, hand, orderlist and state
  p = NULL;

  delete logger;
  logger = NULL;

}

// TODO: when merged
// CommandProcessor::saveCommand() - TODO
// Command::saveEffect() - TODO 
// Order::execute() --> DONE, BUT THE EFFECT ISNT READY, SO NEED TO ADD IT WHEN WE MERGE
// OrderList::addOrder() --> DONE
// GameEngine::transition() - TODO

//todo: extend the following classes when merged:
// Order - DONE 
// OrderList -DONE
/// TODO:
// GameEngine 
// Command
// CommandProcessor