#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(const int& val){
        data = val;
        next = nullptr;
    }
};

class LinkedList{
private:
    Node* head;

public:
    LinkedList(){
        head = nullptr;
    }

    void insertAhead(const int& val){
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertTail(const int& val){
        Node* newNode = new Node(val);

        if(head == nullptr){
            head = newNode;
            return;
        }

        Node* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }

        temp->next = newNode;
    }

    void display(){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

    void deleteNode(const int& val){
        // Case 1: The list is empty
        if(head == nullptr){
            return;
        }

        // Case 2: The head is what we want
        if(head->data == val){
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Case 3: What we want is in the middle or tail
        Node* current = head;
        while(current->next != nullptr && current->next->data != val){
            current = current->next;
        }

        if(current->next == nullptr){
            return;
        }

        Node* nodeToBeDelete = current->next;
        current->next = nodeToBeDelete->next;
        delete nodeToBeDelete;
        return;
    }
};

int main(){
    LinkedList list;

    list.insertAhead(5);
    list.insertAhead(10);
    list.insertAhead(15);
    list.insertTail(15);

    list.display();

    list.deleteNode(15);

    list.display();

    return 0;
}