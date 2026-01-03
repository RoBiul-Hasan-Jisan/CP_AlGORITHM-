//If an array has 2n elements and only n+1 are unique, what can you say about the repeated element?
//There is exactly one element that repeats many times


class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

    

    set<int> a;
       
       for( int i : nums)
       {
        if(a.count(i))
        
            return i;
        
        a.insert(i);
       }
       return -1;

    }
};