#include<iostream>
#include<math.h>
#define PI 3.14159265
#define c 300000000
using namespace std;

//Define class distance with variables
class dist
{
    float x1,x2,y1,y2,z1,z2,t1,t2;
    float x1_n,x2_n,y1_n,y2_n,z1_n,z2_n,t1_n,t2_n;
    float d,d_n;
public:
    //Get the input value
    void get()
{
    cout<<"\n Enter the  value of A(T1,X1,Y1,Z1) and (T2,X2,Y2,Z2):" "\n";
    cout<<"\n Sugguest A(2,1,0,2) and (1,0,1,1):" "\n";
    cin>>t1>>x1>>y1>>z1>>t2>>x2>>y2>>z2;
}
    //Caculate the distance
    void calc(){
    d=sqrt( pow(x1-x2,2)  +   pow(y1-y2,2) + pow(z1-z2,2) + pow(c,2)*pow(t1-t2,2)   );
    cout<<"\n Distance between point A(X1,Y1,Z1,W1) and (X2,Y2,Z2,W2) is: "<<d << "\n\n";

}
    //Lorent Transformation
    void lorentz1(float a){
    	t1_n = cosh(a)*t1 + sinh(a)*z1;
    	t2_n = cosh(a)*t2 + sinh(a)*z2;
    	x1_n = x1;
    	x2_n = x2;
    	y1_n = y1;
    	y2_n = y2;
    	z1_n = sinh(a)*t1+cosh(a)*z1;
    	z2_n = sinh(a)*t2+cosh(a)*z2;
    		cout<<"\n New value of A and B:";
    		cout<<"\nX1:"<<t1_n<<"\nX1:"<<x1_n<<"\nY1:"<<y1_n<<"\nZ1:"<<z1_n<<"\nT2:"<<t2_n<<"\nX2:"<<x2_n<<"\nY2:"<<y2_n<<"\nZ2:"<<z2_n;
    }
    //Lorent Transformation
    void lorentz2(float v){
        double gamma = 1/sqrt(1-pow(v,2)/pow(c,2));
        t1_n = gamma*t1-gamma*v/c*x1;
        t2_n = gamma*t2-gamma*v/c*x2;
        x1_n = -gamma*v/c+gamma*x1;
        x2_n = -gamma*v/c+gamma*x2;
        y1_n = y1;
        y2_n = y2;
        z1_n = z1;
        z2_n = z2;
            cout<<"\n New value of A and B:";
            cout<<"\nX1:"<<t1_n<<"\nX1:"<<x1_n<<"\nY1:"<<y1_n<<"\nZ1:"<<z1_n<<"\nT2:"<<t2_n<<"\nX2:"<<x2_n<<"\nY2:"<<y2_n<<"\nZ2:"<<z2_n;
                }
    void calc_new(){
    d_n=sqrt( pow(x1_n-x2_n,2)  +   pow(y1_n-y2_n,2) + pow(z1_n-z2_n,2) + pow(c,2)*pow(t1_n-t2_n,2)   );
    cout<<"\n Distance between new point A(X1_n,Y1_n,Z1_n,W1_n) and (X2_n,Y2_n,Z2_n,W2_n) is: "<<d_n << "\n\n";
}

    //Check distance invariant
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
    m.calc();
    m.lorentz1(0);
    m.calc_new();
    m.check();
    m.lorentz2(30);
    m.calc_new();




return 0;
}
