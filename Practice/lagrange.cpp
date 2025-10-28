#include<bits/stdc++.h>
#define ll long long

using namespace std;

void lagrange(vector<double> &x,vector<double> &y,double x0) {
    ll n=x.size();
    double prod,y0=0.0;
    for(ll i=0;i<n;i++) {
       prod=1.0;
       for(ll j=0;j<n;j++) {
       if(i!=j) {
        cout<<"(x - "<<x[j]<<") / ("<<x[i]<<" - "<<x[j]<<" ) * ";
        prod*=(x0-x[j])/(x[i]-x[j]);
       }
    }
    cout<<y[i]<<") \n";
    y0+=prod*y[i];
}   
   cout<<"Interpolated value at "<<x0<<" is "<<y0<<endl;
}


int main() {
    ll n;
    cin>>n;
    vector<double> x(n),y(n);
    for(ll i=0;i<n;i++) cin>>x[i]>>y[i];
    double x0;
    cin>>x0;
    lagrange(x,y,x0);
    return 0;
}