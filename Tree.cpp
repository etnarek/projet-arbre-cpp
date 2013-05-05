// #include <iostream>
// #include <string>
#include "Tree.hpp"

using namespace std;

// Getteurs
Tree Tree::getSubTreeL(){
    return *subTreeL;
}

Tree Tree::getSubTreeR(){
    return *subTreeR;
}
string Tree::getInfo(){
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
void Tree::generateRandomTree(){

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
Tree::Tree(string newInfo, Tree &newSubTreeL){
    info = info;
    subTreeL = &newSubTreeL;
    subTreeR = NULL;
}
Tree::Tree(string newInfo, Tree &newSubTreeL, Tree &snewSbTreeR){
    info = info;
    subTreeL = &newSubTreeL;
    subTreeR = &snewSbTreeR;
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