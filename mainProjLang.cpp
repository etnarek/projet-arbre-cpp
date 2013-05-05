#include <iostream>
#include "Tree.hpp"
#include "SplitGame.hpp"

using namespace std;

const int nbMaxTry=35;

int main()
{
	Tree initial,C,*ref,*ref2;
	
	initial.generateRandomTree();
	
	Tree final=initial;

	SplitGame Game1(initial,final,nbMaxTry);
	cout<< "Les arbres sont identiques en terme de structure? " << Game1.isIdentic() << endl;
	cout<< "mais pas leur adresses?"<< (&initial!= &final) << endl;
	
	C=final;
	SplitGame Game2(C,final,nbMaxTry);
	
	cout<< "Les structures sont identiques? " << Game2.isIdentic() << endl;
	
	ref=new Tree("3",new Tree("4",new Tree("5S"),new Tree("6",new Tree("1"))),new Tree("2", new Tree("7D", NULL, new Tree("9X")), new Tree("10")));
	ref2=new Tree("6",new Tree("1",new Tree("5"),new Tree("2",new Tree("4"))),new Tree("3", new Tree("7X", NULL, new Tree("9S")), new Tree("8")));
	cout<<"hello"<<endl;
	SplitGame Game3(*ref,*ref2,nbMaxTry);
	Game3.trig(); // "déclenchement" des noeuds speciaux
	cout<< "Les arbres ne sont pas identiques en terme de structure: " << Game3.isIdentic() << endl;
	
	cout<<"Le noeud racine a pour etiquette" << ref->getInfo()<<endl;
	if(ref->getSubTreeL()!=NULL)
		cout<<"Le noeud racine du ss-arbre gauche a pour etiquette" << ref->getSubTreeL()->getInfo()<<endl;
	if(ref->getSubTreeR()!=NULL)
		cout<<"Le noeud racine du ss-arbre droit a pour etiquette" << ref->getSubTreeR()->getInfo()<<endl;
	
	//cout<<"Affichage d'un arbre :"<<endl;
	//Game3.display();

	delete ref;
	delete ref2;
	
	return 0;
}