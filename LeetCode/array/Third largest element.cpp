#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
 //Third largest element in an array of distinct elements
 //Given an array of positive integers arr[] of size n, the task is to find second largest distinct element in the array.

  //Note: If the second largest element does not exist, return -1.

  int n;
  cin>>n;
  vector<int>a(n);
  for(int i = 0;i<n;i++)
  {
      cin>>a[i];

  }

  //sort(a.begin(),a.end());  //o(n log n)



  //cout<<a[n-3]<<endl;
  int lar =-1 ,sec =-1,td=-1;

  for(int i=0;i<n;i++)  //0(n)
  {


      if(a[i]>lar)
      {

          td = sec;
          sec = lar;
          lar = a[i];
      }


      else if( a[i]>sec)
      {

          td = sec;
          sec = a[i];



      }

        else if(  a[i]>td)
      {


          td = a[i];



      }
  }

  cout<<td<<endl;





}
