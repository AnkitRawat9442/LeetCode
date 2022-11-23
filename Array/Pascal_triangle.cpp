#include<iostream>
#include<vector>
using namespace std;

long long  fact(int n )
{
    if(n == 0  )
    return  1;
    return n * fact(n-1);

}

void solution (int numRows)
{
    long long  temp;
    for( int i = 0 ; i<= numRows ; i++)
    {
        long long  c = fact(i);
        for( int j = 0 ; j<= i  ; j++)
        {
          temp = c/(fact(i-j)*fact(j));
          cout <<temp<<" ";
        }
        cout<<endl;
    }
}

void solution_2 (int numRows)   // better opproach
{
    vector<vector<int>> res(numRows) ;
    for( int i = 0 ;i<numRows;i++)
    {
        res[i].resize(i+1);
        res[i][0] = res[i][i] = 1;
        for( int j = 1;j<i ;j++)
        {
            res[i][j] =  res[i-1][j-1] + res[i-1][j];
        }
    }


        
}

int main()
{
    int numRows ;
    cin>> numRows;
     solution(numRows);

     return 0 ;

}

