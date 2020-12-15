#include <iostream>
#include <stack>

struct Node{
    int value;
    Node* next;
    Node* prev;
    Node* min;
    Node(int t){
        value = t;
        prev = nullptr;
        next = nullptr;
        min = nullptr;
    }
};

class _1_28{
    bool *T;
    Node *first;
    _1_28(int n){
        T = new bool[n];
        for (int i = 0; i < n; ++i) {
            T[i] = false;
        }
    }
    ~_1_28(){
        delete []T;
    }
    void Select(){
        if(first!= nullptr){
            T[first->value] = -1;
            Node *temp = first;
            first = first->next;
            delete temp;
        }
    }
    bool Search(int i){
        return T[i];
    }
    void insert(int i){
        T[i] = true;
        Node *T = new Node(i);
        if (first != nullptr){
            T->next = first;
            first = T;
        } else
            first = T;
    }
};

class _1_29{
    Node* first;
    Node* *T;
    _1_29(int N){
        first = nullptr;
        T = new Node*[N];
        for (int i = 0; i < N; ++i) {
            T[i] = nullptr;
        }
    }
    ~_1_29(){
        while(!first){
            Node *t = first;
            first = first->next;
            delete t;
        }
    }
    void push(int i){
        if(T[i] != nullptr) {
            Node *N = new Node(i);
            N->next = first;
            first->prev = N;
            first = N;
            T[i] = first;
        }
    }
    void pop(){
        if (first != nullptr){
            Node *temp = first;
            first = first->next;
            T[temp->value] = nullptr;
            delete temp;
        }
    }
    bool search(int i){
        return T[i] != nullptr;
    }
    void Delete(int i){
        if (T[i] != nullptr){
            Node *temp = T[i];
            if (temp->prev != nullptr) {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            } else{
                first = temp->next;
                if(first != nullptr)
                  first->prev = nullptr;
            }
            delete temp;
            T[i] = nullptr;
        }
    }
};

class _1_30{
    Node *first;
    Node *min;
    _1_30(){
        first = nullptr;
        min = nullptr;
    }
    void push(int i){
        Node *T = new Node(i);
        if (first == nullptr){
            first = T;
            min = T;
            T->min = min;
        }
        else{
            first->prev = T;
            T->next = first;
            first = T;
            T->min = min;
            if(min->value < T->value)
                min = T;
        }
    }
    void pop(){
        if(first != nullptr){
            if(min != first){
                Node *t =first;
                first = first->next;
                first->prev = nullptr;
                delete t;
            } else{
                Node *t =first;
                first = first->next;
                first->prev = nullptr;
                delete t;
                if (first != nullptr){
                    min = nullptr;
                }
                else{
                    min = first->min;
                }
            }

        }
    }
    void uptomin(){
        if(first != nullptr){
            first = min->next;
            first->prev = nullptr;
            Node *t = min;
            if(first != nullptr)
                min = first->min;
            else
                min = nullptr;
            while (t != nullptr) { //język C++ wymaga w tym miejscu liniowego dekonstruktora, gdyż doszłoby do wycików pamięci przy braku takiego rozwiązania
                Node *T = t->prev;
                delete t;
                t = T;
            }

        }
    }



};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
