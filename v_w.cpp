#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <typeinfo>
using namespace std;
int main(){
 //ofstream dts("f_v_w.txt");
  string v_str;
  ifstream data ("v.txt");
  string w_str;
  ifstream dat ("w.txt");
  float v[1];
  float w[1];
  int i=0;
  float dot_p;
  float v_i;
  float w_i; 
  while(getline(data,v_str)){
     getline(dat,w_str);
     stringstream(w_str)>>w_i;
     stringstream(v_str)>>v_i;
     if(i==0){
	     v[i]=v_i;
	     w[i]=w_i;
     }
     else{
	     int vS = sizeof(v)/sizeof(v[0]);
	     float v0=v[0];
	     float v[vS+1];
	     v[0]=v0;
	     v[i]=v_i;
	     float w0=w[0];
	     int wS = sizeof(w)/sizeof(w[0]);
	     float w[wS+1];
	     w[i]=w_i;
	     w[0]=w0;

     }
     
      
}
int vS = sizeof(v)/sizeof(v[0]);
cout<<vS<<" \n\n\n";

for(int i=0;i<vS;i++){
	
	dot_p+=(v[i]*w[i]);
}


//save it to the file dots.txt

   

}


