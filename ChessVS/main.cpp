#include "include\\actionList.h"
#include <iostream>
#include<iomanip>
#include "include\\chess.h"
#include "include\\autoPlayer.h"
#include "include\\humanPlayer.h"
#include "include\\HellsBishops.h"

using namespace std;

int main(){
    chess Game;
    Game.Players[1] = new humanPlayer("Human Player Name", White);
    //Game.Players[0] = new autoPlayer(White);
    Game.Players[0] = new HellsBishops(Black);
    Game.playGame();
    return 0;
}
