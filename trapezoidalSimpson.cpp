#include<bits/stdc++.h>
#define ll long long
#define dbl double 
#define el '\n'
using namespace std;

double func(double x) {
    return 1/(1+pow(x,2));
}

void trapezoidal(double lo,double hi,ll n) {
      double h=(hi-lo)/n;
      double ans=(func(hi)+func(lo))/2;
      for(ll i=1;i<n;i++) {
        ans+=func(lo+i*h);
      }
      ans*=h;
      cout<<"Trapezoidal ans : "<<ans<<el;
}

void simpson13 (double lo,double hi,ll n) {
      double h=(hi-lo)/n;
      double ans=func(lo)+func(hi);
      for(ll i=1;i<n;i++) {
        if(i%2==0) {
            ans+=2*func(lo+i*h);
        }
        else ans+=4*func(lo+i*h);
    }
      ans*=(h/3);
      cout<<"Simpson 1/3 ans : "<<ans<<el;
}

void simpson38(double lo,double hi,ll n) {
    double h=(hi-lo)/n;
    double ans=func(lo)+func(hi);
    for(ll i=1;i<n;i++) {
        if(i%3==0) {
            ans+=2*func(lo+i*h);
        }
        else ans+=3*func(lo+i*h);
    }
    ans*=(3*h/8);
    cout<<"Simpson 3/8 ans : "<<ans<<el;
}

int main() {
   double lo,hi;
   ll n;
   cin>>lo>>hi>>n;
   trapezoidal(lo,hi,n);
   simpson13(lo,hi,n);
   simpson38(lo,hi,n);
}