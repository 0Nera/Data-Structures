class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None

    def insert_at_beginning(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def delete_element(self, key):
        temp = self.head

        if temp is not None and temp.data == key:
            self.head = temp.next
            temp = None
            return

        prev = None
        while temp is not None and temp.data != key:
            prev = temp
            temp = temp.next

        if temp is None:
            return

        prev.next = temp.next
        temp = None

    def traverse_list(self):
        temp = self.head
        while temp:
            print(temp.data, end=' ')
            temp = temp.next
        print()

if __name__ == "__main__":
    llist = SinglyLinkedList()
    llist.insert_at_beginning(3)
    llist.insert_at_beginning(2)
    llist.insert_at_beginning(1)

    llist.traverse_list()

    llist.delete_element(2)
    llist.traverse_list()