class ArrayStack:
    def __init__(self, max_size):
        self.max_size = max_size  # Stack 的最大容量
        self.stack = [None] * max_size  # 用陣列存儲元素
        self.top = -1  # 頂部指針（-1 表示空堆疊）

    # 壓棧
    def push(self, item):
        if self.is_full():
            raise Exception("Stack Overflow: 堆疊已滿，無法壓棧")
        self.top += 1
        self.stack[self.top] = item

    # 彈棧
    def pop(self):
        if self.is_empty():
            raise Exception("Stack Underflow: 堆疊已空，無法彈棧")
        item = self.stack[self.top]
        self.top -= 1
        return item

    # 查看頂部元素
    def peek(self):
        if self.is_empty():
            raise Exception("Stack is empty: 堆疊已空，無頂部元素")
        return self.stack[self.top]

    # 判空
    def is_empty(self):
        return self.top == -1

    # 判滿
    def is_full(self):
        return self.top == self.max_size - 1

    # 查看堆疊大小
    def size(self):
        return self.top + 1


# 測試程式
if __name__ == "__main__":
    stack = ArrayStack(max_size=5)
    stack.push(10)
    stack.push(20)
    stack.push(30)
    print("當前頂部元素：", stack.peek())  # 輸出：30
    print("彈出元素：", stack.pop())       # 輸出：30
    print("堆疊大小：", stack.size())      # 輸出：2
    print("是否空堆疊：", stack.is_empty())# 輸出：False
