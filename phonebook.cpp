#include <iostream>
#include <vector>
#include <string>

// 定義一個表示聯絡人的結構
struct Contact {
    std::string name;
    std::string phone_number;
};

// 儲存所有聯絡人的向量
std::vector<Contact> phonebook;

// 函式：新增聯絡人
void add_contact() {
    Contact new_contact;
    std::cout << "請輸入聯絡人姓名：";
    std::cin >> new_contact.name;
    std::cout << "請輸入聯絡人電話：";
    std::cin >> new_contact.phone_number;
    phonebook.push_back(new_contact);
    std::cout << "聯絡人已成功新增！\n";
}

// 函式：顯示所有聯絡人
void view_contacts() {
    if (phonebook.empty()) {
        std::cout << "電話簿是空的。\n";
        return;
    }
    std::cout << "--- 所有聯絡人 ---\n";
    for (const auto& contact : phonebook) {
        std::cout << "姓名：" << contact.name << ", 電話：" << contact.phone_number << "\n";
    }
    std::cout << "--------------------\n";
}

// 函式：搜尋聯絡人
void search_contact() {
    std::string search_name;
    std::cout << "請輸入要搜尋的姓名：";
    std::cin >> search_name;
    
    bool found = false;
    for (const auto& contact : phonebook) {
        if (contact.name == search_name) {
            std::cout << "找到聯絡人！\n";
            std::cout << "姓名：" << contact.name << ", 電話：" << contact.phone_number << "\n";
            found = true;
            break; // 找到後就結束迴圈
        }
    }
    if (!found) {
        std::cout << "找不到此聯絡人。\n";
    }
}

// 主函式
int main() {
    int choice;
    while (true) {
        std::cout << "\n--- 電話簿選單 ---\n";
        std::cout << "1. 新增聯絡人\n";
        std::cout << "2. 顯示所有聯絡人\n";
        std::cout << "3. 搜尋聯絡人\n";
        std::cout << "4. 離開\n";
        std::cout << "請輸入你的選擇：";
        std::cin >> choice;

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                view_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                std::cout << "程式結束。\n";
                return 0;
            default:
                std::cout << "無效的選擇，請重新輸入。\n";
        }
    }
    return 0;
}