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

// Functions de la classe
void Tree::generateRandomTree(){
    // Préparation pour l'appel à generateRandomTreeRecurse
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
        string newInfo = "";
        switch (random){
            // Une chance sur 4 pour etre dans chacun des cas.
            case 0:
                // Création des sous arbres avec comme info greaterInfo++
                greaterInfo++;
                newInfo = intToString(greaterInfo);
                subTreeL = new Tree(newInfo);
                greaterInfo++;
                newInfo = intToString(greaterInfo);
                subTreeR = new Tree(newInfo);

                // Appel récursif sur les sous arbres crées précédement
                subTreeL->generateRandomTreeRecurse(deep + 1);
                subTreeR->generateRandomTreeRecurse(deep + 1);
                break;

            case 1:
                // Création des sous arbres avec comme info greaterInfo++
                greaterInfo++;
                newInfo = intToString(greaterInfo);
                subTreeL = new Tree(newInfo);
                subTreeR = NULL;

                // Appel récursif sur les sous arbres crées précédement
                subTreeL->generateRandomTreeRecurse(deep + 1);
                break;

            case 2:
                // Création des sous arbres avec comme info greaterInfo++
                greaterInfo++;
                newInfo = intToString(greaterInfo);
                subTreeR = new Tree(newInfo);
                subTreeL = NULL;

                // Appel récursif sur les sous arbres crées précédement
                subTreeR->generateRandomTreeRecurse(deep + 1);
                break;
        }
    }
}
void Tree::delation(bool left){
    // Supprime un noeud et tous ces sous noeuds de l'arbre
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
    // Utilisation des flux pour transformer un int en string
    ostringstream oss;
    oss << value;
    return oss.str();
    return "";
}
int Tree::stringToInt(string value){
    // Utilisation des flux pour transformer un string en int
    if(!isdigit(value[value.size()-1]))
        value = value.substr(0, value.size()-1);
    istringstream iss(value);
    int number = 0;
    iss >> number;
    return number;
    return 5;
}

// Constructeurs
Tree::Tree(){
    // Constructeur si aucune info n'es spécifiée
    subTreeL = NULL;
    subTreeR = NULL;
    greaterInfo++;
    info = intToString(greaterInfo);

}
Tree::Tree(string newInfo, Tree *newSubTreeL, Tree *newSubTreeR){
    // Constructeur si on spécifie au moins l'info
    info = newInfo;
    subTreeL = newSubTreeL;
    subTreeR = newSubTreeR;
    int max = stringToInt(newInfo);
    if(max>greaterInfo)
        greaterInfo = max;
}
Tree::Tree(Tree const& tree){
    // Constructeur de copy
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
    // Regarde si la structure des deux arbre est identique.
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
