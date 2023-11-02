#include "CommandProcessing.h"

/************************************************************ CommandProcessor **************************************************************/
/**
 * Default Constructor
 */
    CommandProcessor::CommandProcessor(){}
/**
 * Destructor
 */
    CommandProcessor::~CommandProcessor(){}
/**
 * Assignment Operator
 */
    CommandProcessor& CommandProcessor::operator=(const CommandProcessor& other){
        this->commands = other.commands;
        return *this;
    }
/**
 * Copy Constructor
 */
    CommandProcessor::CommandProcessor(const CommandProcessor& other){
        this->commands = other.commands;
    }
/**
 * overide Stream insertion operator
 */
    ostream& operator<<(ostream& out, CommandProcessor* cp){
        //haven't decided what to printout so TODO!!!
        return out;
    }
/**
 * gets a command from the console as a string
*/
    Command* CommandProcessor::readCommand(){
        string commandstr;
        cout << "Enter a command:\n";
        cin >> commandstr;
        Command* commandobj = new Command(commandstr);
        return commandobj;
    }
/**
 * stores commands internally in a collection of Command objects
 */
    void CommandProcessor::saveCommand(){
        Command* commandobj = readCommand();
        commands.push_back(commandobj);
    }
/**
 * public method for other objects such as the GameEngine or the Player
 */
    Command CommandProcessor::getCommandForOtherObjects(){
        if (!commands.empty()) {
            //TODO
        }
    }
/**
 * checks if the command is valid in the current game state
 * let's say a player is in state issueorders but then gives a command that belong to executeorders
 * this command should be rejected
 * otherwise we update the state of the player
*/
    void CommandProcessor::validate(Command* cmd, Player* p){
        bool isValid = false;
        vector<Transition*> transitions = initializeGameTransitions();
        for (int i = 0; i < transitions.size(); i++) {
            if (cmd->getCommand().compare(transitions[i]->getCommand()) == 0 
                    && transitions[i]->getCurrentState()->getStateName() == p->getState()->getStateName()) {
                        isValid = true;
                        p->setState(transitions[i]->getNextState());
                        cout << "this command is valid in the current game state.\n";
                        string effect = "Player was moved to "+transitions[i]->getNextState()->getStateName();
                        cmd->setEffect(effect);
            }
            if (isValid && i == transitions.size() - 1) {
                cmd->setEffect("Invalid Command Error");
                cout << "this command is NOT VALID in the current game state.\n";
            }
        }
    }
/*************************************************** FileCommandProcessorAdapter ***************************************************/
/**
 * Default Constructor
 */
    FileCommandProcessorAdapter::FileCommandProcessorAdapter(){}
/**
 * Destructor
 */
    FileCommandProcessorAdapter::~FileCommandProcessorAdapter(){}
/**
 * Assignment Operator
 */
    FileCommandProcessorAdapter& FileCommandProcessorAdapter::operator=(const FileCommandProcessorAdapter& other){
        this->commands = other.commands;
        return *this;
    }
/**
 * Copy Constructor
 */
    FileCommandProcessorAdapter::FileCommandProcessorAdapter(const FileCommandProcessorAdapter& other){
        this->commands = other.commands;
    }
/**
 * overide Stream insertion operator
 */
    ostream& operator<<(ostream& out, FileCommandProcessorAdapter* cp){
        //haven't decided what to printout so TODO!!!
        return out;
    }
    /**
     * reads commands line by line from an input file and saves the commands internally in a collection of Command objects
    */
    void FileCommandProcessorAdapter::readsaveCommand(){
        string commandstr;
        ifstream readCommands("Commands.txt");
        while (getline (readCommands, commandstr)) {
            Command* commandobj = new Command(commandstr);
            commands.push_back(commandobj);
        }
    }
/**
 * public method for other objects such as the GameEngine or the Player
 */
    Command FileCommandProcessorAdapter::getCommandForOtherObjects(){
        if (!commands.empty()) {
            //TODO
        }
    }
/**
 * checks if the command is valid in the current game state
 * let's say a player is in state issueorders but then gives a command that belong to executeorders
 * this command should be rejected
 * otherwise we update the state of the player
*/
    void FileCommandProcessorAdapter::validate(Command* cmd, Player* p){
        bool isValid = false;
        vector<Transition*> transitions = initializeGameTransitions();
        for (int i = 0; i < transitions.size(); i++) {
            if (cmd->getCommand().compare(transitions[i]->getCommand()) == 0 
                    && transitions[i]->getCurrentState()->getStateName() == p->getState()->getStateName()) {
                        isValid = true;
                        p->setState(transitions[i]->getNextState());
                        cout << "this command is valid in the current game state.\n";
                        string effect = "Player was moved to "+transitions[i]->getNextState()->getStateName();
                        cmd->setEffect(effect);
            }
            if (isValid && i == transitions.size() - 1) {
                cmd->setEffect("Invalid Command Error");
                cout << "this command is NOT VALID in the current game state.\n";
            }
        }
    }
/************************************************************ Command **************************************************************/
/**
 * Default Constructor
 */
	Command::Command(){}
/**S
 * Destructor
 */
    Command::~Command(){}
/**
 * Constructor with with an argument(s)
 */
	Command::Command(string cmd){
        this->command = cmd;
    }
/**
 * Assignment Operator
 */
	Command& Command::operator=(const Command& other){
        this->command = other.command;
        this->effect = other.effect;
        return *this;
    }
/**
 * Copy Constructor
 */
    Command::Command(const Command& other){
        this->command = other.command;
        this->effect = other.effect;
    }
/**
 * overide Stream insertion operator
 */
    ostream& operator<<(ostream& out, Command* c){
        cout << "The " << c->command << " currently leads to the effect of : " << c->effect << "\n";
        return out;
    }

    string Command::getCommand(){
        return this->command;
    }
    
    void Command::setEffect(string e){
        this->effect = e;
    }