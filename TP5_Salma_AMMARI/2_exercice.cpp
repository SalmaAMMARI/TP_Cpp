//Exercice:2
#include <iostream>
#include <unordered_map> // For storing word frequencies in a hash table
#include <sstream>       // For breaking input text into words
using namespace std;
// Function to count the frequency of each word in the given text
void word_frequency(const std::string& text) {
    std::unordered_map<std::string, int> frequency; // Hash table to store word counts
    std::istringstream stream(text); // String stream to tokenize the input text
    std::string word; // Variable to hold each extracted word

    // Read words from the input string one by one
    while (stream >> word) {
        frequency[word]++; // Increment the count of the current word
    }

    // Print the word frequencies
    for (const auto& it : frequency) {
        std::cout << it.first << " -> " << it.second << "\n"; // Display word and its count
    }
}

int main() {
    std::cout << "Entrer un texte: ";
    std::string str;
    std::getline(std::cin, str); // Read the full input line
    cout<<"Fréquence des mots: "<<endl;
    word_frequency(str); // Call the function to analyze word frequencies

    return 0;
}
