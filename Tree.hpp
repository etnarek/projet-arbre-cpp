#ifndef DEF_TREE
#define DEF_TREE

#include <string>
#include <iostream>

class Tree
{
public:
    // Constructeurs
    Tree();
    Tree(std::string newInfo);
    Tree(std::string newInfo, Tree *newSubTreeL);
    Tree(std::string newInfo, Tree *newSubTreeL, Tree *newSubTreeR);
    Tree(Tree const& tree);

    // Getteurs
    Tree * getSubTreeL() const;
    Tree * getSubTreeR() const;
    std::string getInfo();
    // Setteurs
    void setSubTreeL(Tree *newLeft);
    void setSubTreeR(Tree *newRight);
    void setInfo(std::string newInfo);

    void generateRandomTree();
    bool operator==(Tree const& other);

    // destructeur
    ~Tree();

private:
    Tree *subTreeL;
    Tree *subTreeR;
    std::string info;
    static int maxDeep;
};

#endif
