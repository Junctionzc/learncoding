def bubble_sort(array):
    for i in range(0, len(array) - 1):
        for j in range(0, len(array) - i - 1):
            if array[j] > array[j + 1]:
                tmp = array[j]
                array[j] = array[j + 1]
                array[j + 1] = tmp
                
if __name__ == '__main__':
    array = [54, 4, 1, 98, 3, 68, 23, 0]
    print array
    bubble_sort(array)
    print array