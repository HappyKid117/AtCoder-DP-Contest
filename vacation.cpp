#include<bits/stdc++.h>
using namespace std;
 
void print(vector<int> A, int n){
    for(int i=0; i<n; i++){
        cout << A[i] << " ";
    }
    cout << "\n";
}
 
int main(){
    int n;
    cin >> n;
    vector<vector<int>> A(n, vector<int>(3));
    for(int i=0; i<n; i++){
        cin >> A[i][0] >> A[i][1] >> A[i][2];
    }
 
    vector <vector<int>> dp(3, vector<int>(n, 0));
    dp[0][0] = A[0][0];
    dp[1][0] = A[0][1];
    dp[2][0] = A[0][2];
 
    for(int j=1; j<n; j++){
        for(int i=0; i<3; i++){
            if(i==0){
                dp[i][j] = A[j][0] + max(dp[1][j-1], dp[2][j-1]);
            }
            if(i==1){
                dp[i][j] = A[j][1] + max(dp[0][j-1], dp[2][j-1]);
            }
            if(i==2){
                dp[i][j] = A[j][2] + max(dp[1][j-1], dp[0][j-1]);
            }
        }
    }
 
    int ans = max({dp[0][n-1], dp[1][n-1], dp[2][n-1]});
 
    cout << ans;
}
