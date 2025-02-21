//Eexrcice 1
#include <iostream>
#include <string>     // For handling strings
#include <algorithm>  // For std::transform, std::reverse, and std::remove_if
#include <cctype>     // For character manipulation functions like tolower and isspace

// Function to convert a string to lowercase
std::string toLower(const std::string& str) {
    std::string result = str; // Copy the input string to modify it
    std::transform(result.begin(), result.end(), result.begin(), ::tolower); // Convert each character to lowercase
    return result; // Return the modified string
}

// Function to check if a given string is a palindrome
bool is_palindrome(const std::string& text) {
    std::string copie = toLower(text); // Convert the input string to lowercase for case-insensitive comparison
    std::string copi1 = copie; // Create another copy of the lowercase string

    std::reverse(copie.begin(), copie.end()); // Reverse the string to compare with the original

    // Remove spaces from both original and reversed strings
    copie.erase(std::remove_if(copie.begin(), copie.end(), ::isspace), copie.end());
    copi1.erase(std::remove_if(copi1.begin(), copi1.end(), ::isspace), copi1.end());

    return copie == copi1; // Compare the processed original and reversed strings
}

int main() {
    std::cout << "Entrer un mot ou une phrase: ";
    std::string str;
    std::getline(std::cin, str); // Read the full input line including spaces

    // Check if the input is a palindrome and print the result
    if (is_palindrome(str)) {
        std::cout <<"\""<< str <<"\""<< " est un palindrome\n";
    } else {
        std::cout<<"\"" << str << "\""<<" n'est pas un palindrome\n";
    }

    return 0;
}
