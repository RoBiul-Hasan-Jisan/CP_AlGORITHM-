#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
 //Second Largest Element in an Array
 //Given an array of positive integers arr[] of size n, the task is to find second largest distinct element in the array.



  int n;
  cin>>n;
  vector<int>a(n);
  for(int i = 0;i<n;i++)
  {
      cin>>a[i];

  }

  //sort(a.begin(),a.end());  //o(n log n)



  //cout<<a[n-2]<<endl;
  int lar =-1 ,sec =-1;

  for(int i=0;i<n;i++)  //0(n)
  {


      if(a[i]>lar)
      {

          sec = lar;
          lar = a[i];
      }


      else if(a[i]<lar && a[i]>sec)
      {
            sec=a[i];

      }
  }

  cout<<sec<<endl;





}
