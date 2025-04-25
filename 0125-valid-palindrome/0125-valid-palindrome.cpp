class Solution {
public:
    bool isPalindrome(string s) {
        // Task:
          // we have a string and need to check if its a palindrome
          // check if letters on both sides are equivalent and move inwards left and right
          // Ignore spaces, punctuation / symbols?
          // Dont ignore numbers?
          // Use isalnum(), I think this is the correct function?

        if(s.empty()){
            return false; // what do we return if no string?
        }
        int left = 0;
        int right = s.size()-1;

        while(left <= right){
            if(isalnum(s.at(left)) && isalnum(s.at(right)) && tolower(s.at(left)) != tolower(s.at(right))){
                return false;
            }
            if(isalnum(s.at(left)) && !isalnum(s.at(right))){
                right--;
                continue;
            }
            else if(!isalnum(s.at(left)) && isalnum(s.at(right))){
                left++;
                continue;
            }
            left++;
            right--;
        }

        return true;
    }
};
