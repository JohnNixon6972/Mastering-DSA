# program to compute median of 2 soretd arrays

def median(arr1, arr2):
    if len(arr1) == 1:
        return (arr1[0] + arr2[0]) / 2
    if len(arr1) == 2:
        return (max(arr1[0], arr2[0]) + min(arr1[1], arr2[1])) / 2
    m1 = median(arr1)
    m2 = median(arr2)
    if m1 > m2:
        if len(arr1) % 2 == 0:
            return median(arr1[:len(arr1) / 2 + 1], arr2[len(arr2) / 2 - 1:])
        return median(arr1[:len(arr1) / 2 + 1], arr2[len(arr2) / 2:])
    else:
        if len(arr1) % 2 == 0:
            return median(arr1[len(arr1) / 2 - 1:], arr2[:len(arr2) / 2 + 1])
        return median(arr1[len(arr1) / 2:], arr2[:len(arr2) / 2 + 1])
    
arr1 = [1, 12, 15, 26, 38]
arr2 = [4, 13, 17, 30, 45]

ans = median(arr1, arr2)

