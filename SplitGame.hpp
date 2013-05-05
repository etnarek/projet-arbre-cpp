#ifndef DEF_SPLITGAME
#define DEF_SPLITGAME

#include <iostream>
#include "Tree.hpp"

class SplitGame
{
public:
    // Constructeur
    SplitGame(Tree &startTree, Tree const &endTree, int maxTry);

    bool isIdentic();
    void trig();

    // Destructeur
    ~SplitGame();

private:
    int maxTry;
    Tree *startTree;
    const Tree *endTree;
};

#endif
