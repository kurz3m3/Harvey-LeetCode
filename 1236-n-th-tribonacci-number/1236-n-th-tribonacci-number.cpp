using namespace std;
class Solution {
public:
    int tribonacci(int n) {
        unordered_map<int, int> memo;
        return helper(memo, n);
    }

    int helper(unordered_map<int,int> &memo, int n){
        if(memo.find(n) != memo.end()){
            return memo[n];
        }

        int result;
        if(n == 0){
            result = 0;
        }
        else if(n == 1 || n == 2){
            result = 1;
        }
        else{result = helper(memo, n-1) + helper(memo, n-2) + helper(memo, n-3);}
        memo[n] = result;
        return result;
    }
};