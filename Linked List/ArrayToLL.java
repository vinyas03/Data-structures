// Define a class for a Node in the linked list
class Node {
    int data; // Data stored in the node
    Node next; // Pointer to the next node

    // Constructor to initialize a node with a value
    Node(int value) {
        data = value; // Set the data of the node
        next = null; // Initialize next pointer to null
    }

    // Constructor to initialize a node with a value and a pointer to the next node
    Node(int value, Node nextNode) {
        data = value; // Set the data of the node
        next = nextNode; // Set the next pointer to the provided node
    }
}

public class Main {
    // Function to convert an array to a linked list
    static Node arrayToLL(int[] arr) {
        // Create the head of the linked list using the first element of the array
        Node head = new Node(arr[0]);
        Node p = head; // Pointer to traverse the linked list

        // Loop through the rest of the array to create nodes
        for (int i = 1; i < arr.length; i++) {
            Node temp = new Node(arr[i]); // Create a new node for each element
            p.next = temp; // Link the current node to the new node
            p = p.next; // Move the pointer to the new node
        }
        return head; // Return the head of the linked list
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4}; // Initialize an array

        // Convert the array to a linked list and get the head
        Node head = arrayToLL(arr);
        
        // Output the data of the third node in the linked list (value 3)
        System.out.println(head.next.next.data); 
    }
}
