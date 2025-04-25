class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> results;
        unordered_map<string, vector<string>> wordMap;
        for(string s : strs){
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            wordMap[sortedS].push_back(s);
        }

        for(auto& it : wordMap){
            results.push_back(it.second);
        }

        return results;
    }
};