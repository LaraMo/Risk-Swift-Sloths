#include "GameEngine.h"

void testGameStates() {

    cout << "\n************************************\nTesting Game Driver!!! \n************************************\n\n";

    cout << "\n\n---------> Test 1: Checking if states and transitions are initialized properly <---------\n\n\n";

    vector<State*> myStates = initializeGameStates();
    vector<Transition*> myTransitions = initializeGameTransitions();
    cout << "...Getting start state...\n";
    cout << myStates[0]->getStateName() << "\n";
    cout << "state has been printed.\n\n";

    cout << "...Getting commands associated with states...\n";
    for (int i = 0; i < myTransitions.size(); i++) {
        cout << myTransitions[i];
        //cout << myTransitions[i]->getCommand() << " leads to " << myTransitions[i]->getNextState() << ".\n";
    }
    cout << "commands have been printed.\n\n";

    cout << "\n\n---------> Test 2: string command comparsion <---------\n\n\n";

    cout << "...Testing command comparision...\n";
    string testLoadMapCommand = "loadmap";
    for (int i = 0; i < myTransitions.size(); i++) {
        if (testLoadMapCommand.compare(myTransitions[i]->getCommand()) == 0) {
            cout << "testLoadMapCommand equals " << myTransitions[i]->getCommand() << " command\n";
        }
    }

    cout << "...Testing Dummy Command...\n";
    string dummyCommand = "patato";
    bool invalid = false;
    for (int i = 0; i < myTransitions.size(); i++) {
        if (dummyCommand.compare(myTransitions[i]->getCommand()) != 0) {
            invalid = true;
        }
        if (invalid && i == myTransitions.size() - 1) {
            cout << "DummyCommand is NOT Valid\n";
        }
    }

    cout << "\n\n---------> Test 3: Assign CurrentState to newState <---------\n\n\n";

    cout << "...Creating currentState as start ...\n";
    State* currentState = myStates[0];
    cout << "currentState created.\n\n";

    cout << "...Printing Contents of current State...\n";
    cout << "Current state is : " << currentState->getStateName() << "\n\n";

    cout << "...assigning currentState using t1 nextState :maploaded ...\n";
    currentState = myTransitions[0]->getNextState();
    cout << "Current state is : " << currentState->getStateName() << "\n\n";

    cout << "\n\n---------> Test 3: Testing User Input <---------\n\n\n";

    cout << "...checking user input commands against game catalogue to allow or deny switch of states...\n";
    cout << "...creating start state...\n";
    State* cState = myStates[0];
    cout << "start state created\n";
    cout << "...Taking user input...\n";

    bool transComplete;
    string userCommand = "";
    while (userCommand.compare("end") != 0) {
        cout << "Enter one of the follwing commands:\n"
            "----------------------------\n"
            " loadmap\n validatemap\n addplayer\n gamestart\n issueorder\n "
            "endissueorders\n execorder\n endexecorders\n replay\n quit - to exit!\n"
            "----------------------------\n";
        cin >> userCommand;
        cout << "\n";
        transComplete = false;
        for (int i = 0; i < myTransitions.size(); i++) {
            if (userCommand.compare(myTransitions[i]->getCommand()) == 0) { // string command
                cState = myTransitions[i]->getNextState(); // assign oldstate to newState
                userCommand = myTransitions[i]->getCommand();
                transComplete = true;
                break;
            }
        }

        if (transComplete) {
            cout << "Current state is : " << cState->getStateName() << "\n\n";
            if (userCommand.compare("end") == 0)
                cout << "...Exiting testGameStates()...\n\n";
        }
        else {
            cout << "The command entered: " << userCommand << " is invalid. Try Again.\n\n";
        }
    }

    cout << "...Deleting State pointers and setting to null...\n";
    for (int i = 0; i < myStates.size(); i++) {
        delete myStates[i];
        myStates[i] = NULL;
    }
    cout << "Deleted State pointers and set to null\n\n";

    cout << "...Deleting Transition Pointers...\n";
    for (int i = 0; i < myTransitions.size(); i++) {
        delete myTransitions[i];
        myTransitions[i] = NULL;
    }
    cout << "Deleted Transition pointers and set to null\n\n";

}