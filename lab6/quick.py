
def partitition(list,low,high):
    i = low - 1
    pivot = high
    for j in range(low,high):
        if list[j] < list[pivot]:
            i += 1
            save = list[j]
            list[j] = list[i]
            list[i] = save
    save2 = list[i + 1]
    list[i+1] = list[pivot]
    list[pivot] = save2
    return i + 1            

def qsort(list,low,high):
    if low < high:
        pivot = partitition(list,low,high)
        qsort(list,low,pivot-1)
        qsort(list,pivot+1,high)


l = int(input().split())
qsort(l,0,len(l)-1)

print(l)
 
           