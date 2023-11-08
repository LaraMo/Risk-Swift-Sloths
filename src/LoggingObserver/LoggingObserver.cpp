#include "LoggingObserver.h"

/************************************************************ Subject ************************************************************/
/**
 * Attach to view
 */
void Subject::attach(Observer* observer) {
    observers.push_back(observer);
}

/**
 * Detach from view
 */
void Subject::detach(Observer* observer) {
    observers.remove(observer);
}

/**
 * Notify all observers that a change has been made in the state
 */
void Subject::notify(ILoggable* loggable) {
    // create an iterator
    list <Observer*>::iterator i = observers.begin();
    for (; i != observers.end(); i++) {
        (*i)->update(loggable);
    }
}
/************************************************************ LogObserver ************************************************************/
void LogObserver::update(ILoggable* loggable) {
    string log = loggable->stringToLog();
    cout << log;
    printToFileHelper(log);
}
/**
 * Helper function that prints to file
 */
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
