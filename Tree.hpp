#ifndef DEF_TREE
#define DEF_TREE

#include <string>
#include <iostream>
#include <ctime> 
#include <cstdlib>
#include <sstream>

class Tree
{
public:
    // Constructeurs
    Tree();
    Tree(std::string newInfo, Tree *newSubTreeL = NULL, Tree *newSubTreeR = NULL);
    Tree(Tree const& tree);

    // Getteurs
    Tree * getSubTreeL() const;
    Tree * getSubTreeR() const;
    std::string getInfo();
    // Setteurs
    void setSubTreeL(Tree *newLeft);
    void setSubTreeR(Tree *newRight);
    void setInfo(std::string newInfo);

    void generateRandomTreeRecurse(int deep);
    void generateRandomTree();
    void delation(bool left);

    bool operator==(Tree const& other);
    Tree &operator=(const Tree &);

    // destructeur
    ~Tree();

    static int maxDeep;

private:
    Tree *subTreeL;
    Tree *subTreeR;
    std::string info;
    static int greaterInfo;

    static std::string intToString(int value);
    static int stringToInt(std::string value);
};

#endif
