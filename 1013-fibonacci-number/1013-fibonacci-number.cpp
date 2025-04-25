class Solution {
public:
    int fib(int n) {
        unordered_map<int,int> mem;
        return helper(mem, n);
    }

    int helper(unordered_map<int,int> &mem, int n){
        if(mem.find(n) != mem.end()){
            return mem[n];
        }

        int result;
        if(n == 0){
            result = 0;
        }
        else if(n == 1){
            result = 1;
        }
        else{
            result = helper(mem, n-1) + helper(mem, n-2);
        }

        mem[n] = result;
        return result;

    }
};