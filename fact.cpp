#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int fact(int a){
 int p=1;
 for(int i=1;i<=a;i++){
     p*=i;
 }
 return p;

}



int main()
{
 int j=0;
 while(j<=5){
  if(j==0){
   cout<<"Choose a number";
   int n=0;
   string str;
   getline (cin,str);
   stringstream(str)>>n;
   if(n<34){
   int f=fact(n);
   cout<<"\n" << n<<"!="<<f<<endl;
   }
   else{
     cout<<"\nThat is to large. Choose a number below 35\n";
   }
  }
  else{
  cout<<"Choose another number";
  int n=0;
   string str;
   getline (cin,str);
   stringstream(str)>>n;
   if(n<34){
    int f=fact(n);
    cout<<"\n" << n<<"!="<<f<<endl;
   }
   else{
     cout<<"\nThat is to large. Choose a number below 35\n";
   }
  }
   j++;
    }
 
 }
