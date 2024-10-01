#include <sstream>
#include <string>
#include <vector>
#include <iostream>

// Function to split a string by space and return a vector of the resulting
// substrings
std::vector<std::string> split(const std::string& input)
{
    std::istringstream iss(input);
    std::vector<std::string> words;
    std::string word;
    while (iss >> word)
    {
        words.push_back(word);
    }
    return words;
}

int main()
{
    // Example input string
    std::string input = "This is an example string";

    // Split the input string and print the resulting words
    std::vector<std::string> words = split(input);
    for (const std::string& word : words)
    {
        std::cout << word << std::endl;
    }

    return 0;
}

