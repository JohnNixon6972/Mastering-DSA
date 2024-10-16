class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        // adding the endpoints  0 and n to the list of cuts
        // these represt the boundaries of the stick
        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(),cuts.end());

        // totla number of cuts - including the boundaries 
        int m = cuts.size();

        // DP table, dp[i][j] will store the minimum cost to cut the stick
        // between cuts[i] and cuts[j]
        vector<vector<int>> dp(m, vector<int>(m,0));

        // fill this dp for increasing lengths of substick
        // len represnts the distance between i and j in terms of cuts (not the stick len)
        for(int len = 2; len < m;len++){
            // i is the starting point of the segment
            for(int i = 0; i < m - len;i++){
                // j is the ending point of the segment
                int j = i + len;

                // overestimating the value initially to minimize
                dp[i][j] = INT_MAX;

                // try every cut k between cuts[i] and cuts[j]
                // this will help to split the stick optimally
                for(int k = i + 1;k<j;k++){

                    // cost of making the cut at cust[k] is the length of the current stick segment
                    // plus the cost of cutting the left and right segments
                    int cost = cuts[j] - cuts[i] + dp[i][k] + dp[k][j];

                    // take the minimum cost for this segment
                    dp[i][j] = min(cost, dp[i][j]);
                }
            }
        }

        // the final res is stored in dp[0][m-1], which represents the minimum cost 
        // to cut the stick from 0 to n
        return dp[0][m-1];
    }
};