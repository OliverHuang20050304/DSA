#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;

// 检查括号是否匹配的函数
bool isBracketMatching(const string& s) {
    stack<char> bracketStack;
    
    unordered_map<char, char>bracketMapping = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for(char c : s){
        if(c == '(' || c == '[' || c == '{'){
            bracketStack.push(c);
        }else if(c == ')' || c == ']' || c == '}'){
            if(bracketStack.empty()){
                return false;
            }

            char top = bracketStack.top();
            bracketStack.pop();
            if(top != bracketMapping[c]){
                return false;
            }
        }


    }

    return bracketStack.empty();
}

int main() {
    string input;
    cout << "请输入包含括号的字符串: ";
    getline(cin, input);
    
    if (isBracketMatching(input)) {
        cout << "括号匹配正确！" << endl;
    } else {
        cout << "括号匹配错误！" << endl;
    }
    
    return 0;
}
