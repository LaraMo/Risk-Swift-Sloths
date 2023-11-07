#include "CommandProcessing.h"

void testCommandProcessor(bool isConsole, string filename = "") {
    CommandProcessor* processor;
    if (isConsole) {
        processor = new CommandProcessor();
    }
    else {
        // call the adapter
        if (filename.empty()) {
            cout << "No file name provided to process commands from";
            return;
        }
        processor = new FileCommandProcessorAdapter(filename);
    }

    const int testStates = 7;
    State* states[testStates] = {
    new State("start"),
    new State("maploaded"),  // make sure to load invalid map
    new State("maploaded"),
    new State("mapvalidated"),
    new State("playersadded"),
    new State("playersadded"),
    new State("win"),
    };

    cout << "\n\n---------> Test 1:Check the validity of the commands if the app is run by console <---------\n\n";
    for (int i = 0; i < testStates; i++) {
        cout << "\nFor console purposes the state right now is at: " + states[i]->getStateName() << "\n";
        Command* c = processor->getCommand();
        bool isValid = processor->validate(c, states[i]);
        cout << "\n................." << (isValid ? "Valid command" : "Invalid command") << ".................\n";
    }


// todo: read from the adapter

// the actual game transition

}