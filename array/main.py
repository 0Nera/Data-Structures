def insert_element(arr, element, position):
    arr.insert(position, element)

def delete_element(arr, position):
    del arr[position]

def traverse_array(arr):
    for element in arr:
        print(element, end=' ')
    print()

if __name__ == "__main__":
    arr = [1, 2, 3, 4, 5]

    traverse_array(arr)

    insert_element(arr, 10, 2)
    traverse_array(arr)

    delete_element(arr, 3)
    traverse_array(arr)