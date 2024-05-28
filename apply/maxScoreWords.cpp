#include <bits/stdc++.h>
#include <vector>

/*
    Given a list of words, list of  single letters (might be repeating) and score of every character.
    Return the maximum score of any valid set of words formed by using the given letters (words[i] cannot be used two or more times).
    It is not necessary to use all characters in letters and each letter can only be used once. 
    Score of letters 'a', 'b', 'c', ... ,'z' is given by score[0], score[1], ... , score[25] respectively.

    Input: words = ["dog","cat","dad","good"], 
    letters = ["a","a","c","d","d","d","g","o","o"], 
    score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]
    Output: 23
        Explanation:
        Score  a=1, c=9, d=5, g=3, o=2
    Given letters, we can form the words "dad" (5+1+5) and "good" (3+2+2+5) with a score of 23.
    Words "dad" and "dog" only get a score of 21.


    Algorithm:
        getting numbers of each words: to push into map[char,int]

*/

using namespace std;

class Solution {
        void getting_number_of_char(vector<string> &words) {
            for (auto word : words) {
                for (auto c : word) {
                    c_mapping[c]++;
                }
            }
        }

        void calculate(vector<string> &words, vector<char> &letters, vector<int> &score) {
            
            for (auto word : words) {

            }
        }
    public:
        Solution() {
            
        }
        int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score) {
            getting_number_of_char();
        }

    protected:
        std::map<char, int> c_mapping;
        std::queue<string> q;
        int m_res;
};

int main() {

}