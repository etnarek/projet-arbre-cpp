#include "Tree.hpp"

int Tree::maxDeep = 10;
int Tree::greaterInfo = 0;

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
    int max = stringToInt(newLeft->getInfo());
    if(max>greaterInfo)
        greaterInfo = max;
}
void Tree::setSubTreeR(Tree *newRight){
    delete subTreeR;
    subTreeR = newRight;
    int max = stringToInt(newRight->getInfo());
    if(max>greaterInfo)
        greaterInfo = max;
}
void Tree::setInfo(string newInfo){
    info = newInfo;
    int max = stringToInt(newInfo);
    if(max>greaterInfo)
        greaterInfo = max;
}
void Tree::generateRandomTree(){
        srand(time(0));
        if(subTreeR != NULL){
            delete subTreeR;
            subTreeR = NULL;
        }
        if(subTreeL != NULL){
            delete subTreeL;
            subTreeL = NULL;
        }
        generateRandomTreeRecurse(0);
}


void Tree::generateRandomTreeRecurse(int deep){
    if (deep < maxDeep){
        int random = rand() % 4;
        string newInfo;
        if (deep < maxDeep/2 && random ==3)
            random--;
        switch (random){
            case 0:
                greaterInfo++;
                newInfo = intToString(greaterInfo);
                subTreeL = new Tree(newInfo);
                greaterInfo++;
                newInfo = intToString(greaterInfo);
                subTreeR = new Tree(newInfo);
                subTreeL->generateRandomTreeRecurse(deep + 1);
                subTreeR->generateRandomTreeRecurse(deep + 1);
                break;
            case 1:
                greaterInfo++;
                newInfo = intToString(greaterInfo);
                subTreeL = new Tree(newInfo);
                subTreeR = NULL;
                subTreeL->generateRandomTreeRecurse(deep + 1);
                break;
            case 2:
                greaterInfo++;
                newInfo = intToString(greaterInfo);
                subTreeR = new Tree(newInfo);
                subTreeL = NULL;
                subTreeR->generateRandomTreeRecurse(deep + 1);
                break;
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
string Tree::intToString(int value){
    ostringstream oss;
    oss << value;
    return oss.str();
    return "";
}
int Tree::stringToInt(string value){
    if(!isdigit(value[value.size()-1]))
        value = value.substr(0, value.size()-1);
    istringstream iss(value);
    int number;
    iss >> number;
    return number;
    return 5;
}

// Constructeurs
Tree::Tree(){
    subTreeL = NULL;
    subTreeR = NULL;
    greaterInfo++;
    info = intToString(greaterInfo);

}
Tree::Tree(string newInfo, Tree *newSubTreeL, Tree *newSubTreeR){
    info = newInfo;
    subTreeL = newSubTreeL;
    subTreeR = newSubTreeR;
    int max = stringToInt(newInfo);
    if(max>greaterInfo)
        greaterInfo = max;
}
Tree::Tree(Tree const& tree){
    if(subTreeL == NULL){
        delete subTreeL;
        subTreeL = NULL;
    }
    if(subTreeR == NULL){
        delete subTreeR;
        subTreeR = NULL;
    }
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
            equal = (*this->getSubTreeR() == *other.getSubTreeR());
        }
        else{
            equal = false;
        }
    }   
    else{
        if(other.getSubTreeR() == NULL){
            equal = true;
        }
        else{
            equal = false;
        }
    }
    if(equal){
        if(this->getSubTreeL()!=NULL){
            if(other.getSubTreeL()!=NULL){
                equal = (*this->getSubTreeL() == *other.getSubTreeL());
            }
            else{
                equal = false;
            }
        }
        else{
            if(other.getSubTreeL() == NULL){
                equal = true;
            }
            else{
                equal = false;
            }
        }
    }
    return equal;
}

Tree &Tree::operator=(const Tree &tree)
{
    if(subTreeL == NULL)
        delete subTreeL;
    if(subTreeR == NULL)
        delete subTreeR;
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
    return *this;
}
