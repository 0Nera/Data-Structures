class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    def insert_at_beginning(self, data):
        new_node = Node(data)
        new_node.next = self.head

        if self.head is not None:
            self.head.prev = new_node

        self.head = new_node

    def delete_element(self, key):
        temp = self.head

        if temp is not None and temp.data == key:
            self.head = temp.next
            if self.head is not None:
                self.head.prev = None
            temp = None
            return

        while temp is not None and temp.data != key:
            temp = temp.next

        if temp is None:
            return

        if temp.next is not None:
            temp.next.prev = temp.prev

        if temp.prev is not None:
            temp.prev.next = temp.next

        temp = None

    def traverse_list(self):
        temp = self.head
        while temp:
            print(temp.data, end=' ')
            temp = temp.next
        print()

if __name__ == "__main__":
    llist = DoublyLinkedList()
    llist.insert_at_beginning(3)
    llist.insert_at_beginning(2)
    llist.insert_at_beginning(1)

    llist.traverse_list()

    llist.delete_element(2)
    llist.traverse_list()