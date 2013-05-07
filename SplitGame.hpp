#ifndef DEF_SPLITGAME
#define DEF_SPLITGAME

#include <iostream>
#include <string>
#include "Tree.hpp"

class SplitGame
{
public:
    // Constructeur
    SplitGame(Tree &newStartTree, Tree const &newEndTree, int newMaxTry);

    // Game
    bool isIdentic();
    void trig();

private:
    int maxTry;
    Tree *startTree;
    const Tree *endTree;
    
    // Functions appelé par trig et permettant de jouer (modifie l'arbre).
    static int trigRecurse(Tree *tree);
    static void delation(Tree *tree, bool left);
    static void extend(Tree *tree, bool left);
    static void split(Tree *tree, bool left);

};

#endif
