#include <iostream>
#include <string>
using namespace std;

int main() {
  string fruits[5];
  int i;
  for (i = 0; i < 5 ; i++)
  {
    cout << "fruits number" << i+1<< " : " ; cin>>fruits[i];
  }
  cout<<"\n -- results--"<<endl<<endl;

  for ( i = 0; i < 5; i++)
  {
     cout << "fruits number" << i+1<< " : " <<fruits[i] << endl;
  }
  return 0;
}
