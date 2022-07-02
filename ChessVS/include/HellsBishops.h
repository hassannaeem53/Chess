#ifndef HELLSBISHOPS_H
#define HELLSBISHOPS_H
#include "chessPlayer.h"
#include"ENUM.h"

class HellsBishops : public chessPlayer {
public:
    HellsBishops(Color playerColor = White);
    void decideMove(gameState* state, action* Move, int maxDepth);
};


#endif // AUTOPLAYER_H
#pragma once
