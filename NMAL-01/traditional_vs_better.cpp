#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
using namespace std;

double func(double x) {
    return 4*x*x+3*x-3;
}

void bisection(double a,double b,double t) {
     if(func(a)*func(b)>0) {
        cout<<"No root found in the interval"<<endl;
        return;
    }
     ll cnt=0;
     double error=abs(a-b);
     double c;
     while(error>=t) {
        cnt++;
        c=(a+b)/2;
        if(func(c)==0.0) {
            cout<<"Root is "<<c<<" & iteration number is "<<cnt<<endl;
            return;
        }
        else if(func(a)*func(c)<0) b=c;
        else a=c;
        error=abs(a-b);
     }
     cout<<"Approximate root is "<<c<<" & iteration number is "<<cnt<<endl;
}

void betterApproach(double start,double end,double increase,double t) {
    bool flag=false;
    double a,b;
      for(double i=start;i+increase<=end;i+=increase) {
        if(func(i)*func(i+increase)<0) {
            a=i;
            b=i+increase;
            flag=true;
            break;
        }
      }
      if(flag) {
        bisection(a,b,t);
      }
      else {
        cout<<"No suitable range detected"<<endl;
      }
}

int main() {
    double a,b;
    cin>>a>>b;
    double tolerance;
    cin>>tolerance;
    cout<<"Traditional bisection method : "<<endl;
    bisection(a,b,tolerance);
    cout<<"Better approach : "<<endl;
    betterApproach(-100,100,0.1,tolerance);
}