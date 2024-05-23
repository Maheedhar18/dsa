#include <iostream>
#include <vector>
#include <string>

// KMP (Knuth Morris Pratt) Pattern Searching Algorithm

int main() {
    // Define the text and pattern strings
    std::string text = "ABABDABACDABABCABAB";
    std::string pattern = "ABABCABAB";

    // Get the lengths of text and pattern
    int m = text.size();
    int n = pattern.size();

    // Initialize the LPS (Longest Prefix Suffix) array
    std::vector<int> longestPrefixSuffix(n, 0);

    // Building the LPS array
    int prevLPS = 0, i = 1;
    while (i < n) {
        if (pattern[i] == pattern[prevLPS]) {
            // If characters match, update LPS and move to the next character
            longestPrefixSuffix[i] = prevLPS + 1;
            prevLPS++;
            i++;
        } else {
            if (prevLPS == 0) {
                // If no prefix of the current prefix is a suffix, set LPS to 0 and move to the next character
                longestPrefixSuffix[i] = 0;
                i++;
            } else {
                // If there's a mismatch, update prevLPS using previously computed values
                prevLPS = longestPrefixSuffix[prevLPS - 1];
            }
        }
    }

    // Searching for the pattern in the text
    int j = 0;
    i = 0;
    while (i < m) {
        if (text[i] == pattern[j]) {
            // If characters match, move to the next characters in both text and pattern
            i++;
            j++;
            if (j == n) {
                // If the entire pattern is found, print the starting index
                std::cout << "Found pattern at index " << i - j << "\n";
                // Update j using LPS array for potential overlap
                j = longestPrefixSuffix[j - 1];
            }
        } else {
            if (j == 0) {
                // If no characters matched, move to the next character in the text
                i++;
            } else {
                // If there's a mismatch, update j using LPS array for potential overlap
                j = longestPrefixSuffix[j - 1];
            }
        }
    }

    return 0;
}
