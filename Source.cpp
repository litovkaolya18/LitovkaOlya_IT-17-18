#include "Header.h"

// Указывает на голову очереди и хвост
Queue::Queue() : Head(nullptr), Tail(nullptr), CurrentSize(0) {}

//Для освобождения памяти
Queue::~Queue() 
{
    clear();
}

// Метод для добавления элемента в конец очереди
void Queue::push(double value) 
{
    QueueNode* newNode = new QueueNode(value);
    if (empty())
    {
        Head = Tail = newNode;  // Устанавливаем Head и Tail на новый узел
    }
    else 
    {
        Tail->Next = newNode; // Указываем, что текущий Tail ссылается на новый узел
        Tail = newNode;   // Обновляем Tail для указания на новый узел
    }
    CurrentSize++;
}

// Метод для извлечения элемента из начала очереди
double Queue::pop()
{
    if (empty()) 
    {
        throw QueueException("error");
    }

    //Сохраняем указатель на первый элемент очереди 
    QueueNode* tempNode = Head;
    double value = tempNode->Value;
    Head = Head->Next;

    if (Head == nullptr) 
    {
        Tail = nullptr; //Так как очередь теперь пуста, то tail в nullptr
    }

    delete tempNode;
    CurrentSize--;
    return value;
}

// Метод для получения значения первого элемента очереди
double Queue::front() const 
{
    if (empty()) 
    {
        throw QueueException("error");
    }
    return Head->Value;
}

// Метод для получения текущего количества элементов в очереди
size_t Queue::size() const 
{
    return CurrentSize;
}

// Метод для очистки очереди
void Queue::clear() 
{
    while (!empty()) 
    {
        pop();
    }
}

// Метод для проверки, пуста ли очередь
bool Queue::empty() const 
{
    return Head == nullptr;
}