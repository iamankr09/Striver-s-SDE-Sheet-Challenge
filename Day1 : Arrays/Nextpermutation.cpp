class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int n = nums.size();
         if(n<=1) return ;

         int k = n-2;
         
      // Find the correct Position we have to change to get next Permutation
         while(k>=0 && nums[k] >= nums[k+1] ){
               k--;
         }

      //  means this is last permutaion ---> so we reverse the array ---> to get first permutation --> treated as Next Permutation
         if(k == -1){
             reverse(nums.begin() , nums.end());
             return;
         }
     
      // Find just Greater element and swap with the element at kth index
         int end = n-1;
         while(nums[k] >= nums[end]){
               end--;
         }

         swap(nums[k] , nums[end]);
      
     //  now sort the remaining element ahead k
         sort(nums.begin() + (k+1) , nums.end());

         

    }
};
