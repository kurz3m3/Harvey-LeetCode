class Solution {
private:
    vector<string> result;
public:
    void recurse(int n, int leftCount, int rightCount, string fullParenth){
        // base cases:
    
        // bad case, we can no longer matchup all the left parenth, more closing than opening
        if(leftCount < rightCount){
            return;
        }

        // bad case, we went over the counts and its invalid now
        if(leftCount > n || rightCount > n){
            return;
        }

        // happy case, we have equal left and right and done, add to result vector
        if(leftCount == n && rightCount == n){
            result.push_back(fullParenth);
            return;
        }

        // try opening cases
        fullParenth.push_back('(');
        recurse(n, leftCount+1, rightCount, fullParenth);
        fullParenth.pop_back();

        fullParenth.push_back(')');
        recurse(n, leftCount, rightCount+1, fullParenth);
        fullParenth.pop_back();
        return;
    }

    vector<string> generateParenthesis(int n) {
        // Task:
         // generate every combination we can with n pairs of parenthesis
         // they NEED to be VALID, ex. (()), (()()) etc.

        // Solution 1:
         // recursive?
         // check every combination possible from the spot we are at
         // every index of 0 should be a '(', every last index should be ')'

        recurse(n, 0, 0, "");
        return result;
    }
};