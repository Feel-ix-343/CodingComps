triangle = [[1], [1, 1]]
# 5 is the fib index
for i in range(2, 5+1):
    triangle.append([1, *[triangle[i-1][j]+triangle[i-1][j-1] for j in range(1, len(triangle[i-1]))], 1])

# The diagonal
print([triangle[i][len(triangle)-1 - i] for i in range(len(triangle)-1, (len(triangle)-len(triangle)%2)//2-1, -1)])
# [1, 4, 3]
