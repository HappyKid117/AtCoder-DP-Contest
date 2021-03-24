#include<bits/stdc++.h>
using namespace std;
 
void print(vector<long long int> A, int n){
    for(int i=0; i<n; i++){
        cout << A[i] << " ";
    }
    cout << "\n";
}
 
int main(){
    long long int n, w;
    cin >> n >> w;
    vector<vector<long long int>> A(n+1, vector<long long int>(2));
    A[0][0] = 0; A[0][1] = 0;
    for(int i=1; i<=n; i++){
        cin >> A[i][0] >> A[i][1];
    }
 
    //for(int i=0; i<=n; i++){
        //print(A[i], 2);
    //}
 
    vector<vector<long long int>> dp(n+1, vector<long long int>(w+1,0));
 
    for(int i=1; i<=n; i++){
        for(int j=0; j<=w; j++){
            if(j-A[i][0]>=0){
                dp[i][j] = max({dp[i-1][j], dp[i][j], dp[i-1][j-A[i][0]]+A[i][1]});
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j]);
            }
        }
    }
 
    //for(int i=0; i<=n; i++){
        //print(dp[i], w+1);
    //}
 
    cout << dp[n][w];
}
