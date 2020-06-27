#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
string str;
ifstream filename ("filename.txt");
while(getline(filename,str)){
 cout<<str<<"\n";

}

}

