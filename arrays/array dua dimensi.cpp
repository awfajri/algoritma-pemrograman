#include <iostream>
using namespace std;

int main (){
    int a [4][4];
    int i,j,x,y;

    for ( i = 0; i < 4; ++i)
    {
        for ( j = 0; j < 4; j++)
        {
            if (i<=j)
            {
                a[i][j] = 1;
            }
            else if (i>j)
            {
                a[i][j] = 0;
            }
            cout <<a[i][j] <<" ";
        }cout<<endl;        
    }
    return 0;
}