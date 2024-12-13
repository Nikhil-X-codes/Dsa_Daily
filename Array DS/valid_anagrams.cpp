#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> mp;

        for (char i : s) {
            mp[i]++;
        }

        for (char i : t) {
            if (mp[i] > 0) {
                mp[i]--;
            } else {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution solution;
    string s = "anagram";
    string t = "nagaram";

    if (solution.isAnagram(s, t)) {
        cout << "The strings are anagrams." << endl;
    } 
    
    else {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}
