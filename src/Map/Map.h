#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <map>

using namespace std;

/************************************************************ Continent ************************************************************/

class Continent {
private:
    int id;
    string name;

public:

    /**
    * Default Constructor
    */
    Continent();

    /**
    * Param Constructor
    */
    Continent(string, int);

    string getName() const;

    int getId() const;
};

/************************************************************ Territory ************************************************************/


class Territory {
private:
    int ownerId;
    int armyCount;
    int id;
    int continentId;
    string name;
    vector<Territory*> adjacencyList;
public:
    /**
    * Default constructor
    */
    Territory();

    /**
    * Param constructor
    */
    Territory(string name, int id, int continentId, int armyCount);

    string getName() const;

    int getId() const;

    int getContinentId() const;

    int getArmyCount() const;

    // Getter for adjacencyList
    vector<Territory*> getAdjacencyList();

    /**
    * imagine we have A,B,C which are all objects of territory
    * if we call A.addAdjacentTerritory(B) then:
    * 1. We will keep track of B from A
    * 2. Keep track of A from B
    * hence we keep track of adjecent territories
    */
    void addAdjacentTerritory(Territory*);
};
/************************************************************ Map ************************************************************/

class Map {
private:
    map<int, Territory*> territories;
    map<int, Continent*> continents;

public:
    /**
    * Default Constructor
    */
    Map();

    /**
    * Copy constructor
    */
    Map(const Map&);

    /**
    * Param constructor
    */
    Map(map<int, Continent*> continents, map<int, Territory*> territories);


    /**
    * Deconstructor
    */
    ~Map();

    void addContinent(Continent*);

    void addTerritory(Territory*);

    /**
    * Print the summary of map
    */
    void printMapSummary();

    /**
    * Validate the map structure
    */
    bool validate();
};



/************************************************************ MapDriver ************************************************************/

void testLoadMaps();
void gameLoadMap();
void gameValidateMap();

/************************************************************ MapLoader ************************************************************/


class MapLoader {
public:
    Map* loadMap(string);
    /**
    * Parse the .map file the map is in, by seperating each line with a delimiter 
    * The method will return a vector of words
    * For ex: 123,232,353 will be [123,232,353] so we can manupulate each item in the vector as such v.at(i)
    */
    vector<string> split(string s, string delim);
};