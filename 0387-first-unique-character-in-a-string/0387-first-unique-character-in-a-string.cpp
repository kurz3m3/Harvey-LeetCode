class Solution {
public:
    int firstUniqChar(string s) {
        if(s.empty()){
            return -1;
        }
        /*
        * Map (lettersSeen):
        * key = letter seen
        * value = # of times we've seen that letter/key
        */
        unordered_map<char, int> lettersSeen;
        for(char c : s){
            lettersSeen[c]++;
        }
        for(int i = 0; i < s.size(); ++i){
            if(lettersSeen[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};