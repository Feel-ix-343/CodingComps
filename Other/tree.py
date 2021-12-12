# coding: utf-8
class node:
    data = None
    left = None
    right = None
    
class node:
    def __init__(self, data, left, right):
        self.data = data
        self.left = left
        self.right = right
    
    
n1 = node(5, None, None)
n2 = node(6, None, None)
n3 = node(3, n1, n2)
n4 = node(4, None, None)
root = node(4, n3, n4)
def find_sum(root):
    if root == None:
        return 0
    else:
        return root.data + find_sum(root.left) + find_sum(root.right)
    
print(find_sum(root))
