#include <iostream>

using namespace std;

struct Node {
    Node* prev = nullptr;
    int information = 0;
};

struct Stack {
    Stack(Node* start, Node* end) {
        first = start;
        last = end;
    }
    Node* first;
    Node* last;
};
Stack& constructor() {
    Stack stack(nullptr, nullptr);
    if (stack.first != nullptr) {
        cout << "Stack constructed!\n";
    }
    return stack;
}

void push(Stack& stack, const Node& node) {
    if (stack.first == nullptr) {
        Node* new_element = new Node;
        new_element->information = node.information;
        stack.first = new_element;
        stack.last = new_element;
    } else {
        Node* new_element = new Node;
        new_element->information = node.information;
        new_element->prev = stack.last;
        stack.last = new_element;
    }
}

Node& pop(Stack& stack) {
    Node *result = new Node;
    Node *node;
    node = stack.last;
    result->information = node->information;
    stack.last = stack.last->prev;
    delete node;
    return *result;
}

void print (const Stack& stack) {
    cout << "Your stack:" << endl;
    Node* node = stack.last;
    if (stack.first != stack.last) {
        while (node != stack.first) {
            cout << node->information << endl;
            node = node->prev;
        }
        cout << node->information << endl;
    } else if (stack.first != stack.last){
        cout << node->information << endl;
    } else
        cout << "Stack doesn't exist" << endl;
}

unsigned int size(Stack& stack) {
    unsigned int count = 0;
    Node *node = stack.last;
    while (node != stack.first) {
        node = node->prev;
        ++count;
    }
    ++count;
    return count;
}

void destructor(Stack& stack) {
    Node *trash = stack.last;
    if (stack.first != stack.last) {
        while (stack.first != stack.last) {
            stack.last = stack.last->prev;
            delete trash;
            trash = stack.last;
        }
    }
    trash = stack.last;
    stack = constructor();
    delete trash;
}

int main() {
    Stack stack = constructor();

    for (int i = 0; i <= 12; ++i) {
        Node node;
        node.information = i;
        push(stack, node);
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
