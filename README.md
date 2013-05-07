INFO-F-105 : projet sur les arbres
==================================
Nous devons, pour le cours de programmation créer un jeux (splitgame) pour apprendre à utiliser le c++.
Voici le site du jeux: http://www.cipherprime.com/games/splice/ .

Ce qu'il faut faire:
--------------------
Il faut creer les différentes classes suivantes:
- Tree
- SplitGame

Compilation et lancement:
-------------------------
Pour compiler le programme, vous pouvez utiliser la commande suivant:

    g++ -c -o Tree.o Tree.cpp && g++ -c -o SplitGame.o SplitGame.cpp && g++ -c -o mainProjLang.o mainProjLang.cpp && g++ -o mainProjLang Tree.o SplitGame.o mainProjLang.o

Et pour le lancer:

    ./mainProjLang

Normalement, vous ne devriez pas avoir de fuite de mémoire. (j'ai dis normalement :p)

Ajouts possible:
----------------
- Un makefile
- Un affichage pour l'arbre
- Un function pour le déplacement des noeuds
- ...