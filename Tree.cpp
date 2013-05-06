#include "Tree.hpp"
#include <ctime> 
#include <cstdlib>
#include <stdio.h>

int Tree::maxDeep = 10;

using namespace std;

// Getteurs
Tree * Tree::getSubTreeL() const{
    return subTreeL;
}

Tree * Tree::getSubTreeR() const{
    return subTreeR;
}
string Tree::getInfo(){
    return info;
}

// Setteur
void Tree::setSubTreeL(Tree *newLeft){
    delete subTreeL;
    subTreeL = newLeft;
}
void Tree::setSubTreeR(Tree *newRight){
    delete subTreeR;
    subTreeR = newRight;
}
void Tree::setInfo(string newInfo){
    info = newInfo;
}

void Tree::generateRandomTree(){ //////////////////////////////////////////////////////////////// problem avec les current non transf en int.
    srand(time(0));
    int current = 1;
    info = current;
    int i=0;
    Tree node = *this;
    bool end = false;
    int random = 0;
    char letter[2];

    while(i<maxDeep && !end){
        random = rand() % 4;
        switch (random){
            case 0:
                sprintf(letter, "%d", ++current);
                node.setSubTreeL(new Tree(letter));
                sprintf(letter, "%d", ++current);
                node.setSubTreeR(new Tree(letter));
                if(rand()%2)
                    node = *node.getSubTreeL();
                else
                    node = *node.getSubTreeR();
                break;
            case 1:
                sprintf(letter, "%d", ++current);
                node.setSubTreeL(new Tree(letter));
                node = *node.getSubTreeL();
            case 2:
                sprintf(letter, "%d", ++current);
                node.setSubTreeR(new Tree(letter));
                node = *node.getSubTreeR();
            default:
                end = true;
        }
    }
}
void Tree::delation(bool left){
    if(left){
        if(subTreeL != NULL){
            delete subTreeL;
            subTreeL = NULL;
        }
    }
    else{
        if(subTreeR != NULL){
            delete subTreeR;
            subTreeR = NULL;
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
    info = newInfo;
    subTreeL = NULL;
    subTreeR = NULL;
}
Tree::Tree(string newInfo, Tree *newSubTreeL){
    info = newInfo;
    subTreeL = newSubTreeL;
    subTreeR = NULL;
}
Tree::Tree(string newInfo, Tree *newSubTreeL, Tree *snewSbTreeR){
    info = newInfo;
    subTreeL = newSubTreeL;
    subTreeR = snewSbTreeR;
}
Tree::Tree(Tree const& tree){
    info = tree.info;
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
