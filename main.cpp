#include "dungeon.hpp"
#include "factory.hpp"
#include "console_observer.hpp"
#include "file_observer.hpp"
#include <iostream>
#include <memory>
#include <fstream>

int main() {
    Dungeon dungeon;
    auto consoleObs = std::make_shared<ConsoleObserver>();
    auto fileObs = std::make_shared<FileObserver>("log.txt");
    std::vector<std::shared_ptr<Observer>> observers = {consoleObs, fileObs};

    std::cout << "=== Dungeon Editor ===" << std::endl << std::endl;

    // Добавляем НПС
    std::cout << "Adding NPCs to the dungeon..." << std::endl;
    dungeon.addNPC(NPCFactory::createNPC("Bear", "Bear1", 100, 100));
    dungeon.addNPC(NPCFactory::createNPC("Heron", "Heron1", 110, 110));
    dungeon.addNPC(NPCFactory::createNPC("Desman", "Desman1", 120, 120));
    dungeon.addNPC(NPCFactory::createNPC("Bear", "Bear2", 130, 130));

    std::cout << "Initial NPCs in the dungeon:" << std::endl;
    dungeon.print();

    // Сохраняем в файл
    std::cout << "\nSaving NPCs to file 'npcs.txt'..." << std::endl;
    dungeon.saveToFile("npcs.txt");

    // Битва
    std::cout << "\n=== Starting Battle ===" << std::endl;
    std::cout << "Battle range: 50 meters" << std::endl;
    std::cout << "Battle log:" << std::endl;
    dungeon.battle(50.0, observers);

    std::cout << "\n=== Battle Results ===" << std::endl;
    std::cout << "Remaining NPCs after battle:" << std::endl;
    dungeon.print();

    std::cout << "\n=== Loading NPCs from file ===" << std::endl;
    Dungeon dungeon2;
    dungeon2.loadFromFile("npcs.txt");
    std::cout << "Loaded NPCs:" << std::endl;
    dungeon2.print();

    std::cout << "\n=== Battle events logged to 'log.txt' ===" << std::endl;
    std::cout << "\nProgram finished successfully!" << std::endl;

    return 0;
}
