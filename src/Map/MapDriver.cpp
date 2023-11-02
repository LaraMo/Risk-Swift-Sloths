#include "Map.h"

using namespace std;

void testLoadMaps() {
    cout << "\n" << "*************************************" << "\n"
        << "Test Map\n"
        << "*************************************" << "\n" << "\n";
    MapLoader* loader = new MapLoader();

    cout << "---------> Test 1: Load a valid map <---------\n\n";
    Map* map1 = loader->loadMap("Map/MapFolder/cliff.map");
    map1->printMapSummary();
    map1->validate();

    cout << "\n\n---------> Test 2: Load a valid map <---------\n\n";
    Map* map2 = new Map(*loader->loadMap("Map/MapFolder/solarSystem.map"));
    map2->printMapSummary();
    map2->validate();

    cout << "\n\n---------> Test 3: Load a Conquest map <---------\n\n";
    Map* map3 = new Map(*loader->loadMap("Map/MapFolder/Europe.map"));
    map3->printMapSummary();
    map3->validate();

    cout << "\n\n---------> Test 4: Load an invalid map <---------\n\n";
    Map* map4 = loader->loadMap("Map/MapFolder/cliffInvalid.map");

    cout << "\n\n---------> Test 5: Load a file that doesnt exist <---------\n\n";
    Map* map5 = loader->loadMap("Map/MapFolder/idontexist.map");

    cout << "\n\n---------> Test 6: Validate a valid map <---------\n\n";
    Map* map6 = loader->loadMap("Map/MapFolder/World.map");
    map6->validate();

    cout << "\n\n---------> Test 7: Validate map with invalid territories due to duplicates <---------\n\n";
    Map* map7 = loader->loadMap("Map/MapFolder/cliffError.map");
    map7->validate();

    cout << "\n\n---------> Test 8: Validate map with disconected territories <---------\n\n";
    Map* map8 = loader->loadMap("Map/MapFolder/solarSystemError.map");
    map8->validate();

    cout << "\n\n---------> Test 9: Validate map with disconected continents <---------\n\n";
    Map* map9 = loader->loadMap("Map/MapFolder/solarSystemErrorContinent.map");
    map9->validate();


    // delete all references to map
    delete map1;
    map1 = NULL;

    delete map2;
    map2 = NULL;

    delete map3;
    map3 = NULL;

    delete map4;
    map4 = NULL;

    delete map5;
    map5 = NULL;

    delete map6;
    map6 = NULL;

    delete map7;
    map7 = NULL;

    delete map8;
    map8 = NULL;
    
    delete map9;
    map9 = NULL;
};

void gameLoadMap() {
    MapLoader* loader = new MapLoader();

    cout << "---------> Test 1: Load a valid map <---------\n\n";
    Map* map1 = loader->loadMap("Map/MapFolder/cliff.map");
    map1->printMapSummary();

    delete map1;
    map1 = NULL;
}

void gameValidateMap() {
    MapLoader* loader = new MapLoader();

    cout << "---------> Test 2: Validate a map <---------\n\n";
    Map* map2 = loader->loadMap("Map/MapFolder/cliff.map");
    map2->validate();

    delete map2;
    map2 = NULL;
}