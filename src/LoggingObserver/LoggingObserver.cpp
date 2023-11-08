#include "LoggingObserver.h"
#include "../OrdersList/Orders.h"
#include "../Player/Player.h"
#include "../CardsDeck/Cards.h"

/************************************************************ Subject ************************************************************/
    /**
     * Attach to view
     */
    void Subject::attach(Observer* observer){
        observers.push_back(observer);
    }

    /**
     * Detach from view
     */
    void Subject::detach(Observer* observer){
        observers.remove(observer);
    }

    /**
     * Notify all observers that a change has been made in the state
     */
    void Subject::notify(ILoggable* loggable){
        // create an iterator
        list<Observer*>::iterator i = observers.begin();
        for(;i != observers.end(); i++){
            (*i)->update(loggable);
        }
    }
/************************************************************ LogObserver ************************************************************/
void LogObserver::update(ILoggable* loggable) {
    string log = loggable->stringToLog();
    cout << log;
    printToFileHelper(log);
}

void LogObserver::printToFileHelper(string log){

    // Create an ofstream object to work with a file
    // create file logger.txt
    ofstream outputFile("gamelog.txt");

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
    // create order to test 
    vector<Territory*> t;
    Territory* t6 = new Territory("Bulgaria", 6, 3, 0);
    State* executeordersState = new State("executeorders");

    Hand* h = new Hand();
    OrdersList* o = new OrdersList;
    t.push_back(t6);
    Player* p = new Player(t, h, o, 1, executeordersState);
    Deploy* deploy = new  Deploy(p, t6, 3);

    deploy->setValid(true);
    // attach modal to view 
    deploy->attach(logger);
    // trigger execution of order to print a notif
    deploy->execute();
}

// TODO after merge:
// LogObserver that writes every game command read by a CommandProcessor object (or a
// FileCommandProcessorAdapter object) into a log file. The game log observer should be notified by the
// CommandProcessor::saveCommand() method that saves the command into the collection of commands, as well
// as the and Command::saveEffect() method that records the effect of the command into the command object.
// This should result in all the current game’s commands and their effects to be logged into a “gamelog.txt” file. 

// Also in the same way, when the GameEngine’s state is changing (e.g. using GameEngine::transition()), a log
// line should be output to the log file stating what is the new game state, using the Observer notification
// mechanism.


// TODO: when merged
// CommandProcessor::saveCommand()
// Command::saveEffect()
// Order::execute() --> DONE, BUT THE EFFECT ISNT READY, SO NEED TO ADD IT WHEN WE MERGE
// OrderList::addOrder()
// GameEngine::transition()

//todo: extend the following classes when merged:
// Order - DONE 
// OrderList
// GameEngine 
// Command
// CommandProcessor
