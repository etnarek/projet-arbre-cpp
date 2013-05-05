#ifndef DEF_TREE
#define DEF_TREE

#include <string>

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
    Tree getInfo();
    // Setteurs
    void setSubTreeL(Tree &newLeft);
    void setSubTreeR(Tree &newRight);
    void setInfo(std::string newRootVal);
    void generateRandomTree();

    // destructeur
    ~Tree();

private:
    Tree subTreeL*;
    Tree subTreeR*;
    string info;
};

#endif
