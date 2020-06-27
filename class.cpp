#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class BYU_student{
	int ID=10412;
	float g1;
	float g2;
        float g3;
	public:
	string major="Chemial Engineering";
	void gradebook(float x, float y, float z){
		g1=x;
		g2=y;
		g3=z;
	}
	float GPA(void){
             float gpa=(g1+g2+g3)/3;
	     return gpa;
	}
};	
int main(){
	BYU_student Ian;
//	cout<<Ian.ID;
	Ian.gradebook(4.0,4.0,4.0);
       float gpa=Ian.GPA();
	cout<<gpa;
	cout<<Ian.major;
}



