#ifndef RUNNER_H
#define RUNNER_H

#include "../engine/game.h"

class Runner: public Game {

private:


public:
    Runner(const int width, const int height): Game{width, height} {};
    ~Runner() {};
    // Game Startup including texture loading
    void start() override;
    // Actual Game Loop
    void run() override;

    // End does not need an override at the moment
    // void end() override;



};

#endif
