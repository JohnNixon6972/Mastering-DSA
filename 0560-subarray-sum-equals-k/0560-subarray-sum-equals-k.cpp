class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefix_sum_count;
        prefix_sum_count[0] = 1;

        int prefix_sum = 0;
        int result = 0;

        for(int num:nums){
            prefix_sum += num;

            if(prefix_sum_count.find(prefix_sum - k) != prefix_sum_count.end()){
                result += prefix_sum_count[prefix_sum - k];

            }

            prefix_sum_count[prefix_sum]++;
        }

        return result;


    }
};