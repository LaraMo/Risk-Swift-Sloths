#pragma once
#include <string>
#include <vector>
#include <time.h>
#include <iostream>
#include <fstream>

#include "../Map/Map.h"
#include "../Player/Player.h"
#include "../OrdersList/Orders.h"
#include "../CardsDeck/Cards.h"
#include "../GameEngine/GameEngine.h"

using namespace std;

/************************************************************ CommandProcessor **************************************************************/
class CommandProcessor{
    public:
    /**
     * Default Constructor
     */
    CommandProcessor();
    /**
     * Destructor
     */
    ~CommandProcessor();
    /**
     * Assignment Operator
     */
        CommandProcessor& operator=(const CommandProcessor& other);
    /**
     * Copy Constructor
     */
        CommandProcessor(const CommandProcessor& other);
    /**
     * overide Stream insertion operator
     */
    friend ostream& operator<<(ostream& out, CommandProcessor* cp);
    /**
     * stores commands internally in a collection of Command objects
     */
    void saveCommand();
    /**
     * public method for other objects such as the GameEngine or the Player
     */
    Command getCommandForOtherObjects();
    /**
     * checks if the command is valid in the current game state
    */
    void validate(Command* cmd, Player* p);

    private:
    vector<Command*> commands;
    /**
     * gets a command from the console as a string
    */
    Command* readCommand();

};
/*************************************************** FileCommandProcessorAdapter ***************************************************/
class FileCommandProcessorAdapter{
    public:
    /**
     * Default Constructor
     */
    FileCommandProcessorAdapter();
    /**
     * Destructor
     */
    ~FileCommandProcessorAdapter();
    /**
     * Assignment Operator
     */
        FileCommandProcessorAdapter& operator=(const FileCommandProcessorAdapter& other);
    /**
     * Copy Constructor
     */
        FileCommandProcessorAdapter(const FileCommandProcessorAdapter& other);
    /**
     * overide Stream insertion operator
     */
    friend ostream& operator<<(ostream& out, FileCommandProcessorAdapter* fcpa);
    /**
     * public method for other objects such as the GameEngine or the Player
     */
    Command getCommandForOtherObjects();
    /**
     * checks if the command is valid in the current game state
    */
    void validate(Command* cmd, Player* p);

    private:
    vector<Command*> commands;
    /**
     * reads commands line by line from an input file and saves the commands internally in a collection of Command objects
    */
    void readsaveCommand();

};
/************************************************************ Command **************************************************************/
class Command{
    public:
    /**
     * Default Constructor
    */
    Command();
    /**S
     * Destructor
     */
    ~Command();
    /**
     * Constructor with with an argument(s)
     */
    Command(string cmd);
    /**
     * Assignment Operator
     */
    Command& operator=(const Command& other);
    /**
     * Copy Constructor
     */
    Command(const Command& other);
    /**
     * overide Stream insertion operator
     */
    friend ostream& operator<<(ostream& out, Command* c);

    string getCommand();
    
    void setEffect(string e);

    private:
    string command;
    string effect;
};
/************************************************************ CommandProcessingDriver **************************************************************/
void testCommandProcessor();