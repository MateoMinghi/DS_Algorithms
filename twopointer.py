arr = [6, 5, 3, "r", 5, 8, "r", 7]

def twopointer(arr):
    left = 0
    right = len(arr) - 1
    
    while left < right:
        if isinstance(arr[left], int):
            left += 1
        elif arr[right] == "r":
            right -= 1
        else:
            arr[left], arr[right] = arr[right], arr[left]
            left += 1
            right -= 1
    
    return arr

print(twopointer(arr))
