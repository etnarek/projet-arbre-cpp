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
    Tree *newNode;
    newNode = new Tree();
    Tree *oldNode;
    if(left){
        oldNode = tree->getSubTreeL();
    }
    else{
        oldNode = tree->getSubTreeR();
    }

    if(oldNode->getSubTreeL() != NULL)
        newNode->setSubTreeL(oldNode->getSubTreeL());
    if(oldNode->getSubTreeR() != NULL)
        newNode->setSubTreeR(oldNode->getSubTreeR());
    oldNode->setSubTreeR(NULL);
    oldNode->setSubTreeL(newNode);
    if(left){
        tree->setSubTreeL(newNode);
    }
    else{
        tree->setSubTreeR(newNode);
    }

}
void SplitGame::split(Tree *tree, bool left){
    Tree *oldNode;
    Tree *newNode;
    newNode = new Tree();
    if(left){
        oldNode = tree->getSubTreeL();
    }
    else{
        oldNode = tree->getSubTreeR();
    }
    newNode->setSubTreeL(oldNode);
    newNode->setSubTreeR(new Tree(*oldNode));
    if(left){
        tree->setSubTreeL(newNode);
    }
    else{
        tree->setSubTreeR(newNode);
    }

}