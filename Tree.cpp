#include "Tree.hpp"
#include <ctime> 
#include <cstdlib>

int Tree::maxDeep = 10;

using namespace std;

// Getteurs
Tree * Tree::getSubTreeL() const{
    return subTreeL;
}

Tree * Tree::getSubTreeR() const{
    return subTreeR;
}
string Tree::getInfo() const{
    return info;
}

// Setteur
void Tree::setSubTreeL(Tree &newLeft){
    delete subTreeL;
    subTreeL = &newLeft;
}
void Tree::setSubTreeR(Tree &newRight){
    delete subTreeR;
    subTreeR = &newRight;
}
void Tree::setInfo(string newInfo){
    info = newInfo;
}

void Tree::generateRandomTree(){ ////////////////////////////////////////////////////////////////:
    srand(time(0));
    int current = 1;
    info = current;
    int i=0;
    Tree node = *this;
    bool end = false;
    int random = 0;
    // char c = '0'

    while(i<maxDeep && !end){
        random = rand() % 4;
        switch (random){
            case 0:
                node.setSubTreeL(Tree('0' + current));
                node.setSubTreeR(Tree('0' + current));
                if(rand()%2)
                    node = node.getSubTreeL();
                else
                    node = node.getSubTreeR();
                break;
            case 1:
                node.setSubTreeL(Tree('0' + current));
                node = node.getSubTreeL();
            case 2:
                node.subTreeR(Tree('0' + current));
                node = node.getSubTreeR();
            default:
                end = true;
        }
    }
}

// Constructeurs
Tree::Tree(){
    info = "";
    subTreeL = NULL;
    subTreeR = NULL;
}
Tree::Tree(string newInfo){
    info = info;
    subTreeL = NULL;
    subTreeR = NULL;
}
Tree::Tree(string newInfo, Tree *newSubTreeL){
    info = info;
    subTreeL = newSubTreeL;
    subTreeR = NULL;
}
Tree::Tree(string newInfo, Tree *newSubTreeL, Tree *snewSbTreeR){
    info = info;
    subTreeL = newSubTreeL;
    subTreeR = snewSbTreeR;
}
Tree::Tree(Tree const& tree){
    info = tree.getInfo();
    if(tree.getSubTreeL() != NULL){
        subTreeL = new Tree(*tree.getSubTreeL());
    }
    else{
        subTreeL = NULL;
    }
    if(tree.getSubTreeR() != NULL){
        subTreeR = new Tree(*tree.getSubTreeR());
    }
    else{
        subTreeR = NULL;
    }
}

// Destructeur
Tree::~Tree(){
    if(subTreeL != NULL){
        delete subTreeL;
    }
    if(subTreeR != NULL){
        delete subTreeR;
    }
}

// Surcharge d'opérateur
bool Tree::operator==(Tree const& other){
    bool equal = false;
    if(this->getSubTreeR() != NULL){
        if(other.getSubTreeR()!=NULL){
            equal = this->getSubTreeR() == other.getSubTreeR();
        }
            else{
                equal = false;
            }
        }   
    else{
        if(other.getSubTreeR() == NULL){
            equal = true;
        }
    }
    if(equal){
        if(this->getSubTreeL()!=NULL){
            if(other.getSubTreeL()!=NULL){
                equal = this->getSubTreeL() == other.getSubTreeL();
            }
                else{
                    equal = false;
                }
        }
        else{
            if(other.getSubTreeL() == NULL){
                equal = true;
            }
        }
    }
    return equal;
}
