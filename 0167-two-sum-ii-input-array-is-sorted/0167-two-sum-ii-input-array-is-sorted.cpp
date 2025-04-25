class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Task:
         // we have an array ints in ascending order?
         // need to return indices (1-indexed) [index1, index2] so both nums add to target
         // index1 cannot be == to index2, basically cannot use same element twice
         // ALWAYS ONE SOLUTION
         // O(1) space

        // Solution 1:
         // two pointers
         // if sum of the two is greater than target, decrease right pointer
         // is sum of the two is less than target, increase left pointer
         // do this until it equals target
         // return {left+1, right+1};

        if(numbers.empty()){
            return {};
        }

        int left = 0;
        int right = numbers.size()-1;
        while(left < right && numbers.at(left)+numbers.at(right) != target){
            int sum = numbers.at(left)+numbers.at(right);
            while(sum > target){
                right--;
                sum = numbers.at(left)+numbers.at(right);
            }
            while(sum < target){
                left++;
                sum = numbers.at(left)+numbers.at(right);
            }
            if(sum == target){
                break;
            }
        }

        return {left+1, right+1};

    }
};
