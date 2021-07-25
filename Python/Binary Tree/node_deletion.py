from collections import deque
def deleteDeepest(root,d_node):
    q = []
    q.append(root)
    while(len(q)):
        temp = q.pop(0)
        if temp is d_node:
            temp = None
            return
        if temp.right:
            if temp.right is d_node:
                temp.right = None
                return
            else:
                q.append(temp.right)
        if temp.left:
            if temp.left is d_node:
                temp.left = None
                return
            else:
                q.append(temp.left)
                
def deletionBT(root, key):
    '''
    root: root of tree
    key:  key to be deleted
    return: root after deleting 
    '''
    if root == None :
        return None
    if root.left == None and root.right == None:
        if root.key == key :
            return None
        else :
            return root
    key_node = None
    q = []
    q.append(root)
    while(len(q)):
        temp = q.pop(0)
        if temp.data == key:
            key_node = temp
        if temp.left:
            q.append(temp.left)
        if temp.right:
            q.append(temp.right)
    if key_node :
        x = temp.data
        deleteDeepest(root,temp)
        key_node.data = x
    return root

class Node:
    def __init__(self, data):
        self.data = data
        self.right = None
        self.left = None 

def inorder(root):
    if not root:
        return 
    
    inorder(root.left)
    print(root.data, end=' ')
    inorder(root.right)


    #      1
    #    /   \
    #   4     7  <------ Delete this node
    #  /  \
    # 5    6   
if __name__ == '__main__':
    root = Node(1)

    root.left = Node(4)
    root.right = Node(7)
    
    root.left.left = Node(5)
    root.left.right = Node(6)

    deletionBT(root, 7)
    inorder(root)

