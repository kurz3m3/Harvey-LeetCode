class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Need to check each string and group similar words
        // return vector of vectors with with anagrams in the same nested vectors
        // Handle empty case and words with no matches
        if(strs.empty()){
            return {{""}};
        }
        
        // Naive solution:
         // sort each word and then find matches
         // O(n log n) time complexity?
         // use hashmap to find matches

        
        unordered_map<string,vector<string>> wordMap;
        for(const auto& c : strs){
            string sortedC = c;
            sort(sortedC.begin(), sortedC.end());
            wordMap[sortedC].push_back(c);
        }
        vector<vector<string>> result;
        for(auto& m : wordMap){
            result.push_back(m.second);
        }
        


        // Better solution:
         // bucket sort? Have array of alphabet and count letters?
        //unordered_map<string, >
        
        return result;
    }
};