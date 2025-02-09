
# README - TP1 - AMMARI Salma

## Description

Ce TP contient plusieurs exercices  utilisant les directives du préprocesseur. En fonction de la macro `EXO` définie lors de la compilation, un exercice spécifique sera compilé et exécuté. Par défaut, l'exercice 1 est sélectionné. 

## Structure du TP

Le projet contient un seul fichier source principal nommé `main.cpp`.

### Fichiers :
- **main.cpp** : Contient le code principal du programme avec les directives du préprocesseur pour choisir l'exercice à exécuter.

## Instructions d'exécution

1. Avant de compiler, assurez-vous d’être dans le dossier contenant `main.cpp` :
 ```bash
   cd /chemin/vers/TP1_Nom_Prenom
   ```



2. **Compiler le code** :
   Le code peut être compilé en utilisant `g++` ou tout autre compilateur C++ compatible. Pour spécifier quel exercice compiler, utilisez l'option `-DEXO=`, suivie du numéro de l'exercice souhaité. Par exemple :
   - Pour compiler l'exercice 1 :
     ```bash
     g++ -DEXO=1 main.cpp -o main
     ```
   - Pour compiler l'exercice 2 :
     ```bash
     g++ -DEXO=2 main.cpp -o main
     ```
   - Pour compiler l'exercice 3 :
     ```bash
     g++ -DEXO=3 main.cpp -o main
     ```
   - Pour compiler l'exercice 4 :
     ```bash
     g++ -DEXO=4 main.cpp -o main
     ```
    - Pour compiler l'exercice 5 :
     ```bash
     g++ -DEXO=5 main.cpp -o main
     ```

3. **Exécuter le programme** :
   Une fois le programme compilé, vous pouvez l'exécuter avec la commande suivante :
   ```bash
   ./main
   ```


## Explication des exercices

### Exercice 1 : Affichage d’un message

- Affiche "Hello, World!" et "Welcome to C++".

### Exercice 2 : Lecture et affichage d'un entier

- Demande à l'utilisateur d'entrer un nombre et l'affiche.

### Exercice 3 : Opérations mathématiques

- Lit deux nombres, puis affiche leur somme, différence, produit et quotient (si le diviseur n'est pas nul).

### Exercice 4 : Correction d'erreurs de compilation

- Corrige les erreurs dans un programme d'affichage d'un nombre entré par l'utilisateur.

### Exercice 5 : Conversion de température

- Convertit une température de Celsius en Fahrenheit.

## Compilation et Exécution

Voici un résumé des commandes de compilation et d'exécution pour chaque exercice :

| Exercice  |Commande de compilation                           | Commande d'exécution             |
|------------|------------------------------------------------|-----------------------------------|
| Exercice 1 | `g++ -DEXO=1 main.cpp -o main`                    | `./main`                       |
| Exercice 2 | `g++ -DEXO=2 main.cpp -o main`                    | `./main`                       |
| Exercice 3 | `g++ -DEXO=3 main.cpp -o main`                    | `./main`                       |
| Exercice 4 | `g++ -DEXO=4 main.cpp -o main`                    | `./main`                       |
| Exercice 5 | `g++ -DEXO=4 main.cpp -o main`                    |  `./main`                      |

## Notes

- Si vous ne définissez pas la macro `EXO` lors de la compilation, l'exercice 1 sera compilé par défaut.
