#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // 為了 std::greater


int findKthLargeNumber(std::vector<int> nums, int k){
    // 先看看k合不合理
    if(k <= 0 || k > nums.size()){
        return -1;
    }

    std::vector<int> topKthElement = {};
    for(int i = 0;i < k; ++i){
        topKthElement.push_back(nums[i]);
    }

    sort(topKthElement.begin(), topKthElement.end(), std::greater<int>());

    for(int i = k;i < nums.size(); ++i){
        int thisNum = nums[i];

        if(thisNum > topKthElement[k-1]){
            topKthElement[k-1] = thisNum;
            sort(topKthElement.begin(), topKthElement.end(), std::greater<int>());
        } 
    }
    return topKthElement[k-1];
}

int main(){
    std::vector<int> arr = {1,2,3,4,5,6,7,8,9,10};
    int res = findKthLargeNumber(arr, 5);

    if(res != -1){
        std::cout << res << std::endl;
        // 應該輸出6
    } 

    return 0;
}