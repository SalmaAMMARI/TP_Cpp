
# README - TP4

## Prérequis

Avant de commencer, assurez-vous d'avoir les éléments suivants installés sur votre machine :
- Un compilateur C++ (par exemple, GCC, Clang, ou Visual Studio).
- C++11 ou une version plus récente du langage C++.

## Instructions pour exécuter les exercices

### 1. Cloner ou télécharger le dépôt

Pour cloner ou télécharger ce dépôt sur votre machine, utilisez l'une des commandes suivantes :

#### Cloner le dépôt
```bash
git clone <URL du dépôt>
```

### 2. Sélectionner un exercice

Le fichier principal `main.cpp` contient une directive préprocesseur `EXO` que vous pouvez modifier pour sélectionner l'exercice que vous souhaitez exécuter. Par défaut, l'exercice sélectionné est l'Exercice 1.

#### Exemple pour sélectionner un exercice

Dans le fichier `main.cpp`, cherchez la ligne suivante :
```cpp
#ifndef EXO
#define EXO 1  // Changez ce nombre pour choisir un autre exercice
#endif
```

Modifiez la valeur de `EXO` en fonction de l'exercice que vous voulez tester :
- `EXO = 1` pour l'exercice 1
- `EXO = 2` pour l'exercice 2
- `EXO = 3` pour l'exercice 3
- Etc.

### 3. Compiler le programme

Une fois l'exercice choisi, compilez le programme avec votre compilateur. Par exemple, avec `g++`, vous pouvez utiliser la commande suivante :
```bash
g++ -o programme main.cpp
```

### 4. Exécuter le programme

Après la compilation, vous pouvez exécuter le programme avec la commande suivante :
```bash
./programme
```

### 5. Interaction avec le programme

Chaque exercice affiche des résultats à la console ou attend des entrées de l'utilisateur (selon l'exercice). Suivez les instructions qui s'affichent pour tester et explorer les exercices.

## Structure des exercices

1. **Exercice 1** : Manipulation d'un tableau 1D.
2. **Exercice 2** : Stockage d'une matrice avec des tableaux 2D.
3. **Exercice 3** : Utilisation de `std::array`.
4. **Exercice 4** : Manipulation de `std::vector`.
5. **Exercice 5** : Utilisation de `std::list` (Liste chaînée).
6. **Exercice 6** : Utilisation de `std::set` pour des éléments uniques.
7. **Exercice 7** : Utilisation de `std::unordered_map` pour des paires clé-valeur.
8. **Exercice 8** : Comptage de mots avec `std::unordered_map`.
9. **Exercice 9** : Tri d'un `std::vector`.
10. **Exercice 10** : Recherche de la séquence consécutive la plus longue dans un `std::set`.
11. **Exercice 11** : Implémentation d'un cache LRU.

## Remarque

Assurez-vous de bien choisir l'exercice voulu avant de compiler le programme, en modifiant la valeur de `EXO`. Chaque exercice est autonome et peut être testé indépendamment.

Cela vous permet de tester chaque exercice séparément.
