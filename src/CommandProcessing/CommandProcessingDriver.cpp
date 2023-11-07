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
        cout << "Reading Commands from " << filename << "\n";
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

    if(isConsole) {
        cout << "\n\n---------> Test 1:Check the validity of the commands if the app is run by console <---------\n\n";
        for (int i = 0; i < testStates; i++) {
            cout << "\nFor console purposes the state right now is at: " + states[i]->getStateName() << "\n";
            Command* c = processor->getCommand();
            bool isValid = processor->validate(c, states[i]);
            cout << "\n................." << (isValid ? "Valid command" : "Invalid command") << ".................\n";
        }
    } else {
        cout << "\n\n---------> Test 1:Check the validity of the commands if the app is run by saved file <---------\n\n";
        for (int i = 0; i < testStates; i++) {
            cout << "\nFor the file adapter the state right now is at: " + states[i]->getStateName() << "\n";
            Command* c = processor->getCommand();
            bool isValid = processor->validate(c, states[i]);
            cout << "\n................." << (isValid ? "Valid command" : "Invalid command") << ".................\n";
        }
    }

    cout << "\n\n---------> Test 2: Test Game transitions <---------\n\n";
    // delete the old processor to be able to initialize the new processor and open the file to complete the second text
    delete processor;
    processor = new FileCommandProcessorAdapter("game.txt");
    cout << "Game should transition from start to maploaded";
    // returns "loadmap file1"
    Command* c = processor->getCommand();
    

        // string commandName = c->getName();
        // string currentStateName = currentState->getStateName();
        // regex mapRegex("^loadmap [A-Za-z0-9/.]+$");
        // regex playerRegex("^addplayer [A-Za-z0-9]+$");
        // // map regex checks if the loadmap command is written properly and if there is a file name afterwards 
        // // NOTE: it doesnt check for the syntax of the file name, the file wont be able to open if its an invalid path
        // if (regex_match(commandName, mapRegex)) {
        //     if (currentStateName.compare("start") == 0 ||
        //         currentStateName.compare("maploaded") == 0) {
        //         // return true;
        //     }
        // }
        // else if (commandName == "validatemap") {
        //     if (currentStateName.compare("maploaded") == 0) {
        //         //create and return a Map
                
        //     }
        // }
        // else if (regex_match(commandName, playerRegex)) {
        //     if (currentStateName.compare("mapvalidated") == 0 ||
        //         currentStateName.compare("playersadded") == 0) {
        //         // return true;
        //     }
        // }
        // else if (commandName == "gamestart") {
        //     if (currentStateName.compare("playersadded") == 0) {
        //         // return true;
        //     }
        // }
        // else if (commandName == "replay" || commandName == "quit") {
        //     if (currentStateName.compare("win") == 0) {
        //         // return true;
        //     }
        // }



// todo: the actual game transition

}