#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    /**
     * @brief Checks if vector 'b' is a subset of vector 'a'.
     * * This function determines if all elements in vector 'b' are present in 
     * vector 'a', considering the frequency of elements.
     * * @param a The main vector.
     * @param b The vector to check if it's a subset.
     * @return true if 'b' is a subset of 'a', false otherwise.
     */
    bool isSubset(std::vector<int>& a, std::vector<int>& b) {
        // Create a frequency map of all elements in vector 'a'.
        std::unordered_map<int, int> freqMap;
        for (int element : a) {
            freqMap[element]++;
        }
        
        // Iterate through vector 'b' to check if each element exists in 'a'.
        for (int element : b) {
            // If the element is present in the map and its count is positive...
            if (freqMap.count(element) && freqMap[element] > 0) {
                // ...decrement the count, as we have "used" one occurrence.
                freqMap[element]--;
            } else {
                // If the element is not found or its count is already zero,
                // 'b' cannot be a subset.
                return false;
            }
        }
        
        // If the loop completes, all elements of 'b' were found in 'a'.
        return true;
    }
};