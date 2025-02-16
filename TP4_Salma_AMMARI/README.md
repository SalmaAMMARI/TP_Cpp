
README - TP4

Prérequis:
Un compilateur C++ (par exemple, GCC, Clang, ou Visual Studio).
C++11 ou une version plus récente.
Instructions pour exécuter les exercices
1. Cloner ou télécharger le dépôt
Téléchargez ou clonez ce dépôt sur votre machine :

bash
Copier
Modifier
git clone <URL du dépôt>
2. Sélectionner un exercice
Le fichier principal contient une directive préprocesseur EXO que vous pouvez modifier pour sélectionner l'exercice que vous souhaitez exécuter. Par défaut, l'exercice sélectionné est l'Exercice 1.

Exemple pour sélectionner un exercice
Dans le fichier main.cpp, cherchez cette ligne :

cpp
Copier
Modifier
#ifndef EXO
#define EXO 1  // Changez ce nombre pour choisir un autre exercice
#endif
Modifiez la valeur de EXO en fonction de l'exercice que vous voulez tester :

EXO = 1 pour l'exercice 1
EXO = 2 pour l'exercice 2
EXO = 3 pour l'exercice 3
Etc.
3. Compiler le programme
Une fois l'exercice choisi, compilez le programme avec votre compilateur. Par exemple, avec g++ :

bash
Copier
Modifier
g++ -o programme main.cpp
4. Exécuter le programme
Après la compilation, vous pouvez exécuter le programme :

bash
Copier
Modifier
./programme
5. Interaction avec le programme
Chaque exercice affiche des résultats à la console ou attend des entrées de l'utilisateur (selon l'exercice). Suivez les instructions qui s'affichent pour tester et explorer les exercices.

Structure des exercices
Exercice 1 : Manipulation d'un tableau 1D.
Exercice 2 : Stockage d'une matrice avec des tableaux 2D.
Exercice 3 : Utilisation de std::array.
Exercice 4 : Manipulation de std::vector.
Exercice 5 : Utilisation de std::list (Liste chaînée).
Exercice 6 : Utilisation de std::set pour des éléments uniques.
Exercice 7 : Utilisation de std::unordered_map pour des paires clé-valeur.
Exercice 8 : Comptage de mots avec std::unordered_map.
Exercice 9 : Tri d'un std::vector.
Exercice 10 : Recherche de la séquence consécutive la plus longue dans un std::set.
Exercice 11 : Implémentation d'un cache LRU.
Remarque
Assurez-vous de bien choisir l'exercice voulu avant de compiler le programme, en modifiant la valeur de EXO. Chaque exercice est autonome et peut être testé indépendamment.

Cela vous permet de tester chaque exercice séparément.
