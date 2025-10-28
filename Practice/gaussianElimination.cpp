#include<bits/stdc++.h>
#define ll long long
#define el '\n'
using namespace std;

int main() {
    ll n;
    cin>>n;
    double arr[n+2][n+2];
    double ans[n+2];
    
    for(ll i=1;i<=n;i++) {
        for(ll j=1;j<=n+1;j++) {
            cin>>arr[i][j];
        }
    }
    for(ll j=1;j<=n;j++) {
        for(ll i=1;i<=n;i++) {
            if(i!=j) {
                double multiplier=arr[i][j]/arr[j][j];
                for(ll k=1;k<=n+1;k++) {
                    arr[i][k]-=multiplier*arr[j][k];
                }
            }
        }
    }
    cout<<"Simplified Matrix : "<<el;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n+1;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<el;
    }
    cout<<"Ans is : "<<el;
    for(ll i=1;i<=n;i++){
       ans[i]=arr[i][n+1]/arr[i][i];
       cout<<"X" <<i<<" = "<<ans[i]<<'\n';
    }
}