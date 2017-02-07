#include<iostream>
#include<math.h>
#define PI 3.14159265
using namespace std;

//Define class distance with variables
class dist
{
    float x1,x2,y1,y2,z1,z2,w1=1,w2=1;
    float x1_n,x2_n,y1_n,y2_n,z1_n,z2_n,w1_n=1,w2_n=1;
    float tx,ty,tz;
    float d,d_n;
public:
    //Get the input value
    void get()
{
    cout<<"\n Enter the  value of A(X1,Y1,Z1,W1) and (X2,Y2,Z2,W2):" "\n";
    cin>>x1>>y1>>z1>>x2>>y2>>z2;
    //Get the value of translate
    cout<<"\n Enter the  value of tx,ty,tz: \n";
    cin>>tx>>ty>>tz;

}
    //Caculate the distance
    void calc(){
    d=sqrt( pow(x1-x2,2)  +   pow(y1-y2,2) + pow(z1-z2,2) + pow(w1-w2,2)   );
    cout<<"\n Distance between point A(X1,Y1,Z1,W1) and (X2,Y2,Z2,W2) is: "<<d << "\n\n";
}
//Translation transformation
    void trans(){
    x1_n = x1 + tx;
    x2_n = x2 + tx;
    y1_n = y1 + ty;
    y2_n = y2 + ty;
    z1_n = z1 + tz;
    z2_n = z2 + tz;
    w1_n = 1;
    w2_n = 1;
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
//Check if distance invariant
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
    m.trans();
    m.calc_new();
    m.check();
    m.rotate(PI/2);
    m.calc_new();
    m.check();



return 0;
}
