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

    bool isIdentic();
    void trig();

    // Destructeur
    ~SplitGame();

    static bool trigRecurse(Tree *tree);
private:
    int maxTry;
    Tree *startTree;
    const Tree *endTree;

};

#endif
