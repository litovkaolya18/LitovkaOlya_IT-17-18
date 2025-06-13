#pragma once
#include <stdexcept>
#include <string>
using namespace std;

//Класс Queue реализует очередь
class Queue 
{
private:
    //Представляет элементы очереди
    struct QueueNode 
    {
        double Value;     // Значение элемента
        QueueNode* Next; // Указатель на следующий элемент очереди
        QueueNode(double val) : Value(val), Next(nullptr) {}
    };

    QueueNode* Head;    // Указатель на начало очереди (для извлечения)
    QueueNode* Tail;    // Указатель на конец очереди (для добавления)
    size_t CurrentSize; // Подсчитывает текущее количество элементов в очереди
     
public:
    Queue();
    ~Queue();

    void push(double value);  // Добавляет в конец
    double pop();             // Извлекает из начала
    double front() const;     // Просматривает первый элемент
    size_t size() const;      // Размер очереди
    void clear();             // Очистка очереди
    bool empty() const;       // Проверяет на пустоту
};

// Класс исключение QueueException для обработки ошибок
class QueueException : public runtime_error
{
public:
    explicit QueueException(const string& message) : runtime_error(message) {}
};