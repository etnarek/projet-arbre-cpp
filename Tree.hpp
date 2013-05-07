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

    // Functions spécifiques
    void generateRandomTreeRecurse(int deep);
    void generateRandomTree();
    void delation(bool left);

    // Surcharge d'opérateur
    bool operator==(Tree const& other);
    Tree &operator=(const Tree &);

    // destructeur
    ~Tree();

    static const int maxDeep; // Taille maximum d'un arbre lors de l'appel de generateRandomTree.

private:
    Tree *subTreeL;
    Tree *subTreeR;
    std::string info;

    static int greaterInfo; // sert à stocker le numéro du plus grand noeud (pour creer les nouveaux plus haut).

    // Functions spécifiques
    static std::string intToString(int value);
    static int stringToInt(std::string value);
};

#endif
