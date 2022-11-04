//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{

    public:
    static bool cmp(vector<int>v1,vector<int>v2){
        return v1[1] > v2[1];
    }
    bool canPlace(vector<int>v1 , vector<int>v2){
        if(v1[1]<v2[1] && v1[2]<v2[2]){
            return true;
        }
        return false;
    }
    int maxHeight(int height[],int width[],int length[],int n)
    {
        vector<vector<int>>v(3*n);
        int k =0;
        for(int i = 0 ; i < n ; i++){
           v[k].push_back(height[i]);
           v[k].push_back(max(width[i],length[i]));
           v[k].push_back(min(width[i],length[i]));
           
           k=k+1;
           v[k].push_back(width[i]);
           v[k].push_back(max(height[i],length[i]));
           v[k].push_back(min(height[i],length[i]));
           
           k=k+1;
           
           v[k].push_back(length[i]);
           v[k].push_back(max(height[i],width[i]));
           v[k].push_back(min(height[i],width[i]));
           
           k=k+1;
        }
        
        sort(v.begin(),v.end(),cmp);
        vector<int>dp(3*n,0);
        for(int i= 0 ; i < 3*n ; i++){
            dp[i] = v[i][0];
        }
        for(int i = 1 ; i < n*3 ; i++){
            for(int j = 0 ; j < i ; j++){
                if(canPlace(v[i],v[j])){
                    dp[i] = max(dp[i], dp[j] + v[i][0]);
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 0 ; i<3*n ; i++){
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int n;
        cin>>n;
        
    
        int A[105],B[105],C[105];
        for(int i = 0; i < n; i++)cin >> A[i];
        for(int j = 0; j < n; j++)cin >> B[j];
        for(int k = 0; k < n; k++)cin >> C[k];
        Solution ob;
        cout<<ob.maxHeight(A,B,C,n)<<endl;
    }
	
	return 0;
}
	
// } Driver Code Ends
