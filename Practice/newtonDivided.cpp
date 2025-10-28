#include<bits/stdc++.h>
#define ll long long

using namespace std;

bool buildTable(vector<double> &x,vector<double> &y,vector<vector<double>> &table) {
     ll n=x.size();
    
     for(ll i=0;i<n;i++) table[i][0]=y[i];

     for(ll j=1;j<n;j++) {
        for(ll i=0;i<n-j;i++) {
          double denome=x[i+j]-x[i];
          if(denome==0.0) {
            cout<<"Duplicate x values \n";
            return false;
          }
          table[i][j]=(table[i+1][j-1]-table[i][j-1])/denome;
        }
     }
     return true;
}

double evaluateVal(double x0,vector<double> &x,vector<vector<double>> &table) {
    ll n=x.size();
    double ans=table[0][0];
    double prod=1.0;
    for(ll j=1;j<n;j++) {
        prod*=(x0-x[j-1]);
        ans+=table[0][j]*prod;
    }
    return ans;
}


int main() {
    ll n;
    cin>>n;
    vector<double> x(n),y(n);
    for(ll i=0;i<n;i++) cin>>x[i]>>y[i];
    double x0;
    cin>>x0;
    vector<vector<double>> table(n,vector<double>(n,0.0));

    if(!buildTable(x,y,table)) return 1;
    cout<<fixed<<setprecision(6);

    cout<<"Divided Difference Table \n";

    for(ll i=0;i<n;i++) {
        for(ll j=0;j<n-i;j++) {
            cout<<table[i][j]<<" ";
        }
        cout<<"\n";
    }

    double ans=evaluateVal(x0,x,table);
    cout<<"\nValue at "<<x0<<" is "<<ans<<"\n";
    return 0;
}