#include<bits/stdc++.h>
#define ll long long

using namespace std;

double func(double x) {
    return 4*pow(x,2)+3*x-3;
}

void falsi(double a,double b,double t,ll max_iter) {
    if(func(a)*func(b)>=0) {
        cout<<"No solution in this interval \n";
        return;
    }
    double error=fabs(a-b);
    double c;
    ll it=0;
    cout<<fixed<<setprecision(6);
    while(error>=t && it<max_iter) {
        c=(a*func(b)-b*func(a))/(func(b)-func(a));
        double fc=func(c);
        cout<<"Iteration : "<<it+1<<" ,a: " <<a<<" ,b: "<<b<<" ,c: "<<c<<" ,fc: "<<fc<<"\n";
        if(fabs(fc)<t) {
            break;
        }
        if(func(a)*func(c)<0) b=c;
        else a=c;
        error=fabs(b-a);
        it++;
    }
    if(it>=max_iter) cout<<"Stopped after reaching maximum iterations "<<max_iter<<" \n";

    cout<<"Approximate root after "<<it<<" iterations is "<<c<<"\n";
}

int main() {
    double x,y;
    cin>>x>>y;
    double tolerance=1e-6;
    ll max_iter=100;
    falsi(x,y,tolerance,max_iter);
}