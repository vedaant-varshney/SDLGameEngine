#include <iostream>
#include <stdio.h>
#include <string>
#include "runner/runnergame.h"





int main() {

    std::cout << "Test" << std::endl;
    Runner game = Runner{960, 544};
    game.start();
    game.run();
    // while (true) {};
    return 0;
}
