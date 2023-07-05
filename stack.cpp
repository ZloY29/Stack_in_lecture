#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cmath>
#include  <cstdio>

using namespace std;

struct Node_stack {
    int info;
    Node_stack* next = NULL;
};

bool empty_stack(Node_stack* Head) {
    if (Head->next == NULL) {
        return true;
    }
    else {
        return false;
    }
}

int size_stack(Node_stack* Head) {
    Node_stack* Buf_Node = new Node_stack;
    Buf_Node = Head;
    int count_elem = 0;
    while (Buf_Node -> next != NULL) {
        count_elem++;
        Buf_Node = Buf_Node -> next;
    }
    return count_elem;
}

void top_stack(Node_stack* Head) {
    if (empty_stack(Head)) {
        cout << "stack empty!\n";
    }
    else {
        cout << Head -> next -> info << "\n";
    }
}

void pop_stack(Node_stack* Head) {
    if (empty_stack(Head)) {
        cout << "stack empty!\n";
    }
    else {
        Head -> next = Head -> next -> next;
    }
}

void push_stack(Node_stack* Head, int data) {
    Node_stack* Buf_Node = new Node_stack;
    Buf_Node -> info = data;
    Buf_Node -> next = Head -> next;
    Head -> next = Buf_Node;
}

void menu() {
    cout << "1 push\n";
    cout << "2 pop\n";
    cout << "3 top\n";
    cout << "4 size\n";
    cout << "5 empty\n";
    cout << "0 exit\n";
}

int main() {
    Node_stack* Head_stack = new Node_stack;
    int number = 10;
    while (number != 0) {
        menu();
        cin >> number;
        switch (number)
        {
            case 1:
            {
                int data;
                cin >> data;
                push_stack(Head_stack, data);
                break;
            }
            case 2:
            {
                pop_stack(Head_stack);
                break;
            }
            case 3:
            {
                top_stack(Head_stack);
                break;
            }
            case 4:
            {
                cout << size_stack(Head_stack) << "\n";
                break;
            }
            case 5:
            {
                if (empty_stack(Head_stack)) {
                    cout << "stack empty!\n";
                }
                else {
                    cout << "stack not empty!\n";
                }
                break;
            }
            case 6:
            {
                exit(0);
                break;
            }
        }
    }
}