#include <iostream>
#include <string>
using namespace std;

int main()
{




int sum=0;
for(int i=1;i<13;i++){
    for(int j=1;j<13;j++){
     int var=i*j;
     if(i==1||i==2||i==3){ 
      if(j!=12) cout<<var<<"   ";
      else if(j == 12) cout<<var<<" \n";
      }
    else{ 
      if(j!=12) cout<<var<<"  ";
      else if(j == 12) cout<<var<<" \n";
      }
    }
}
}


