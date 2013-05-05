#include "SplitGame.hpp"

using namespace std;

// Constructeur
SplitGame::SplitGame(Tree &newStartTree, Tree const &newEndTree, int newMaxTry){
    startTree = &newStartTree;
    endTree = &newEndTree;
    maxTry = newMaxTry;
}

bool SplitGame::isIdentic(){
    return (*startTree == *endTree);
}
void SplitGame::trig(){
    trigRecurse(startTree);
}
bool SplitGame::trigRecurse(Tree *tree){ ////////////////////////////////////////
    return true;
}
