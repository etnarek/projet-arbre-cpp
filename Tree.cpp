#include "Tree.hpp"

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

void Tree::generateRandomTree(int deep){

    if (deep < maxDeep){
        int random =1; //rand() % 4;
        // cout <<"case"<< random <<endl;
        switch (random){
            case 0:
                subTreeL = new Tree("5");
                cout << "subTreeR"<<subTreeR<<endl;
                subTreeR = new Tree("6");
                cout << "subTreeL"<<subTreeL<<endl;
                subTreeL->generateRandomTree(deep + 1);
                subTreeR->generateRandomTree(deep + 1);
                break;
            case 1:
                subTreeL = new Tree("7");
                subTreeR = NULL;
                cout << "subTreeR"<<subTreeR<<endl;
                cout << "subTreeL"<<subTreeL<<endl;
                subTreeL->generateRandomTree(deep + 1);
                break;
            case 2:
                subTreeR = new Tree("8");
                subTreeL = NULL;
                subTreeR->generateRandomTree(deep + 1);
                break;
        }
    }

    // TODO: lettre toujours plus grand

    // int current = 1;
    // char letter[2];

    // sprintf(letter, "%d", ++current);
    // node.setSubTreeR(new Tree(letter));
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
Tree::Tree(string newInfo, Tree *newSubTreeL, Tree *newSubTreeR){
    info = newInfo;
    subTreeL = newSubTreeL;
    subTreeR = newSubTreeR;
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
