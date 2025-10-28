#include<bits/stdc++.h>
#define ll long long
#define el '\n'
using namespace std;

double func(double x,double y) {
    return 3*pow(x,2)+2*y;
}

void euler(double x0,double y0,double x,double h) {
    while(x0<x) {
        y0=y0+h*func(x0,y0);
        x0+=h;
    }
    cout<<"Euler : Value of y at x="<<x<<" is "<<y0<<el;
}

void improvedEuler(double x0,double y0,double x,double h) {
    while(x0<x) {
        double k1,k2;
        k1=func(x0,y0);
        k2=func(x0+h,y0+k1*h);
        y0=y0+(h/2)*(k1+k2);
        x0+=h;
    }
    cout<<"Improved Euler : Value of y at x="<<x<<" is "<<y0<<el;
}

int main() {
    double x0,y0,x,h;
    cin>>x0>>y0>>x>>h;
    euler(x0,y0,x,h);
    improvedEuler(x0,y0,x,h);
}