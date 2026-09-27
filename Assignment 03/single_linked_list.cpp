// Assignment 03 - Single Linked List Implementation
// By ALI ZULFIQAR
// STUDENT ID: 2026199005
// Email:zulfiqar@chungbuk.ac.kr



#include <iostream>
#include <cstring>

using namespace std;

struct SingleNode {

    int id;
    char name[20];
    SingleNode* next;
};

SingleNode* head = NULL;


// INSERT 
int insert(int id, char name[]) {

     // First check if ID already exists
    SingleNode* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            cout << "ID already exists. Insertion failed." << endl;
            return -1; // ID already exists
        }
        temp = temp->next;
    }

    // Create a new node
    SingleNode* newNode = new SingleNode;
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->next = NULL;

    // IF the list is empty, make the new node the head
    if (head == NULL) {
        head = newNode;
    } else {
        // Otherwise, traverse to the end of the list and insert the new node
        SingleNode* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    return 0; // Insertion successful

    // Insert at the end of the list
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return 0; // Insertion successful
}

// 2. UPDATE
int update(int id, char name[]) {
    SingleNode* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            strcpy(temp->name, name);
            return 0; // Update successful
        }
        temp = temp->next;
    }
    cout << "ID not found. Update failed." << endl;
    return -1; // ID not found      
}

// 3. DELETE
int deleteNode(int id) {
    if (head == NULL) {
        cout << "List is empty. Deletion failed." << endl;
        return -1; // List is empty
    }

    // If the node to be deleted is the head
    if (head->id == id) {
        SingleNode* temp = head;
        head = head->next;
        delete temp;
        return 0; // Deletion successful
    }

    // Traverse the list to find the node to delete
    SingleNode* current = head;
    while (current->next != NULL && current->next->id != id) {
        current = current->next;
    }

    // If the node was not found
    if (current->next == NULL) {
        cout << "ID not found. Deletion failed." << endl;
        return -1; // ID not found
    }

    // Node found, perform deletion
    SingleNode* temp = current->next;
    current->next = temp->next;
    delete temp;
    return 0; // Deletion successful
}

// 4. RETRIEVE
char* retrieve(int id) {
    SingleNode* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            return temp->name; // Return the name associated with the ID
        }
        temp = temp->next;
    }
    cout << "ID not found. Retrieval failed." << endl;
    return NULL; // ID not found
}

//5. PRINT
void printSingleList() {
    SingleNode* temp = head;
    if (temp == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    while (temp != NULL) {
        cout << "ID: " << temp->id << ", Name: " << temp->name << endl;
        temp = temp->next;
    }
}

// MAIN FUNCTION
int main() {
    //Insert
    insert(101, (char*)"Ali");
    insert(102, (char*)"Kim");
    insert(103, (char*)"Ahmed");
    printSingleList();

    //Update
    cout << "Updating ID 102 to 'Khan'" << endl;
    update(102, (char*)"Khan");
    printSingleList();

    //Retrieve
    cout << "Retrieving name for ID 103: ";
    char* name = retrieve(103);
    if (name != NULL) {
        cout << name << endl;
    }
    else {
        cout << "ID not found." << endl;
    }
    
    //Delete
    cout << "Deleting ID 101...\n";
    deleteNode(101);
    printSingleList();
    return 0;
}