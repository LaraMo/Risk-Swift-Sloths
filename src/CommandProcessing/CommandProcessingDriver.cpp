#include "CommandProcessing.h"

void testCommandProcessor (bool isConsole, string filename = "") {
    CommandProcessor* processor;
    if(isConsole) {
        processor = new CommandProcessor();
    } else {
        // call the adapter
        if(filename.empty()){
            cout << "No file name provided to process commands from";
            return;
        }
        processor = new FileCommandProcessorAdapter(filename);        
    }
    cout << "sup bitch";

    //test the rest of the commandProcessor
}