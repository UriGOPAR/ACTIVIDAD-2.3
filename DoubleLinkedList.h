#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "DLLNode.h"
#include <iostream>

template <class T>
class DoubleLinkedList{
private:
    DLLNode<T> *head;
    DLLNode<T> *tail;
    int numElements;
    //mergeSort
    DLLNode<T>* mergeSort(DLLNode<T>* head);
    DLLNode<T>* merge(DLLNode<T>* first,DLLNode<T>* second);
    DLLNode<T>* split(DLLNode<T>* head);
    DLLNode<T>* split(DLLNode<T>* head, DLLNode<T>*tail);
    DLLNode<T> *lastNode(DLLNode<T> * root);

public:
    DoubleLinkedList();
    ~DoubleLinkedList();

    // Retorna el numero de elementos en la lista
    int getNumElements();
    // Imprime los elementos
    void printList();
    // Agrega elementos al inicio
    void addFirst(T value);
    // Agrega elementos al final
    void addLast(T value);
    // Borra el primer elemento de valor "value"
    bool deleteData(T value);
    // Borra un elemento segun su posición
    bool deleteAt(int position);
    // Nos regresa el elemento en una posición
    T getData(int position);
    // Actualiza el primer elemento de valor "value" por "newValue"
    void updateData(T value, T newValue);
    // Actualiza un elemento segun su posición por "newValue"
    void updateAt(int position, T newValue);
    // Busca la posición de newValue
    int findData(T newValue);
    DLLNode<T>* findNode(int i);
    // Sobrescribe el =
    void operator=(const DoubleLinkedList<T> &other);
    // Ordena los elementos usando mergeSor
    void sort();
    // Invertir la lista dada 
    void invert();
    // Regresa una lista diferente oredenada a la inversa
    DoubleLinkedList<T> getReversedSubList(int inicio,int fin);
    //Hace lo mismo que el destructor
    void clearMemory();
    // BinarySearch
    DLLNode<T>* binarySearch(DLLNode<T>* head, T value);

    DLLNode<T>* getHead();
    DLLNode<T>* getTail();
};

template <class T>
DoubleLinkedList<T>::DoubleLinkedList(){
    head = nullptr;
    tail = nullptr;
    numElements = 0;
}

template <class T>
DoubleLinkedList<T>::~DoubleLinkedList(){
    DLLNode<T> *prev, *q;
    prev = head;
    while (prev != nullptr){
        q = prev->next;
        delete prev;
        prev = q;
    }
    head = nullptr;
    tail = nullptr;
    numElements = 0;
}
template <class T>
void DoubleLinkedList<T>::clearMemory(){
    DLLNode<T> *prev, *q;
    prev = head;
    while (prev != nullptr){
        q = prev->next;
        delete prev;
        prev = q;
    }
    head = nullptr;
    tail = nullptr;
    numElements = 0;
}
template <class T>
int DoubleLinkedList<T>::getNumElements(){
    return numElements;
}
// Complejidad O(n)
template <class T>
void DoubleLinkedList<T>::printList(){
    DLLNode<T> *ptr = head;
    while (ptr != nullptr){
        std::cout << ptr -> data << " ";
        ptr = ptr -> next;
    }
    std::cout << std::endl;
}
// Complejidad O(n)
template <class T>
void DoubleLinkedList<T>::addFirst(T value){
    DLLNode<T> *newDLLNode = new DLLNode<T>(value);
    if(numElements == 0){
        head = newDLLNode;
        tail = newDLLNode;
    }
    else{
        newDLLNode->next = head;
        head->prev = newDLLNode;
        head = newDLLNode;
    }
    numElements++;
}
// Complejidad O(n)
template <class T>
void DoubleLinkedList<T>::addLast(T value){
    if(numElements == 0){
        addFirst(value);
    }
    else{
        // creando un nuevo nodo de la lista
        DLLNode<T> *newDLLNode = new DLLNode<T>(value);
        tail->next = newDLLNode;
        newDLLNode->prev = tail;
        tail = newDLLNode;
        numElements++;
    }
}
// Complejidad O(n)
template <class T>
bool DoubleLinkedList<T>::deleteData(T value){
    bool estado = false;
    if(numElements == 0){
        return estado;
    }
    else{
        DLLNode<T> *p = head;
        DLLNode<T> *prev = nullptr;
        while(p != nullptr && p->data != value){
            prev = p;
            p = p->next;
        }
        if(p == nullptr){
            return estado;
        }
        if(p == head){
            head = p->next;
            if(head != nullptr)
                head->prev = nullptr;
        }
        else if(p->next == nullptr){
            prev->next = nullptr;
            tail = prev;
        }
        else{
            prev->next = p->next;
            p->next->prev = p->prev;
        }
        delete p;
        numElements--;
        estado = true;
        return estado;
    }
}
// Complejidad O(n)
template <class T>
bool DoubleLinkedList<T>::deleteAt(int position){
    if(position < 0 || position >= numElements){
        throw std::out_of_range("Indice fuera de rango");
    }
    else if(position == 0){ 
        DLLNode<T> *p = head;
        if(head != nullptr && head->next == nullptr){
            head = nullptr;
            tail = nullptr;
        }
        else{
            head = p->next;
            head->prev = nullptr;
        }
        delete p;
        numElements--;
        return true;
    }
    else{
        DLLNode<T> *p = head, *q = nullptr;
        int index = 0;
        while(index != position){
            q = p;
            p = p->next;
            index++;
        }
        if(p->next == nullptr){
            q->next = nullptr;
            tail = q;
        }
        else{
            q->next = p->next;
            p->next->prev = q;
        }
        delete p;
        numElements--;
        return true;
    }
}
// Complejidad O(n)
template <class T>
T DoubleLinkedList<T>::getData(int position){
    if(position < 0 || position >= numElements){
        throw std::out_of_range("Indice fuera de rango");
    }
    else{
        if(position == 0){
            return head->data;
        }
        DLLNode<T> *p = head;
        int index = 0;
        while(p != nullptr){
            if(index == position)
                return p->data;
            index++;
            p = p->next;
        }
        return {};
    }
}
// Complejidad O(n)
template <class T>
void DoubleLinkedList<T>::updateData(T value, T newValue){
    if(numElements > 0){
        DLLNode<T> *p = head;
        DLLNode<T> *prev = nullptr;
        while (p != nullptr && p->data != value){
            prev = p;
            p = p->next;
        }
        if(p != nullptr)
            p->data = newValue;
        else
            throw std::out_of_range("No se encontró el valor en la lista");
    }
}
// Complejidad O(n)
template <class T>
void DoubleLinkedList<T>::updateAt(int position, T newValue){
    if(position < 0 || position >= numElements){
        throw std::out_of_range("Indice fuera de rango");
    }
    else {
      DLLNode<T> *p = head;
      DLLNode<T> *prev = nullptr;
      int index = 0;
      while(index != position){
          prev = p;
          p = p->next;
          index++;
        }
      p->data = newValue;
    }

}
// Complejidad O(n)
template <class T>
int DoubleLinkedList<T>::findData(T value){
      DLLNode<T> *p = head;
      DLLNode<T> *prev = nullptr;
      int index = 0;
      while (p != nullptr && p->data != value){
            prev = p;
            p = p->next;
            index++;
        }
      if(p != nullptr)
         return  index;
      else
         return  index=-1;
}
//Complejidad O(n²)
template <class T>
void DoubleLinkedList<T>::operator=(const DoubleLinkedList<T> &other){
    this->clearMemory();
    DLLNode<T>*p=other.head;
    while (p!=nullptr)
    {
        this->addLast(p->data);
        p=p->next;
    }
}
//Ordenamiento
template <class T>
void DoubleLinkedList<T>::sort(){
        head=mergeSort(head);
}
template <class T>
void DoubleLinkedList<T>::invert(){
    this->operator=(getReversedSubList(0,numElements-1));
}
template <class T>
DoubleLinkedList<T> DoubleLinkedList<T>::getReversedSubList(int inicio,int fin){
    DoubleLinkedList<T> temp;
    
    DLLNode<T>* p=findNode(inicio);
    DLLNode<T>* f=findNode(fin);
    while (true)
    {
        temp.addFirst(p->data);
        if (p==f)
        {
            break;
        }   
        p=p->next;
    }
      
    return temp;
}
// Complejidad O(n)
template <class T>
DLLNode<T>* DoubleLinkedList<T>::findNode(int i){
    if(i < 0 || i >= numElements){
      throw std::out_of_range("Indice fuera de rango");
    }
    else{
        if(i == 0){
            return head;
        }
        DLLNode<T> *p = head;
        int index = 0;
        while(p != nullptr){
            if(index == i)
                return p;
            index++;
            p = p->next;
        }
        return {};
    }
}

template <class T>
DLLNode<T>* DoubleLinkedList<T>::merge(DLLNode<T>* first,DLLNode<T>* second){
    if(!first)
    {
        return second;
    }
    if (!second)
    {
        return first;
    }
    if (first->data<second->data)
    {
        first->next=merge(first->next,second);
        first->next->prev=first;
        first->prev=nullptr;
        return first;
    }
    else{
        second->next = merge(first,second->next); 
        second->next->prev = second; 
        second->prev = nullptr; 
        return second;  
    }
    
    
}
// Complejidad O(n log n)
template <class T>
 DLLNode<T>* DoubleLinkedList<T>::mergeSort(DLLNode<T>* head){
   if (!head || !head->next) 
        return head ; 
     DLLNode<T>*second,*first; 
     second=split(head); 
    first = mergeSort(head); 
    second = mergeSort(second); 
     DLLNode<T>* sortedList=merge(first,second);
    return  sortedList;
}

template <class T>
DLLNode<T>* DoubleLinkedList<T>::split(DLLNode<T>* head){
    DLLNode<T>* fast = head,*slow = head; 
    while (fast->next&&fast->next->next) 
    { 
        fast = fast->next->next; 
        slow = slow->next; 
    } 
    DLLNode<T>* temp = slow->next; 
    slow->next = NULL; 
    return temp; 
}
template <class T>
DLLNode<T>* DoubleLinkedList<T>::split(DLLNode<T>* head, DLLNode<T>*tail){
    if(head==nullptr){
        return nullptr;
    }

    DLLNode<T>* slow=head;
    DLLNode<T>* fast=head;

    while (fast!=slow)
    {
        fast=fast->next->next;
        slow= slow->next;
    }
    return slow;
    
}
//Complejidad O(log n)
template<class T>
DLLNode<T>* DoubleLinkedList<T>::binarySearch(DLLNode<T>* head,T value){
    DLLNode<T>* start=head;
    DLLNode<T>* last=nullptr;
    do
    {
        DLLNode<T>* mid = split(start,last);

        // Si mid no tiene valor
        if (mid==nullptr)
        {
            std::cout<<"No existe"<<std::endl;
            return nullptr;
        }
        // Si mid es lo que buscamos
        if (mid->data==value)
        {
            return mid;
        }
        else if(mid->data<value)
        {
            start=mid->next;
        }
        else{
            last=mid;
        }
    } while (last==nullptr||last!=start);

    return nullptr;
    
}

template <class T>
DLLNode<T>*DoubleLinkedList<T>::getHead(){
    return head;
}
template <class T>
DLLNode<T>*DoubleLinkedList<T>::getTail(){
    return tail;
}
#endif // LINKEDLIST_H
