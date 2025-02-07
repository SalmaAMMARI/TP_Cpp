
# README - TP[Cours_ou_Numéro] - Nom Prénom

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

3. **Exécuter le programme** :
   Une fois le programme compilé, vous pouvez l'exécuter avec la commande suivante :
   ```bash
   ./main
   ```

4. **Afficher les arguments passés en ligne de commande** :
   Si vous utilisez l'exercice 2 (en passant `-DEXO=2` lors de la compilation), vous pouvez tester la réception d'arguments en ligne de commande. Par exemple, vous pouvez par exemple passer des arguments comme suit :
   ```bash
   ./main arg1 arg2
   ```

   Cela affichera les arguments entrés en ligne de commande:
   ```
   Argument 1: arg1
   Argument 2: arg2
   ```

## Explication des exercices

### Exercice 1 : Utilisation des directives du préprocesseur
- Affiche si la macro `DEBUG` est définie ou non, selon le code.

### Exercice 2 : Utilisation des arguments de la ligne de commande
- Le programme affiche les arguments passés en ligne de commande.

### Exercice 3 : Espaces de noms et portée des variables
- Le programme affiche une variable définie dans un espace de noms personnalisé, avec et sans utiliser `using namespace`.

### Exercice 4 : Entrée et sortie avec `cin` et `cout`
- Demande à l'utilisateur d'entrer un entier et un nombre à virgule, puis affiche les valeurs saisies.

## Compilation et Exécution

Voici un résumé des commandes de compilation et d'exécution pour chaque exercice :

| Exercice  |Commande de compilation                           | Commande d'exécution             |
|------------|------------------------------------------------|-----------------------------------|
| Exercice 1 | `g++ -DEXO=1 main.cpp -o main`                    | `./main`                       |
| Exercice 2 | `g++ -DEXO=2 main.cpp -o main`                    | `./main arg1 arg2`(ex de 2 args|
| Exercice 3 | `g++ -DEXO=3 main.cpp -o main`                    | `./main`                       |
| Exercice 4 | `g++ -DEXO=4 main.cpp -o main`                    | `./main`                       |

## Notes

- Si vous ne définissez pas la macro `EXO` lors de la compilation, l'exercice 1 sera compilé par défaut.
