#include "SplitGame.hpp"

using namespace std;

// Constructeur
SplitGame::SplitGame(Tree &newStartTree, Tree const &newEndTree, int newMaxTry){
    startTree = &newStartTree;
    endTree = &newEndTree;
    maxTry = newMaxTry;
}

// Game
bool SplitGame::isIdentic(){
    return (*startTree == *endTree);
}
void SplitGame::trig(){
    trigRecurse(startTree);
}
int SplitGame::trigRecurse(Tree *tree){
    string info = tree->getInfo();
    char lettre = info[info.size()-1];
    switch (lettre){
        case 'D':
            return 1;
        case 'X':
            return 2;
        case 's':
            return 3;
        default:
            int treeL, treeR = 0;
            if(tree->getSubTreeL() != NULL)
                treeL = trigRecurse(tree->getSubTreeL());
            if(tree->getSubTreeR() != NULL)
                treeR = trigRecurse(tree->getSubTreeR());
            switch(treeL){
                case 1:
                    delation(tree, true);
                    break;
                case 2:
                    extend(tree, true);
                    break;
                case 3:
                    split(tree, true);
                    break;
            }
            switch(treeR){
                case 1:
                    delation(tree, false);
                    break;
                case 2:
                    extend(tree, false);
                    break;
                case 3:
                    split(tree, false);
                    break;
            }
            break;
    }
    return 0;

}
void SplitGame::delation(Tree *tree, bool left){
    tree->delation(left);
}
void SplitGame::extend(Tree *tree, bool left){

}
void SplitGame::split(Tree *tree, bool left){

}