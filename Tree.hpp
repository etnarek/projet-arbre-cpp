#ifndef DEF_TREE
#define DEF_TREE

#include <string>
#include <iostream>

class Tree
{
public:
    // Constructeurs
    Tree();
    Tree(std::string info);
    Tree(std::string info, Tree &subTreeL);
    Tree(std::string info, Tree &subTreeL, Tree &subTreeR);

    // Getteurs
    Tree getSubTreeL();
    Tree getSubTreeR();
    std::string getInfo();
    // Setteurs
    void setSubTreeL(Tree &newLeft);
    void setSubTreeR(Tree &newRight);
    void setInfo(std::string newInfo);
    void generateRandomTree();

    // destructeur
    ~Tree();

private:
    Tree *subTreeL;
    Tree *subTreeR;
    std::string info;
};

#endif
