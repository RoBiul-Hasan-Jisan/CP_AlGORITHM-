class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // plan create new  vector  where i  store  all   element 
        // a  and  b  
        // a=[1,2,3,0,0,0] b=[2,5,6] 
        //output[1,2,2,5,6]  where i   need  to  ignored  zero  and must  be  ascinding   oder
        vector<int>store;


        for (int i=0;i<m;i++) 
            store.push_back(nums1[i]);

        for (int j=0;j<n;j++) 
            store.push_back(nums2[j]);
        sort(store.begin(),store.end());
        for (int i = 0; i < m + n; i++) 
            nums1[i] =store[i];
    }  
};
