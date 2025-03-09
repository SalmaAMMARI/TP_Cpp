#include <iostream>  // Include the input-output stream library
#include <string>    // Include the string library for handling strings

using namespace std;  // Use the standard namespace to avoid writing std:: before cout, string, etc.

// Define a class named 'joueur' (French for "player")
class joueur {
private:
    int score;        // Private member variable to store the score
    std::string name; // Private member variable to store the player's name

public:
    // Constructor that initializes the player's name and score
    joueur(int n, std::string nom) {
        name = nom;  // Assign the name parameter to the member variable
        score = n;   // Assign the score parameter to the member variable
    };

    // Function to display the player's details
    void display() {
        cout << "Nom : " << name << endl;  // Print the player's name
        cout << "Score: " << score << endl; // Print the player's score
    }

    // Destructor, automatically called when an object is destroyed
    ~joueur() {
        cout << "Objet dynamiquement supprimé" << endl;  // Message when the object is deleted
    }
};

int main() {
    // Create an object 'Alice' of class joueur with score 100 and name "Alice"
    joueur Alice(100, "Alice");
    Alice.display();  // Call display function to show Alice's details

    // Dynamically allocate memory for an object 'Bob' of class joueur
    joueur* Bob = new joueur(200, "Bob");
    Bob->display();  // Call display function using pointer syntax (->)

    // Manually delete the dynamically allocated object to free memory
    delete Bob;

    return 0;  // Return 0 to indicate successful program execution
}
