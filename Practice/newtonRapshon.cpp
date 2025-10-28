#include<bits/stdc++.h>
#define ll long long

using namespace std;

double func(double x) {
    return 4*pow(x,2)+3*x-3;
}

double deriveFunc(double x) {
    return 8*x+3;
}

void newtonRaphson(double x,double tol,ll max_iter) {
     double x1;
     ll it=0;
     cout<<fixed<<setprecision(6);

     while(it<max_iter) {
         x1=x-(func(x)/deriveFunc(x));
         cout<<it+1<<" "<<x<<" "<<x1<<" "<<func(x1)<<"\n";

         if(fabs(x1-x)<tol) {
            break;
        }
        x=x1;
        it++;
     }

     cout<<"\nApproximate root: "<<x1<<" after "<<it<<" iterations.\n";
     cout<<"f(root) : "<<func(x1)<<endl;
}


void newtonrapshon2(double x,double tol,ll max_iter) {
    double x1=x;
    ll it=0;
    cout<<fixed<<setprecision(6);

    while(it<max_iter) {
        double fx=func(x);
        double dfx=deriveFunc(x);

        if(fabs(dfx)<1e-12) {
            cout<<"Derivative ~ 0 at x = "<<x<<". Stop.\n";
            break;
        }

        x1=x-(fx/dfx);

        double denom=fabs(x1);
        if(denom==0.0) denom=1.0;
        double rel_err=fabs(x1-x)/denom;

        cout<<it+1<<" "<<x<<" "<<x1<<" "<<func(x1)<<" rel_err= "<<rel_err<<"\n";

        if(rel_err<=tol || fabs(func(x1))<=tol) {
            x=x1;
            break;
        }

        x=x1;
        it++;
    }

    cout<<"\nApproximate root: "<<x<<" after "<<it<<" iterations.\n";
    cout<<"f(root) : "<<func(x)<<endl;
}

int main() {
    double x;
    cin>>x;
    double tolerance=1e-6;
    ll max_iter=100;
    newtonRaphson(x,tolerance,max_iter);
}