
// Assignment 03: Double Linked List Implementation
// By ALI ZULFIQAR
// STUDENT ID: 2026199005
// Email:zulfiqar@chungbuk.ac.kr

#include <iostream>
#include <string>

using namespace std;

struct DoubleLinkedNode {
    
    int id;
    string name;
    DoubleLinkedNode* next;
    DoubleLinkedNode* prev;
};
DoubleLinkedNode* head = NULL;

// INSERT
int insertDouble(int id, string name) {
    // First check if ID already exists
    DoubleLinkedNode* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            cout << "ID already exists. Insertion failed." << endl;
            return -1; // ID already exists
        }
        temp = temp->next;
    }

    // Create a new node
    DoubleLinkedNode* newNode = new DoubleLinkedNode;
    newNode->id = id;
    newNode->name = name;
    newNode->next = NULL;
    newNode->prev = NULL;

    // If the list is empty, make the new node the head
    if (head == NULL) {
        head = newNode;
    } else {
        // Otherwise, traverse to the end of the list and insert the new node
        DoubleLinkedNode* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current; // Set the previous pointer of the new node
    }
    return 0; // Insertion successful
}

// 2. UPDATE
int updateDouble(int id, std::string name) {
    DoubleLinkedNode* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            temp->name = name; // Update the name
            return 0; // Update successful
        }
        temp = temp->next;
    }
    cout << "ID not found. Update failed." << endl;
    return -1; // ID not found
}

// 3. DELETE
int deleteDouble(int id) {
    DoubleLinkedNode* temp = head;

    // If the list is empty
    if (temp == NULL) {
        cout << "List is empty. Deletion failed." << endl;
        return -1; // List is empty
    }

    // If the node to be deleted is the head
    if (temp->id == id) {
        head = head->next; // Move head to the next node
        if (head != NULL) {
            head->prev = NULL; // Set the previous pointer of the new head to NULL
        }
        delete temp; // Delete the old head
        return 0; // Deletion successful
    }

    // Traverse the list to find the node to delete
    while (temp != NULL && temp->id != id) {
        temp = temp->next;
    }

    // If the node was not found
    if (temp == NULL) {
        cout << "ID not found. Deletion failed." << endl;
        return -1; // ID not found
    }

    // Node found, perform deletion
    if (temp->next != NULL) {
        temp->next->prev = temp->prev; // Update the next node's previous pointer
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next; // Update the previous node's next pointer
    }
    delete temp; // Delete the node
    return 0; // Deletion successful
}

// 4. RETRIEVE
std::string retrieveDouble(int id) {
    DoubleLinkedNode* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp->name; // Return the name if ID is found
        }
        temp = temp->next;
    }
    cout << "ID not found. Retrieval failed." << endl;
    return ""; // ID not found
}

// PRINT

void printDoubleList() {
    DoubleLinkedNode* temp = head;
    if (temp == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    while (temp != NULL) {
        cout << "ID: " << temp->id << ", Name: " << temp->name << endl;
        temp = temp->next;
    }
}

//MAIN

int main() {
    //Insert

    insertDouble(1, "Ali");
    insertDouble(2, "Kim");
    insertDouble(3, "Charlie");
    // Print the list
    printDoubleList();

    //Update
    cout << "Updating ID 2 to 'David'..." << endl;
    updateDouble(2, "David");
    // Print the list
    printDoubleList();

    //Delete
    cout << "Deleting ID 1..." << endl;
    deleteDouble(1);
    // Print the list
    printDoubleList();

    //Retrieve
    cout << "Retrieving name for ID 3: ";
    std::string name = retrieveDouble(3);
    if (!name.empty()) {
        cout << name << endl;
    } else {
        cout << "ID not found." << endl;
    }
}