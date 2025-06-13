#include <iostream>
#include <Windows.h>
#include <string>
#include <sstream>
#include "Header.h"

using namespace std;
void Menu() 
{
    cout << "Икм летняя сессия. Литовка Ольга ИТ-17,18. Задача 10\n";
    cout << "Здравствуй пользователь! Эта программа работает с 'очередью',\n";
    cout << "она реализует все указанные методы в меню которое находиться ниже.\n";
    cout << "Меню управления очередью: \n"
        << "   push <n> - Добавить число в очередь\n"
        << "   pop      - Извлечь первый элемент\n"
        << "   front    - Посмотреть первый элемент\n"
        << "   size     - Узнать размер очереди\n"
        << "   clear    - Очистить очередь\n"
        << "   exit     - Выход из программы\n"
        << "Введите команду:\n";
}

// Метод для обработки пользовательских команд
void ProcessCommand(Queue& queue, const string& commandLine) 
{
    istringstream inputStream(commandLine);
    string command;
    inputStream >> command; // Извлекаем первую часть команды

    try
    {
        if (command == "push") 
        {
            string argument;
            if (!(inputStream >> argument))
            {
                throw runtime_error("Отсутствует аргумент для push");
            }

            size_t pos;
            double number;
            try 
            {
                number = stod(argument, &pos); // Преобразуем строку в число

                // Проверяет что вся строка была обработана как число
                if (pos != argument.length())
                {
                    throw invalid_argument("Неверный формат числа");
                }
            }
            catch (const invalid_argument&) 
            {
                throw runtime_error("Неверный формат числа");
            }
            catch (const out_of_range&) 
            {
                throw runtime_error("Число вне допустимого диапазона");
            }
            
            // Проверяет, что после числа нет больше данных
            if (inputStream >> argument)
            {
                throw runtime_error("Слишком много аргументов для push");
            }

            queue.push(number); // Добавляем элемент в очередь
            cout << "ok" << endl;
        }

        else if (command == "pop")
        {
            // Проверяет, что нет лишних аргументов
            string extra;
            if (inputStream >> extra)
            {
                throw runtime_error("Команда pop не принимает аргументов");
            }
            cout << queue.pop() << endl; 
        }

        else if (command == "front") 
        {
            // Проверяет, что нет лишних аргументов
            string extra;
            if (inputStream >> extra)
            {
                throw runtime_error("Команда front не принимает аргументов");
            }
            cout << queue.front() << endl; 
        }

        else if (command == "size")
        {
            // Проверяет, что нет лишних аргументов
            string extra;
            if (inputStream >> extra)
            {
                throw runtime_error("Команда size не принимает аргументов");
            }
            cout << queue.size() << endl;
        }

        else if (command == "clear") 
        {
            // Проверяет, что нет лишних аргументов
            string extra;
            if (inputStream >> extra)
            {
                throw runtime_error("Команда clear не принимает аргументов");
            }
            queue.clear();
            cout << "ok" << endl;
        }

        else if (command == "exit") 
        {
            // Проверяет, что нет лишних аргументов
            string extra;
            if (inputStream >> extra)
            {
                throw runtime_error("Команда exit не принимает аргументов");
            }
            cout << "bye" << endl;
            exit(0);
        }
        else 
        {
            throw runtime_error("Неизвестная команда");
        }
    }
    catch (const QueueException&)
    {
        cout << "error" << endl;
    }
    catch (const runtime_error& e)
    {
        cout << "error: " << e.what() << endl;
    }
    catch (...) 
    {
        cout << "error: неизвестная ошибка" << endl;
    }
} 

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Queue queue;
    Menu();

    string inputLine;
    //Для обработки команд
    while (true) 
    {
        getline(cin, inputLine);          // Читаем строку ввода
        if (inputLine.empty()) continue;  // Игнорируем пустые строки
        ProcessCommand(queue, inputLine); // Обрабатываем введенную команду
    }
    return 0;
}