#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> // 為了 std::greater

int find_kth_largest_with_vector(const std::vector<int>& nums, int k) {
    // 確保 k 是有效的，且不超過總數字的數量
    if (k <= 0 || k > nums.size()) {
        std::cerr << "Error: Invalid value for k." << std::endl;
        return -1; // 或拋出異常
    }

    // 1. 讀取前 k 個數字到一個向量中
    std::vector<int> top_k_elements;
    for (int i = 0; i < k; ++i) {
        top_k_elements.push_back(nums[i]);
    }
    
    // 2. 對這 k 個數字進行降序排序
    // std::sort 預設是升序，所以我們需要傳入一個比較函式
    std::sort(top_k_elements.begin(), top_k_elements.end(), std::greater<int>());

    // 3. 逐一處理剩下的數字
    for (size_t i = k; i < nums.size(); ++i) {
        int current_num = nums[i];
        
        // 如果新數字大於候選名單中最小的那個（第 k 個）
        if (current_num > top_k_elements[k - 1]) {
            // 將新數字替換掉最小的那個
            top_k_elements[k - 1] = current_num;
            
            // 重新對這個大小為 k 的向量進行排序，以維持降序
            std::sort(top_k_elements.begin(), top_k_elements.end(), std::greater<int>());
        }
    }
    
    // 4. 返回第 k 個位置的數字
    return top_k_elements[k - 1];
}

int main() {
    std::vector<int> my_nums = {8, 12, 5, 15, 6, 20, 10, 1, 9, 3};
    int k = 3;
    
    int kth_largest_num = find_kth_largest_with_vector(my_nums, k);
    
    if (kth_largest_num != -1) {
        std::cout << "The " << k << "th largest number is: " << kth_largest_num << std::endl; // 應該輸出 12
    }
    
    return 0;
}