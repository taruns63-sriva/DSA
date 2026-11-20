class Solution {
 public:
  int maxSelectedElements(vector<int>& nums) {
    ranges::sort(nums);
    int A = 1;
    for (int i = 1, length = 1, non_modified_chain = 1; i < nums.size(); i++) {
      if (nums[i] == nums[i - 1]) {
        if (non_modified_chain > 0) {
          length++;
          non_modified_chain = 0;
        }
      } else if (nums[i] == nums[i - 1] + 1) {
        length++;
        if (non_modified_chain > 0) non_modified_chain++;
      } else if (nums[i] == nums[i - 1] + 2) {
        if (non_modified_chain == 0) {
          length++;
          non_modified_chain = 1;
        } else {
          length = 1 + non_modified_chain;
          non_modified_chain = 1;
        }
      } else {
        length = 1;
        non_modified_chain = 1;
      }
      A = max(A, length);
    }
    return A;
  }
};