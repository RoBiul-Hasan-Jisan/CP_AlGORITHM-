
#include <bits/stdc++.h>
using namespace std;

//Anagram Cheek
//Approach 1:O(n log n)
void slove()
{

    string s,s1;
    cin>>s>>s1;
    sort(s.begin(),s.end());
    sort(s1.begin(),s1.end());
    if (s==s1) cout<<"YES"<<endl;
    else  cout<<"NO"<<endl;
}

//Approach 2:O( n)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t ;
    cin>> t;
    while(t--)

    {
        //Way 1:O(n log n)
        string s,s1;
        cin>>s>>s1;
        if(s.size()!=s1.size())
        {

            cout<<"NO"<<endl;
            continue;
        }


        int freq[256]= {0};
        for(char c:s)freq[c]++;
        for(char c :s1)freq[c]--;

        bool ok = true;
        for(int i=0; i<256; i++)
        {

            if(freq[i]!=0)
            {


                ok = false;
                break;


            }
        }
        cout << (ok? "YES\n" : "NO\n");

    }
    return 0;
}
