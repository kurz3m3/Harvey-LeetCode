class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> targetLookup;
        for(int i = 0; i < nums.size(); ++i){
            int neededNumber = target - nums[i];
            if(targetLookup.find(neededNumber) != targetLookup.end()){
                return {targetLookup[neededNumber], i};
            }
            targetLookup[nums[i]] = i;
        }
        return {};
    }
};