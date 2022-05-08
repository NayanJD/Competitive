from collections import deque
from unicodedata import name

class Solution:
    #Function to return the level order traversal of a tree.
    def levelOrder(self,root ):
        # Code here
        queue = deque([])
        queue.append(root)
        
        level_list = []
        while len(queue) != 0:
            curr = queue.popleft()
            
            if not curr:
                continue
            
            level_list.append(curr.data)
            
            queue.append(curr.left)
            queue.append(curr.right)
            
                
        return level_list

