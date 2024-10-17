class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        if(rows == 0) return false;
        int cols = matrix[0].size();

        int left = 0;
        int right = rows * cols - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            int mid_ele = matrix[mid/cols][mid%cols];

            if(mid_ele == target){
                return true;
            }else if (mid_ele < target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return false;
        
    }
};