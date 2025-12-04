#include <bits/stdc++.h>
using namespace std;

/*
  Given a string s, find the length of the longest substring without repeating characters.

Example
Input:  "abcabcbb"
Output: 3

*/
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
  string s;
  cin>> s;
  int n = s.size();
  set<char>ss;
   int r =0,ans=0;
   for(int l = 0; l < n; l++) {
       while(ss.count(s[l]))
       {
        ss.erase(s[r]);
        r++;
       }

       ss.insert(s[l]);
       ans = max(ans,l-r+1);

   }

  cout<< ans <<endl;

}
