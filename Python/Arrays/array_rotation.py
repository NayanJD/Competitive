T=int(input())

def rotate(arr,d):
    temp=arr[len(arr)-d:len(arr)]

    indx=0
    for i in range(0,len(arr)-d):
        arr[len(arr)-i-1]=arr[len(arr)-d-1-i]
    #print(arr)
    #print()
    for i in range(0,d):
        arr[i]=temp[i]
    

for i in range(T):
    N=int(input())
    
    arr=list(map(int,input().strip().split(' ')))
    
    count=1
 

    while len(arr)!=1:
        #print(len(arr))
        rotate(arr,1)
        last=len(arr)-count;
        #print(last)
        if(len(arr)<count):
            arr=arr[1:len(arr)]
        else:
            arr=arr[0:last] + arr[last+1:len(arr)]
        
        count=count+1
        #print(arr)
    # for j in range(len(arr)):
    #     rotate(arr,1)
    #     print(arr)

    print(arr[0])