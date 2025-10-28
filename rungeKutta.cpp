#include<bits/stdc++.h>
#define ll long long
#define el '\n'
using namespace std;

double func(double x,double y) {
    return 3*pow(x,2)+2*y;
}

void rk2(double x0,double y0,double x,double h) {
    while(x0<x) {
        double k1,k2;
        k1=func(x0,y0);
        k2=func(x0+h,y0+k1*h);
        y0=y0+(h/2)*(k1+k2);
        x0+=h;
    }
    cout<<"RK2 : Value of y at x="<<x<<" is "<<y0<<el;
}

void rk3(double x0,double y0,double x,double h) {
    while(x0<x) {
        double k1,k2,k3;
        k1=func(x0,y0);
        k2=func(x0+.5*h,y0+.5*h*k1);
        k3=func(x0+h,y0-k1*h+2*k2*h);
        y0=y0+(h/6.0)*(k1+4*k2+k3);
        x0+=h;
    }
    cout<<"RK3 : Value of y at x="<<x<<" is "<<y0<<el;
}

void rk4(double x0,double y0,double x,double h) {
    while(x0<x) {
        double k1,k2,k3,k4;
        k1=func(x0,y0);
        k2=func(x0+0.5*h,y0+0.5*h*k1);
        k3=func(x0+0.5*h,y0+0.5*h*k2);
        k4=func(x0+h,y0+h*k3);
        y0=y0+(h/6.0)*(k1+2*k2+2*k3+k4);
        x0+=h;
    }
    cout<<"RK4 : Value of y at x="<<x<<" is "<<y0<<el;
}

int main() {
    double x0,y0,x,h;
    cin>>x0>>y0>>x>>h;
    rk2(x0,y0,x,h);
    rk3(x0,y0,x,h);
    rk4(x0,y0,x,h);
}