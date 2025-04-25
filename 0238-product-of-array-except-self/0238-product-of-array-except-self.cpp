class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Have an array of numbers we need to multiple together
        // We want to output an array of products, with the ith number being the
        // product of all numbers in nums besides nums[i]

        // edge cases
         // nums is empty
         // if num is 0

        // todo:
         // multiply all numbers together
         // divide by i

        int totalProduct = 1;
        int zeroCounter = 0;
        for(int num : nums){ // O(n)
            if(num != 0){
                totalProduct *= num; // multiply all nums together
            }
            else{
                zeroCounter++;
            }
        }

        if(zeroCounter > 1){
            return vector<int>(nums.size(), 0);
        }

        vector<int> result(nums.size());
        //result.reserve(nums.size());
        for(int i = 0; i < nums.size(); ++i){
            if(zeroCounter == 1){
                // make all numbers in result besides the nums[i] = 0 a zero
                if(nums[i] == 0){
                    result[i] = totalProduct;
                }
                else{
                    result[i] = 0;
                }
            }
            else{
                result[i] = totalProduct / nums[i];
            }
        }
        return result;
    }
};
