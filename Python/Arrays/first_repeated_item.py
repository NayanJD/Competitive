from typing import TypeVar, Generic, List

T = TypeVar('T')

def getFirstRepeatedItem(arr: list[T]) -> T:
    visited = set()

    for item in arr:
        if item in visited:
            return item
        
        visited.add(item)

    raise ValueError("Array does not contain any repeated value")

if __name__ == '__main__':
    t1 = [1,2,3,2,1]

    try:
        print(getFirstRepeatedItem(t1))
    except Exception as e:
        print(e)