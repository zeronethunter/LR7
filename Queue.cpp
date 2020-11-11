#include <iostream>

using namespace std;

struct Node {
    Node* next = nullptr;
    int information = 0;
};

struct Queue {
    Queue(Node* start, Node* end) {
        first = start;
        last = end;
    }
    Node* first;
    Node* last;
};
Queue& constructor() {
    Queue queue(nullptr, nullptr);
    if (queue.first != nullptr) {
        cout << "Queue constructed!\n";
    }
    return queue;
}

void push(Queue& queue, const Node& node) {
    if (queue.first == nullptr) {
        Node* new_element = new Node;
        new_element->information = node.information;
        queue.first = new_element;
        queue.last = new_element;
    } else {
        Node* new_element = new Node;
        new_element->information = node.information;
        queue.last->next = new_element;
        queue.last = new_element;
    }
}

Node& pop(Queue& queue) {
    Node *result = new Node;
    Node *node;
    node = queue.first;
    result->information = node->information;
    queue.first = queue.first->next;
    delete node;
    return *result;
}

void print (const Queue& queue) {
    cout << "Your queue:" << endl;
    Node* node = queue.first;
    if (queue.first != queue.last) {
        while (node != queue.last) {
            cout << node->information << endl;
            node = node->next;
        }
        cout << node->information << endl;
    } else if (queue.first != queue.last){
        cout << node->information << endl;
    } else
        cout << "Queue doesn't exist" << endl;
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
    Node *trash = queue.first;
    if (queue.first != queue.last) {
        while (queue.first != queue.last) {
            queue.first = queue.first->next;
            delete trash;
            trash = queue.first;
        }
    }
    trash = queue.first;
    queue = constructor();
    delete trash;
}

int main() {
    Queue queue = constructor();

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


    return 0;
}
