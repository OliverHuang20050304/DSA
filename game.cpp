#include <iostream>
#include <string>
#include <vector>
#include <map>

// 定義物品結構
struct Item {
    std::string name;
    std::string description;
};

// 定義房間結構，包含描述、可用的物品和通往其他房間的出口
struct Room {
    std::string name;
    std::string description;
    std::vector<Item> items;
    std::map<std::string, std::string> exits; // 方向 -> 房間名稱
};

// 遊戲狀態變數
std::map<std::string, Room> world_map;
std::string current_room = "大廳";
std::vector<Item> player_inventory;

// 初始化遊戲地圖
void init_map() {
    // 建立房間
    Room lobby;
    lobby.name = "大廳";
    lobby.description = "你站在一個寬敞的大廳裡。這裡有幾扇門。";
    lobby.exits["北"] = "圖書館";
    lobby.exits["東"] = "廚房";
    
    Room library;
    library.name = "圖書館";
    library.description = "你身處一個充滿書架的安靜圖書館。";
    library.items.push_back({"古老的鑰匙", "一把生鏽的古老鑰匙。"});
    library.exits["南"] = "大廳";

    Room kitchen;
    kitchen.name = "廚房";
    kitchen.description = "這是一個充滿食物香味的廚房，角落有一口舊箱子。";
    kitchen.items.push_back({"黃金", "閃亮的黃金。"});
    kitchen.exits["西"] = "大廳";
    
    // 將房間加入地圖
    world_map["大廳"] = lobby;
    world_map["圖書館"] = library;
    world_map["廚房"] = kitchen;
}

// 處理玩家指令
void process_command(const std::string& command, const std::string& argument) {
    if (command == "移動" || command == "走") {
        if (world_map[current_room].exits.count(argument)) {
            current_room = world_map[current_room].exits[argument];
            std::cout << "你向" << argument << "移動了。\n";
        } else {
            std::cout << "你不能向那個方向移動。\n";
        }
    } else if (command == "查看" || command == "環顧") {
        std::cout << world_map[current_room].description << "\n";
        if (!world_map[current_room].items.empty()) {
            std::cout << "你看到這裡有：\n";
            for (const auto& item : world_map[current_room].items) {
                std::cout << "- " << item.name << "\n";
            }
        }
        std::cout << "這裡可以往：";
        for (const auto& exit : world_map[current_room].exits) {
            std::cout << exit.first << " ";
        }
        std::cout << "方向移動。\n";
    } else if (command == "撿起") {
        bool found = false;
        for (size_t i = 0; i < world_map[current_room].items.size(); ++i) {
            if (world_map[current_room].items[i].name == argument) {
                player_inventory.push_back(world_map[current_room].items[i]);
                std::cout << "你撿起了 " << argument << "。\n";
                // 從房間移除物品
                world_map[current_room].items.erase(world_map[current_room].items.begin() + i);
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << "這裡沒有 '" << argument << "'。\n";
        }
    } else if (command == "背包") {
        if (player_inventory.empty()) {
            std::cout << "你的背包是空的。\n";
        } else {
            std::cout << "你的背包裡有：\n";
            for (const auto& item : player_inventory) {
                std::cout << "- " << item.name << "：" << item.description << "\n";
            }
        }
    } else {
        std::cout << "我不懂你的指令。你可以試試 '移動 北'、'查看'、'撿起 古老的鑰匙'。\n";
    }
}

// 主函式
int main() {
    init_map();
    std::cout << "歡迎來到文字冒險遊戲！輸入 '查看' 開始你的旅程。\n";

    std::string input;
    while (true) {
        std::cout << "\n> ";
        std::cin >> input;
        
        std::string command = input;
        std::string argument = "";
        
        // 檢查是否有第二個詞（參數）
        if (std::cin.peek() != '\n' && std::cin.peek() != EOF) {
            std::cin >> argument;
        }

        process_command(command, argument);
        
        // 檢查遊戲是否結束
        if (current_room == "大廳" && !player_inventory.empty()) {
            bool has_treasure = false;
            for(const auto& item : player_inventory) {
                if (item.name == "黃金") {
                    has_treasure = true;
                    break;
                }
            }
            if (has_treasure) {
                std::cout << "你帶著黃金回到了大廳！恭喜你，你完成了遊戲！\n";
                break;
            }
        }
    }

    return 0;
}