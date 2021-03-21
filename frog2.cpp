#include<bits/stdc++.h>
using namespace std;
 
void print(vector<int> A, int n){
    for(int i=0; i<n; i++){
        cout << A[i] << " ";
    }
    cout << "\n";
}
 
int main(){
    int n, k;
    cin >> n >> k;
    vector <int> A(n);
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
 
    vector <int> dp(n, INT_MAX);
 
    dp[0]=0;
    
    for(int i=1; i<n; i++){
        for(int j=0; j<=k; j++){
            if(i-j>=0){
                dp[i] = min(dp[i], dp[i-j]+abs(A[i]-A[i-j]));
            }
        }
    }
 
    cout << dp[n-1];
 
}
