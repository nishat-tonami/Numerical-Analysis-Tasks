#include<bits/stdc++.h>
#define ll long long
using namespace std;

double func(double x) {
    return 4*x*x+3*x-3;
}

void bisection(double a,double b,double t) {
     if(func(a)*func(b)>0) {
        cout<<"No root found in the interval"<<endl;
        return;
    }
     double error=abs(a-b);
     double c;
     while(error>=t) {
        c=(a+b)/2;
        if(func(c)==0.0) {
            cout<<"Root is "<<c<<endl;
            return;
        }
        else if(func(a)*func(c)<0) b=c;
        else a=c;
        error=abs(a-b);
     }
     cout<<"Approximate root is "<<c<<endl;
}

int main() {
    double a,b;
    cin>>a>>b;
    double tolerance=0.05;
    bisection(a,b,tolerance);
}