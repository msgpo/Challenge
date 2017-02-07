#include<iostream>
#include<math.h>
#define PI 3.14159265
using namespace std;

//Define class distance with variables
class dist
{
    float x1,x2,y1,y2,z1,z2,w1,w2;
    float x1_n,x2_n,y1_n,y2_n,z1_n,z2_n,w1_n,w2_n;
    float r1,psi1,theta1,phi1,r2,psi2,theta2,phi2;
    float d,d_n;
public:
    //Get the input value
    void get()
{
    cout<<"\n Enter the  value of A(r1,psi1,theta1,phi1) and (r2,psi2,theta2,phi2):" "\n";
    cout<<"\n Suggest A(1,0,90,90) and (1,90,0,90):" "\n";
    cin>>r1>>psi1>>theta1>>phi1>>r2>>psi2>>theta2>>phi2;

}
    //Convert to Euclidean using Cartesian coordinator 
    void convert(){
    	x1=r1*cos(psi1*PI/180);
    	x2=r2*cos(psi2*PI/180);
    	y1=r1*sin(psi1*PI/180)*cos(theta1*PI/180);
    	y2=r2*sin(psi2*PI/180)*cos(theta2*PI/180);
    	z1=r1*sin(psi1*PI/180)*sin(theta1*PI/180)*cos(phi1*PI/180);
    	z2=r2*sin(psi2*PI/180)*sin(theta2*PI/180)*cos(phi2*PI/180);
    	w1=r1*sin(psi1*PI/180)*sin(theta1*PI/180)*sin(phi1*PI/180);
    	w2=r2*sin(psi2*PI/180)*sin(theta2*PI/180)*sin(phi2*PI/180);
    	cout<<"\n New value of A and B:";
    	cout<<"\nX1:"<<x1<<"\nY1:"<<y1<<"\nZ1:"<<z1<<"\nW1:"<<w1<<"\nX2:"<<x2<<"\nY2:"<<y2<<"\nZ2:"<<z2<<"\nW2:"<<w2;
    }
    //Caculate the distance
    void calc(){
    d=sqrt( pow(x1-x2,2)  +   pow(y1-y2,2) + pow(z1-z2,2) + pow(w1-w2,2)   );
    cout<<"\n Distance between point A(X1,Y1,Z1,W1) and (X2,Y2,Z2,W2) is: "<<d << "\n\n";
}
    //Orthogonal transformation
    void ortho_trans(){
    	 x1_n = x1;
    	 x2_n = x2;
    	 y1_n = 1/sqrt(2)*y1-1/sqrt(2)*z1;
    	 y2_n = 1/sqrt(2)*y2-1/sqrt(2)*z2;
    	 z1_n = 1/sqrt(2)*y1+1/sqrt(2)*z1;
    	 z2_n = 1/sqrt(2)*y2+1/sqrt(2)*z2;
    	 w1_n = w1;
    	 w2_n = w2;
    	 cout<<"\n New value of A and B:";
    	 cout<<"\nX1:"<<x1_n<<"\nY1:"<<y1_n<<"\nZ1:"<<z1_n<<"\nW1:"<<w1_n<<"\nX2:"<<x2_n<<"\nY2:"<<y2_n<<"\nZ2:"<<z2_n<<"\nW2:"<<w2_n;
    }
    void calc_new(){
    	d_n=sqrt( pow(x1_n-x2_n,2)  +   pow(y1_n-y2_n,2) + pow(z1_n-z2_n,2) + pow(w1_n-w2_n,2)   );
    	cout<<"\n Distance between new point A(X1_n,Y1_n,Z1_n,W1_n) and (X2_n,Y2_n,Z2_n,W2_n) is: "<<d_n << "\n\n";
}
    //Rotation transformation
    void rotate(float a){
    	x1_n = x1*cos(a) - y1*sin(a);
    	x2_n = x2*cos(a) - y2*sin(a);
      y1_n = x1*sin(a) + y1*cos(a);
      y2_n = x2*sin(a) + y2*cos(a);
      z1_n = z1;
      z2_n = z2;
      w1_n = 1;
      w2_n = 1;
      cout<<"\n New value of A and B:";
      cout<<"\nX1:"<<x1_n<<"\nY1:"<<y1_n<<"\nZ1:"<<z1_n<<"\nW1:"<<w1_n<<"\nX2:"<<x2_n<<"\nY2:"<<y2_n<<"\nZ2:"<<z2_n<<"\nW2:"<<w2_n;
            }

    void check(){
    	if (d==d_n)
    		cout<<"True";
    	else
    		cout<<"False";
    }
};


int main()
{

    dist m;
    m.get();
    m.convert();
    m.calc();
    m.ortho_trans();
    m.calc_new();
    m.check();
    m.rotate(PI/2);
    m.calc_new();
    m.check();



return 0;
}
