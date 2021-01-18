#include <iostream>

using namespace std;

struct Node {
    Node* prev = nullptr;
    int information = 0;
};

struct Stack {
    Node* last = nullptr;
};
void constructor(Stack& stack) {
    stack.last = nullptr;
}

void push(Stack& stack, int i) {
    Node* new_element = new Node;
    new_element->information = i;
    new_element->prev = stack.last;
    stack.last = new_element;
}

Node& pop(Stack& stack) {
    Node* node = stack.last;
    stack.last = stack.last->prev;
    return *node;
}

void print (const Stack& stack) {
    cout << "Your stack:" << endl;
    Node* node = stack.last;
    if (node != nullptr) {
        while (node != nullptr) {
            cout << node->information << endl;
            node = node->prev;
        }
    } else {
        cout << "Stack is empty!" << endl;
    }
}

unsigned int size(Stack& stack) {
    unsigned int count = 0;
    Node *node = stack.last;
    if (node != nullptr) {
        while (node != nullptr) {
            node = node->prev;
            ++count;
        }
    } else {
        return 0;
    }
    return count;
}

void destructor(Stack& stack) {
    Node *trash = stack.last;
    if (trash != nullptr) {
        while (stack.last != nullptr) {
            stack.last = stack.last->prev;
            delete trash;
            trash = stack.last;
        }
        delete trash;
    } else {
        return;
    }
}

int main() {
    Stack stack;
    constructor(stack);

    for (int i = 0; i <= 12; ++i) {
        push(stack, i);
    }

    print(stack);

    cout << "Poped element is ";
    Node node = pop(stack);
    cout << node.information << endl;

    print(stack);

    cout << "Size of stack is " << size(stack) << endl;

    destructor(stack);
    print(stack);


    return 0;
}
