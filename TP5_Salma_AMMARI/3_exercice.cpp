//Exercice 3
#include <iostream>
#include <string>    // For using std::string

// Function to perform Run-Length Encoding (RLE) on the given text
std::string encode_rle(const std::string& text) {
    std::string result;  // Stores the encoded string
    int l = text.size(); // Get the length of the input text

    // Iterate over the input text
    for (int i = 0; i < l; ++i) {
        int f = 1; // Initialize the frequency counter for the current character

        // Count consecutive occurrences of the same character
        while (i < l - 1 && text[i] == text[i + 1]) {
            f++; // Increment frequency
            i++; // Move to the next character
        }

        // Append the character and its frequency to the result string
        result += text[i] + std::to_string(f);
    }

    return result; // Return the encoded string
}

int main() {
    std::cout << "Entrer un texte: ";

    std::string str;
    std::getline(std::cin, str); // Read the entire input line

    // Call the encoding function and display the result
    std::cout << encode_rle(str) << "\n";

    return 0;
}
