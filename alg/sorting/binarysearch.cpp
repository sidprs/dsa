#include <iostream>
#include <vector>
#include <tuple>
#include <iomanip>
#include <iomanip>   
using namespace std; 
  




class Solution {
public:
  std::tuple<int, bool> BinarySearch(std::vector<int> &nums, int target){
    
    std::tuple<int, bool> ret;
    ret = make_tuple(0, false);

    int low = 0;
    int high = nums.size()-1;

    while(low <= high){
      int mid = low + (high - low) / 2;
      //int mid = (low + high) / 2;
      if(nums[mid] == target){
        ret = make_tuple(mid, true);
        return ret;
      }
      
      if(nums[mid] < target){
       low = mid + 1;
      }
      else {
        high = mid - 1;
      }


    }
    return {-1, false};
  }

  
};



int main (int argc, char *argv[]) {
 
  std::vector<int> nums = {1,2,3,4,5};
  Solution sol;

  auto [idx, found] = sol.BinarySearch(nums, 2);
  std::cout << std::boolalpha<< "index = " << idx << ", found = " << found << '\n';

  

  return 0;
}
