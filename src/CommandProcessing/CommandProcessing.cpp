#include "CommandProcessing.h"

using namespace std;
/************************************************************ Command **************************************************************/

/**
    * Default
    */
Command::Command() {};

/**
  * Param Constructor
  */
Command::Command(string n) {
    name = n;
}
/**
* Copy constrcutor
*/
Command::Command(const Command& c) {
    effect = c.effect;
}
/**
* Destructor
*/
Command::~Command() {};

string Command::getEffect() {
    return effect;
};

string Command::getName() {
    return name;
};

/**
* Save the effect of the command
*/
void Command::saveEffect(string eff) {
    effect = eff;
};

/**
 * Assignement operator
*/
Command& Command::operator=(const Command& other) {
    effect = other.effect;
    name = other.name;
};

/**
 * Override the stream operator for Command
 */
ostream& operator <<(ostream& out, Command* c) {
    cout << "....Effect of the " << c->name << " command: " << c->effect << "....\n";
    return out;
}


/************************************************************ CommandProcessor **************************************************************/

/**
    * Default
    */
CommandProcessor::CommandProcessor() {};
/**
    * Copy constrcutor
    */
CommandProcessor::CommandProcessor(const CommandProcessor& c) {
    for (int i = 0; i < c.commands.size(); i++) {
        commands.push_back(new Command(*(commands.at(i))));
    }

};
/**
* Destructor
*/
CommandProcessor::~CommandProcessor() {
    for (int i = 0; i < commands.size(); i++) {
        Command* command = commands.at(i);
        delete command;
        command = NULL;
    }
};

/**
* Currently get's the command at the front of the list
* todo: ask what getCommand should do, are we supposed to return a specific command?
// todo: ask about the save command bieng inside of read command or not?
*/
Command* CommandProcessor::getCommand() {
    // read command
    string command = readCommand();
    // save command 
    Command* c = new Command(command);
    saveCommand(c);
    return c;
};


CommandProcessor& CommandProcessor::operator=(const CommandProcessor& other) {
    commands = other.commands;
};

/*
* Check if the command is valid in the current game state. If the command is not valid, a corresponding error
* message should be saved in the effect of the command.
*/
bool CommandProcessor::validate(Command* c, State* currentState) {
    string commandName = c->getName();
    string currentStateName = currentState->getStateName();
    if (commandName == "loadmap") {
        if (currentStateName.compare("start") == 0 || currentStateName.compare("maploaded") == 0) {
            return true;
        }
    }
    else if (commandName == "validatemap") {
        if (currentStateName.compare("maploaded") == 0) {
            return true;
        }
    }
    else if (commandName == "addplayer") {
        if (currentStateName.compare("mapvalidated") == 0 || currentStateName.compare("playersadded") == 0) {
            return true;
        }
    }
    else if (commandName == "gamestart") {
        if (currentStateName.compare("playersadded") == 0) {
            return true;
        }
    }
    else if (commandName == "replay" || commandName == "quit") {
        if (currentStateName.compare("win") == 0) {
            return true;
        }
    }

    c->saveEffect("Invalid " + commandName + " command. Game is in invalid state: " + currentStateName);
    return false;
};

/**
 * Save into the private collection of commands
*/
void CommandProcessor::saveCommand(Command* c) {
    commands.push_back(c);
}

/**
   * Stores a collection oF Command ojects
   * will read commands from the command line
  */
string CommandProcessor::readCommand() {
    // Asking for input
    cout << "Please enter a command!\n";
    string userInput;
    cin >> userInput;
    return userInput;
};


/**
* Override the stream operator for CommandProcessor
*/
ostream& operator <<(ostream& out, CommandProcessor* c) {
    return out;
}

/************************************************************ FileCommandProcessorAdapter   **************************************************************/

/**
* Default
*/
FileCommandProcessorAdapter::FileCommandProcessorAdapter() {};
/**
* Constructor with Params
*/
FileCommandProcessorAdapter::FileCommandProcessorAdapter(string fileName) {};
/**
* Copy constrcutor
*/
FileCommandProcessorAdapter::FileCommandProcessorAdapter(const FileCommandProcessorAdapter& a) {};
/**
* Destructor
*/
FileCommandProcessorAdapter::~FileCommandProcessorAdapter() {};

FileCommandProcessorAdapter& FileCommandProcessorAdapter::operator=(const FileCommandProcessorAdapter& other) {

};

/**
* Override the stream operator for CommandProcessor
*/
ostream& operator <<(ostream& out, FileCommandProcessorAdapter* c) {
    return out;
};

/**
 *   Will read commands from the text file
 */
string FileCommandProcessorAdapter::readCommand() {};

/************************************************************ FileCommandProcessorAdapter   **************************************************************/
void testCommandProcessor(bool isConsole, string fileName);