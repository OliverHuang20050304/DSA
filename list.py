fruits = []
fruits.append('apple')
print(fruits)
fruits.append('orange')
fruits.append('grape')
fruits.append('banana')
print(fruits)

print('The length of fruits is', len(fruits))
pop_fruits = fruits.pop()
print('We pop', pop_fruits)
print('The remaining fruits are', fruits)

print('banana' in fruits)
print('apple' in fruits)

matrix = [
    [1,2,3],
    [4,5,6],
    [7,8,9]
]

print('The matrix is', matrix)
print(matrix[0][1])
print(matrix[2][2])

numbers = [1,2,3,4,5,6,7,8,9]
print(numbers[1:5]) # print 2,3,4,5
print(numbers[6:]) # print 7,8,9
print(numbers[:5]) # print 1,2,3,4,5
print(numbers[::2])
print(numbers[::3])
print(numbers[::-1])
print(numbers[::-2])

squares = [i**2 for i in range(1, 6) if i % 2 == 1]
print('Squares are', squares)

numbers = [5,4,6,3,7,2,8,1,9]
numbers.sort(reverse=True)
print(numbers)

more_numbers = [5,6,4,3,1,7,23,2]
sorted_numbers = sorted(more_numbers)
print(sorted_numbers)
print(more_numbers)

lst1 = [1,2,3]
lst2 = [4,5,6]
print(lst1 + lst2)