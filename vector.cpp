#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums;  // 空 vector
    
    // 添加元素
    nums.push_back(10);
    nums.push_back(20);
    nums.push_back(30);
    
    // 访问元素
    cout << "第二个元素：" << nums[1] << endl;  // 输出 20
    cout << "最后一个元素：" << nums.back() << endl;  // 输出 30
    
    // 遍历元素（3种方式）
    cout << "遍历元素：";
    // 方式1：普通for循环
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    
    // 方式2：范围for循环（C++11及以上）
    for (int num : nums) {
        // 直接访问每个元素
    }
    
    // 删除尾部元素
    nums.pop_back();
    cout << "\n删除后大小：" << nums.size() << endl;  // 输出 2
    
    return 0;
}
