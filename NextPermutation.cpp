class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int n = nums.size();
         if(n<=1) return ;

         int k = n-2;
         
         while(k>=0 && nums[k] >= nums[k+1] ){
               k--;
         }

         if(k == -1){
             reverse(nums.begin() , nums.end());
             return;
         }

         int end = n-1;
         while(nums[k] >= nums[end]){
               end--;
         }

         swap(nums[k] , nums[end]);
         sort(nums.begin() + (k+1) , nums.end());

         

    }
};
