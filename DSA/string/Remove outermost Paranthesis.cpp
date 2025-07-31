#include<bits/stdc++.h>
#define ll long long
#define IOS ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 2;
string Slove(string s)
{
//interview question prb 2
//(()())()  ->()()
//we need removed each  segment outer ( ) thats it 
//stack 0(n) on other idea 


      stack<char> st;
        string op = "";

        for( char i : s ){

            if( i == '(' ){
                if(!st.empty()){
                    op = op + i;
                }
                st.push(i);
            }
            else{
                if( !(st.empty()) && st.top()=='('){
                    st.pop();
                }
                if(!st.empty()){
                    op = op + i;
                }
            }

        }
        return op ;
}
signed main()
{
    IOS;
    int t = 1;
    //cin >> t;
    while (t--)

    {


    string s;
    cin>>s;

       cout<<Slove(s);
    }
    return 0;
}
