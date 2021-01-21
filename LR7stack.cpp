#include <iostream>
using namespace std;

struct Node{
    Node* prev;
    //Node* next;
    int value;
};

struct Stack{
    Node* top;
    unsigned int count;
};

void constructor(Stack& stack){
    stack.top = nullptr;
    stack.count = 0;
}


Stack& push(Stack& stack, Node* node){
    node->prev = stack.top;
    stack.top = node;
    stack.count++;
    return stack;
}

int pop(Stack& stack){
    Node* deleted = stack.top;
    stack.top = stack.top->prev;
    stack.count--;
    int value = deleted->value;
    delete deleted;
    return value;
}

void destructor(Stack& stack){
    Node* tmp = stack.top;
    for(int i = 0 ; i < stack.count; i++){
        Node* deleted = tmp;
        tmp = tmp->prev;
        delete deleted;
    }
    
    stack.count = 0;
    stack.top = nullptr;
}

void print(Stack& stack){
    Node* top = stack.top;
    for (int i = 0; i < stack.count; i++) {
        cout << top->value << " ";
        top = top->prev;
    }
    cout << endl;
}

int main()
{
    Stack st;
    constructor(st);
    cout << "Введите размер\n";
    int n;
    cin >> n;
    cout << "Введите ноды\n";
    for (int i = 0; i < n; i++) {
        Node* newNode = new Node;
        cin >> newNode->value;
        push(st, newNode);
    }
    cout << "После ввода\n";
    print(st);
    
    cout << "После удаления верхнего элемента\n";
    cout << "Элемент удален: " << pop(st) << endl;
    print(st);
    
    destructor(st);
    cout << "После деструктора:" << endl;
    print(st);
    
    return 0;
}
