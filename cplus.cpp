

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

float area( float r ){
    if ( r>100)
      cout << "\nthats a big circle. Radius="<<r;
    else if ((r>50) && (r<100))
       cout << "\nthats a medium circle. Radius="<<r;
    else
       cout << "\nthats a small circle. Radius="<<r;
    float pie=3.1415;
    float A;
    A=pie*r*r;
    return A;
    
}

int main(){
cout<<"Choose a radius value";
float rd=0.5;
string str;
getline (cin,str);
stringstream(str)>>rd;
cout<<"\n"<<rd;
float a=area(rd);
cout<<"\nArea=" << a;
}
