#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <typeinfo>
using namespace std;
int main(){
 // ofstream dts("r_dots.txt");
  string strv;
  ifstream data ("v.txt");
  string strw;
  ifstream dat ("w.txt");

  vector <float> v;
  vector <float> w;
  float dot_p; 
  float w1;
  float v1;
//set the vectors from the data files
  while(getline(data,strv)){
     getline(dat,strw);
     stringstream(strw)>>w1;
   //  v.push_back(w1);
     stringstream(strv)>>v1;
     cout<<typeid(w1).name()<<"  =type of w\t";
     cout<<typeid(v1).name()<<"  =type of v\n";

     //v.push_back(v1);
    //  dot_p+=w1*v1;
}
//cout<<dot_p;

//cout<<v;
//cout<<w;
//calculate the dot product of the vectors

//for(int i=0;i<v.size();i++){
//	dot_p+=v[i]*w[i];
//}


//save it to the file dots.txt
// dts<<dot_p;   

}

