// dp(ind , wt)  -->   max value that can be obtained given wt capacity of bag and we are at ith index

// SC : O (N*W) + 0(N)
int knapsack(int ind,int wt,vector<int> val,vector<int> weight,vector<vector<int>> &dp){
    if(ind==0){
        if(weight[0]<=wt) return val[0];
        return 0;
    }
    if(dp[ind][wt]!=-1) return dp[ind][wt];
    int take=0;
    if(wt>=weight[ind]) take=val[ind]+knapsack(ind-1,wt-weight[ind],val,weight,dp);
    int notTake=knapsack(ind-1,wt,val,weight,dp);
    return dp[ind][wt]=max(take,notTake);
}

// In the iterative solutions the result can be achieved by lesser weight also ... for simplicity return dp[n-1][maxWeight]
// else we can loop for weight and find the minimum weight which can help in achieving the max value

// SC : 0 (N*W)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<int> prev(maxWeight+1,0),curr(maxWeight+1);
    for(int i=0;i<n;i++){
        for(int j=0;j<=maxWeight;j++){
            if(!i){
                if(j>=weight[0]) curr[j]=value[0];
                else curr[j]=0;
                continue;
            }
            int take=INT_MIN;
            if(j>=weight[i]) take=value[i]+prev[j-weight[i]];
            int notTake=prev[j];
            curr[j]=max(take,notTake);
        }
        prev=curr;
    }
    return prev[maxWeight];
}

// SC : 0(2*W)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<int> prev(maxWeight+1,0),curr(maxWeight+1);
    for(int i=0;i<n;i++){
        for(int j=0;j<=maxWeight;j++){
            if(!i){
                if(j>=weight[0]) curr[j]=value[0];
                else curr[j]=0;
                continue;
            }
            int take=INT_MIN;
            if(j>=weight[i]) take=value[i]+prev[j-weight[i]];
            int notTake=prev[j];
            curr[j]=max(take,notTake);
        }
        prev=curr;
    }
    return prev[maxWeight];
}

// SC : O (W)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<int> prev(maxWeight+1,0);
    for(int i=0;i<n;i++){
        for(int j=maxWeight;j>=0;j--){
            if(!i){
                if(j>=weight[0]) prev[j]=value[0];
                else prev[j]=0;
                continue;
            }
            int take=INT_MIN;
            if(j>=weight[i]) take=value[i]+prev[j-weight[i]];
            int notTake=prev[j];
            prev[j]=max(take,notTake);
        }
    }
    return prev[maxWeight];
}
