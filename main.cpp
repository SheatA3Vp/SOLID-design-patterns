#include "dungeon.hpp"
#include "factory.hpp"
#include "console_observer.hpp"
#include "file_observer.hpp"
#include <iostream>
#include <memory>

int main() {
    Dungeon dungeon;
    auto consoleObs = std::make_shared<ConsoleObserver>();
    auto fileObs = std::make_shared<FileObserver>("log.txt");
    std::vector<std::shared_ptr<Observer>> observers = {consoleObs, fileObs};

    // Add some NPCs
    dungeon.addNPC(NPCFactory::createNPC("Bear", "Bear1", 100, 100));
    dungeon.addNPC(NPCFactory::createNPC("Heron", "Heron1", 110, 110));
    dungeon.addNPC(NPCFactory::createNPC("Desman", "Desman1", 120, 120));
    dungeon.addNPC(NPCFactory::createNPC("Bear", "Bear2", 130, 130));

    std::cout << "Initial NPCs:" << std::endl;
    dungeon.print();

    // Save to file
    dungeon.saveToFile("npcs.txt");

    // Battle
    std::cout << "\nStarting battle with range 50:" << std::endl;
    dungeon.battle(50.0, observers);

    std::cout << "\nRemaining NPCs:" << std::endl;
    dungeon.print();

    return 0;
}
