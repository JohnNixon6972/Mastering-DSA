class Solution {
public:
    bool isValid(vector<int>& nums, int k, int mid) {
        int subarrayCount = 1, currentSum = 0;
        for (int num : nums) {
            if (currentSum + num > mid) {
           
                subarrayCount++;
                currentSum = num;
                if (subarrayCount > k) return false;
            } else {
                currentSum += num;
            }
        }
        return true;
    }
    

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end()); 
        int high = accumulate(nums.begin(), nums.end(), 0); 
        int result = high; 

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValid(nums, k, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1; 
            }
        }
        return result;
    }
};