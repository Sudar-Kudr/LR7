#include <iostream>
using namespace::std;

struct Node{
    Node* next;
    int value;
};

struct Queue{
    Node* top, *tail;
    int count;
};

void constructor(Queue& q){
    q.count = 0;
    q.top = q.tail = nullptr;
}

void destructor(Queue& q){
    Node* tmp = q.top;
    while (tmp != nullptr) {
        Node* del = tmp;
        tmp = tmp->next;
        delete del;
    }
    q.count = 0;
    q.tail = q.top = nullptr;
}

unsigned int size(Queue& q){
    return q.count;
}

bool push(Queue& q, int value){
    Node* tmp = new Node;
    tmp->value = value;
    if(tmp == nullptr)
        return false;
    if(q.count == 0){
        q.top = q.tail = tmp;
    }
    else{
        q.tail->next = tmp;
        q.tail = tmp;
    }
    q.count++;
    return true;
}

bool pop(Queue& q, int& value){
    if(q.count == 0)
        return false;
    Node* tmp = q.top;
    q.top = tmp->next;
    value = tmp->value;
    delete tmp;
    q.count--;
    return true;
}

void print(Queue& q){
    Node* tmp = q.top;
    for(int i = 0; i < q.count; i++){
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
}

int main() {
    Queue q;
    
    constructor(q);
    int value, n;
    cout << "Введите размер\n";
    cin >> n;
    cout << "Введите значение\n";
    for (int i=0; i<n; i++){
        cin >> value;
        push(q, value);
    }
    cout << "Вывод:\n";
    print(q);
    
    pop(q, value);
    cout << "\nУдаленный элемент: " << value << endl;
    cout << "Вывод:\n";
    print(q);
    
    cout << "\nРезультат размера " << size(q) << endl;
    
    destructor(q);
    cout << "После деструктора:\n";
    print(q);
    return 0;
}
