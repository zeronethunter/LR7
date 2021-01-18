#include <iostream>

using namespace std;

struct Node {
    Node* next = nullptr;
    int information = 0;
};

struct Queue {
    Node* first = nullptr;
    Node* last = nullptr;
};

void constructor(Queue& queue) {
    queue.first = nullptr;
    queue.last = nullptr;
}

void push(Queue& queue, const Node& node) {
    Node* new_element = new Node;
    new_element->information = node.information;
    if (queue.first == nullptr) {
        queue.first = new_element;
    } else {
        queue.last->next = new_element;
    }
    queue.last = new_element;
}

Node& pop(Queue& queue) {
    Node *node = queue.first;
    queue.first = queue.first->next;
    return *node;
}

void print (const Queue& queue) {
    cout << "Your queue:" << endl;
    Node* node = queue.first;
    if (queue.first != nullptr) {
        while (node != queue.last) {
            cout << node->information << endl;
            node = node->next;
        }
        cout << node->information << endl;
    } else {
        cout << "Queue doesn't exist" << endl;
    }
}

unsigned int size(Queue& queue) {
    unsigned int count = 0;
    Node *node = queue.first;
    while (node != queue.last) {
        node = node->next;
        ++count;
    }
    ++count;
    return count;
}

void destructor(Queue& queue) {
    Node* trash = queue.first;
    if (queue.first != queue.last) {
        while (queue.first != queue.last) {
            queue.first = queue.first->next;
            delete trash;
            trash = queue.first;
        }
        delete trash;
    }
    queue.first = nullptr;
    queue.last = queue.first;
}

int main() {
    Queue queue;
    constructor(queue);

    for (int i = 0; i <= 12; ++i) {
        Node node;
        node.information = i;
        push(queue, node);
    }

    print(queue);

    cout << "Poped element is ";
    Node node = pop(queue);
    cout << node.information << endl;

    print(queue);

    cout << "Size of queue is " << size(queue) << endl;

    destructor(queue);
    print(queue);
    push(queue, node);
    print(queue);


    return 0;
}
