#include <iostream>
#include "Renderer.h"
#include "Controller.h"
#include "Game.h"

using namespace std;

int main(int argv, char** argc) {

    constexpr std::size_t kFramesPerSecond{60};
    constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
    constexpr std::size_t kScreenWidth{640};
    constexpr std::size_t kScreenHeight{640};
    constexpr std::size_t kGridWidth{32};
    constexpr std::size_t kGridHeight{32};

    Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
    Controller controller;
    Game game(kGridWidth, kGridHeight);
    game.Run(controller, renderer, kMsPerFrame);
    std::cout << "Game has terminated successfully!\n";
    std::cout << "Score: " << game.GetLevel() << "\n";
    std::cout << "Size: " << game.GetSize() << "\n";
    std::cout << "Steps: " << game.GetEjecuciones() << endl;
    cout << "Ejecucion finalizada. " << endl;
    return 0;
}