#include <iostream>
#include <vector>
using namespace std ;
struct graph{
    int v ;//vertices
    vector<int>* adj ;//tableau de tableau , l indice i est le noeud et adj[i] est la liste des adjacents
    //Constructeur
    graph(int v){
        this->v=v;
        adj = new vector<int>[v] ;
    }
    // Méthode pour ajouter une arête (de sommet u à sommet v)
    void edge(int u , int v){
        adj[u].push_back(v);
    }
    void dfs(int v , vector<bool>& visited){
        visited[v]=true;
        cout<<v<<" ";
        for (int i:adj[v]){
            if (!visited[i]){
                dfs(i, visited);
            }
        }

    }
    void DFS(int start){
        vector<bool> visited(v , false);
        cout << "Parcours en profondeur à partir du sommet " << start << " : ";
        dfs(start, visited);
        cout << endl;

    }
    ~graph() {
        delete[] adj;  // Libère la mémoire allouée dynamiquement
    }

};
// Destructeur pour libérer la mémoire



int main() {
    graph g(4);
    // Ajout des arêtes
    g.edge(0, 1);
    g.edge(0, 3);
    g.edge(1, 3);
    g.edge(3, 2);
    g.DFS(0);
    return 0;

}
