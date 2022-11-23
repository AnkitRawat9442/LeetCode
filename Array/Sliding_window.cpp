#include<iostream>
#include<vector>
using namespace std;

int max_Sum_Window (vector<int> arr  , int size)
{
    int k =0 , n = arr.size() , i = 0 , j =0 , sum = 0 , a = 0  , b = 0  ;
    while(j<n )
    {
      sum+= arr[j];
      cout<<sum<<endl;
      if(j == size)
      k = sum ;
      else{
        if(k < sum )
        {
          k = sum ;
          a = i , b = j;
        }
      
        sum -= arr[i];
      }
      j++;
    }
    cout<<"i : "<<a << " j : "<<b<<endl;
    return k ;
}

int main()
{ 
    int n , size ;
    cout<<"Enter the size of array : ";
    cin>>n ;
    vector<int> arr(n);
    for( int i=0 ;i<n ;i++)
    {
     cin>>arr[i];
    }
    cout<<"Enter the size of window : ";
    cin>>size;
    cout<<"Max Sum : "<<max_Sum_Window(arr , size);
   

    return 0;
}