#include <iostream> // Inclusion de la bibliothèque iostream
#include <array>
#include <vector>
#include <list>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <utility>

using namespace std;

#ifndef EXO
#define EXO 1
#endif

//Exercice 11
void put(std::list<std::pair<int, int>>& lru , std::unordered_map<int, std::list<std::pair<int, int>>::iterator>& cache , int capacity ,int  value,int key ){
    std::pair<int , int> paiir (key , value);
    if (cache.find(key)!=cache.end()){  //si la clé existe déjà dans le cache
        //on doit modifier la valeur de la paire dans le cache
        auto it = cache.find(key);
        //it est un itérateur pointant vers key dans map cache
        //it->first est la clé it->second est la valeur qui est un itérateur pointant sur la paire (key, value) dans lru
        //donc it->second->second est la valeur de la clé key dans lru
        it->second->second = value ;//on a changé la valeur de la clé
        //on doit déplacer la  paire (key , value ) à la tete de la liste dans lru
        //pour faire  ça on utilise splice (iterateur arrivée , liste , itérateur départ)
        //puisque it->second est l'itérateur pointant sur la paire dans lru et lru.begin() it"rateur pointant au début de lruon ecrit donc :
        lru.splice(lru.begin() , lru ,it->second);
        //on doit modifier la valeur de l'iterateur de la clé key dans le map ,
        //après avoir déplacer la paire au début de la liste lru , l'itérateur pointant sur la paire est lru.begin()
        cache[key]=lru.begin();



    }else{
        // on doit ajouter la paire  (key , iterator)au map cache et ajouter (key , value) en tete de lru si la capacite de lru n est pas atteinte
        //sion on supprime la paire  le moins récemment utilisée
        if (lru.size()==capacity){
            //si la capacity est atteint on supprime le dernier élément de la liste et on ajoute (key ,value) en tete
            auto dernier =lru.back();//le dernier pair de lru
            lru.pop_back();
            cache.erase(dernier.first);//supprimer paire du cache dont l itérateur est celui de la paire supprimée de lru
            lru.push_front(std::make_pair(key,value));
            //ajouter (key ,iterator) au cache
            cache[key]=lru.begin();
            cout<<"Ajout de ("<<key<<" , "<<value<<") , suppression de  ("<<dernier.first<<" , "<<dernier.second<<" )\n";


        }else{
            //si la capacité n'est pas atteinte , on ajoute la paire en tete de lru , et on ajoute paire (key , iterator) dans le map cache
            lru.push_front(std::make_pair(key,value));
            //ajouter (key ,iterator) au cache
            cache[key]=lru.begin();



        }

    }



}
int get( std::unordered_map<int, std::list<std::pair<int, int>>::iterator>& cache, std::list<std::pair<int, int>>& lru , int key){
    // retourner la valeur associée à une clé (key) si il exist
    auto it = cache.find(key);
    if (it==cache.end()){ //si la clé n'existe pas
        return -1;

    }else{
        int value = it->second->second ;//la valeur associé au clé
        //on doit déplacer (key, value) à la tete de la liste lru
        lru.splice(lru.begin(), lru,it->second);
        // changer la valeur associée à key dans cach
        cache[key]=lru.begin();
        cout<<"Acces à la cle "<<key<<" :"<<value<<"\n";
        return value;



    }

}
void afficher(std::list<std::pair<int, int>>& lru ){
    cout<<"Etat du cache: ";
    for (auto it=lru.begin(); it!=lru.end();++it) {
        cout << "(" << it->first << ", " << it->second << ") ";

    }
    cout<<"\n";


}


int main() {
#if EXO==1
    // Exercice 1: Manipulation d’un tableau C 1D
    int n;
    cout << "Entrez le nombre d'éléments du tableau: ";
    cin >> n;
    int arr[n];
    cout << "Entrez les éléments du tableau:" << endl;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];  // Calcul de la somme des éléments du tableau
    }
    cout << "Elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\nSomme : " << sum << endl;

#elif EXO==2
    // Exercice 2: Tableau C 2D (Stockage Matriciel)
    int rows, cols;
    cout << "Entrez le nombre de lignes de la matrice: ";
    cin >> rows;
    cout << "Entrez le nombre de colonnes de la matrice: ";
    cin >> cols;
    int arr[rows][cols];
    cout << "Entrez les éléments de la matrice:" << endl;
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
            if (i == j) {
                sum += arr[i][j]; // Additionne les éléments de la diagonale principale
            }
        }
    }
    cout << "Matrice:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\nSomme diagonale : " << sum << endl;

#elif EXO==3
    // Exercice 3: Utilisation de std::array
    std::array<int, 5> arr;
    cout << "Entrez 5 éléments pour le tableau: ";
    for (std::size_t i = 0; i < arr.size(); ++i) {
        cin >> arr[i];
    }
    cout << "Original: ";
    for (std::size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << "\nInverse: ";
    for (auto it = arr.rbegin(); it != arr.rend(); ++it) {
        cout << *it << " "; // Affiche les éléments du tableau dans l'ordre inverse
    }
    cout << endl;

#elif EXO==4
    // Exercice 4: Utilisation de std::vector
    int n;
    cout << "Entrez le nombre d'éléments pour le vector: ";
    cin >> n;
    std::vector<int> vect(n);
    cout << "Entrez les éléments du vector: ";
    for (int i = 0; i < n; ++i) {
        cin >> vect[i];
    }
    cout << "Doubles: ";
    for (auto it = vect.begin(); it != vect.end(); ++it) {
        cout << 2 * (*it) << " ";  // Multiplie chaque élément du vector par 2
    }
    cout << endl;

#elif EXO==5
    // Exercice 5: Utilisation de std::list (Liste Chaînée)
    int n;
    cout << "Entrez le nombre d'éléments pour la liste: ";
    cin >> n;
    std::list<int> lista;
    cout << "Entrez les éléments de la liste: ";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        lista.push_back(val);
    }
    lista.push_front(0);  // Ajoute un élément au début de la liste
    lista.push_back(60);  // Ajoute un élément à la fin de la liste
    for (int val : lista) {
        cout << val << " ";  // Affiche tous les éléments de la liste
    }
    cout << endl;

#elif EXO==6
    // Exercice 6: Utilisation de std::set (Éléments Uniques)
    int n;
    cout << "Entrez le nombre d'éléments pour le set: ";
    cin >> n;
    std::set<int> seet;
    cout << "Entrez les éléments du set: ";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        seet.insert(val);  // Insère chaque élément dans le set (les doublons sont automatiquement éliminés)
    }
    cout << "Original: ";
    for (int x : seet) {
        cout << x << " ";
    }
    cout << "\nAprès insertion de 10 : ";
    seet.insert(10);  // Insère l'élément 10 dans le set (s'il n'est pas déjà présent)
    for (int x : seet) {
        cout << x << " ";  // Affiche les éléments du set (toujours sans doublons)
    }
    cout << " (pas de doublons)" << endl;

#elif EXO==7
    // Exercice 7: Utilisation de std::unordered_map (Paires Clé-Valeur)
    int n;
    cout << "Entrez le nombre d'éléments pour la map: ";
    cin >> n;
    std::unordered_map<std::string, int> stds;
    cout << "Entrez les paires clé-valeur (nom et note): " << endl;
    for (int i = 0; i < n; ++i) {
        string name;
        int grade;
        cin >> name >> grade;
        stds[name] = grade;  // Insère une paire clé-valeur dans la map
    }
    for (const auto& pair : stds) {
        cout << pair.first << " : " << pair.second << endl;  // Affiche toutes les paires clé-valeur
    }

#elif EXO==8
    // Exercice 8: Compteur de mots avec std::unordered_map
    string input;
    cout << "Entrez la phrase: ";
    cin.ignore();
    getline(cin, input);  // Récupère une ligne entière d'entrée
    std::unordered_map<std::string, int> wordCount;

    string word = "";
    for (char c : input) {
        if (c == ' ') {
            if (!word.empty()) {
                wordCount[word]++;  // Compte le mot actuel
                word = "";
            }
        } else {
            word += c;  // Construit le mot caractère par caractère
        }
    }

    if (!word.empty()) {
        wordCount[word]++;  // Compte le dernier mot s'il existe
    }

    for (const auto& pair : wordCount) {
        cout << pair.first << " : " << pair.second << endl;  // Affiche chaque mot et son nombre d'occurrences
    }

#elif EXO==9
    // Exercice 9: Trier un std::vector
    int n;
    cout << "Entrez le nombre d'éléments pour le vector: ";
    cin >> n;
    std::vector<int> nums(n);
    cout << "Entrez les éléments du vector: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << "Original: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << "\nSorted: ";
    std::sort(nums.begin(), nums.end());  // Trie les éléments du vector par ordre croissant
    for (int num : nums) {
        cout << num << " ";  // Affiche le vector trié
    }
    cout << endl;

#elif EXO==10
    // Exercice 10: Trouver la Plus Longue Séquence Consécutive dans un std::set
    int n;
    cout << "Entrez le nombre d'elements pour la liste: ";
    cin >> n;
    list <int> numList;
    cout << "Entrez les elements du set: ";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        numList.push_back(val);  // Ajoute chaque élément dans la liste
    }
    set<int> numSet;
    for (auto it=numList.begin(); it!=numList.end(); ++it) {
        numSet.insert(*it);  // Insère chaque élément de la liste dans un set pour garantir l'unicité
    }
    int maxlength = 0;
    vector<int> longest_subset;
    for (int num : numSet) {
        // Vérifie si num est le début d'une séquence (c'est-à-dire que num-1 n'existe pas dans le set)
        if (numSet.find(num - 1) == numSet.end()) {
            int current = num;
            int currentlength = 1;
            vector<int> current_subset = {current};
            // Ajoute les éléments consécutifs qui viennent après current
            while (numSet.find(current + 1) != numSet.end()) {
                current++;
                currentlength++;
                current_subset.push_back(current);
            }
            if (currentlength > maxlength) {
                maxlength = currentlength;
                longest_subset = current_subset;  // Met à jour la séquence la plus longue
            }
        }
    }
    cout << "Plus longue sequence: " << maxlength << " (";
    for (int num : longest_subset) {
        cout << num << " ";  // Affiche les éléments de la plus longue séquence
    }
    cout << ")" << endl;

#elif EXO == 11
    // Exercice 11: (Ajouter d'autres exercices ici si nécessaire)
    // Définir la capacité du cache
    int capacity = 2;

    // Créer la liste LRU et le cache
    std::list<std::pair<int, int>> lru;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache;
    put(lru , cache ,capacity, 10,1);
    put(lru , cache ,capacity , 20,2);
    afficher(lru);
    int acces = get(cache,lru , 1);
    afficher(lru);
    put(lru , cache ,capacity , 30,3);
    afficher(lru);




#else
#error 'Veuillez définir EXO à 1, 2, 3 ou 4 (exemple: -DEXO=1 , -DEXO=2)'
#endif
    return 0;
}
