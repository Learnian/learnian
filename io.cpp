#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
int main(){
  ofstream dts("dts.txt");
  string str;
  ifstream data ("data.txt");
  string str2;
  ifstream dat ("dat.txt");

  int dot;
  int dot2;
  int dsum; 
  while(getline(data,str)){
     getline(dat,str2);
     stringstream(str2)>>dot2;
     stringstream(str)>>dot;
     dsum+=dot*dot2;
      
}
 dts<<dsum;   

}
