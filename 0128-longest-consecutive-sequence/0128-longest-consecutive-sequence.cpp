class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // finding longest sequence of nums we can make (num+1)

        // Edge cases:
         // if empty, return 0
         // duplicates are ignored
        
        // Solution 1 (NOT OPTIMAL!!!):
         // using sort(), will NOT be within O(n) time. --> O(n log n) time
         // DO NOT DO THIS UNLESS GIVEN UP!

        // Solution 2
         // iterate through nums, add num from nums into unordered_set. --> O(n) time
         // {0, 3, 2, 5, 4, 6, 1}
         // loop through num in nums again
         // check if num-1 exists in set. if it does go back and start from there for max sequence?
         // return longest sequence count

        if(nums.empty()){
            return 0;
        }

        unordered_set<int> numSet; // stores numbers we've seen
        for(int num : nums){
            numSet.insert(num); // insert each unique num into our set
        }

        int longestSeq = 0;
        for(int num : numSet){
            if(numSet.find(num-1) == numSet.end()){
                int len = 1;
                while(numSet.find(num+len) != numSet.end()){
                    len++;
                }
                longestSeq = max(longestSeq, len);
            }
        }
        return longestSeq;
    }
};
