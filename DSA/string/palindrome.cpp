
#include <bits/stdc++.h>
using namespace std;

//Funny String
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t ;
    cin>> t;
    while(t--)

    {

        string s;
        cin>>s;
        cout<<s.size()<<endl;
        int l=0,r=s.size()-1;
        bool ok = true;
        while(l<=r)
        {

            if(s[l]!=s[r])
            {
                ok= false;
                break;
            }

            l++;
            r--;

        }
        if (isFunny)
            cout << "YES ITS FUNNY\n";
        else
            cout << "NO ITS NOT FUNNY\n"

        }

    return 0;
}
