/*
    Vitaliy Polyakov (c), polyakov.vs@mail.ru, 2023.

    Библиотека menu (версия 1.0).
    Библиотека написана на языке программирования C++, включает два файла:
        menu.h      -заголовочный файл
        menu.cpp    -файл реализации.
    Библиотека предназначена для интерактивного взаимодействия пользователя с
    консольной программой через меню вида:

    НАЗВАНИЕ МЕНЮ:
    [a] - элемент меню 1
    [b] - элемент меню 2
    [c] - элемент меню 3
    [.] - элемент меню N (максимально 10 элементов, по умолчанию)

    Например:

    MAIN GAME MENU:
    [n] - start new game
    [r] - display game rules
    [e] - exit game
    Enter your choice and press [ENTER]-key: 
*/

#include <iostream>
#include <string>

class Menu
{
private:
    std::string     _title;         // menu title (first string)
    int             _itemsCount;    // items count (<= 10)
    
    struct          _item {         // structure of item menu:
        char        _hotkey;        //  hot key
        std::string _caption;       //  item caption
    };
    
    _item           _items[10];      // array of menu items (max count = 10)
public:
    Menu(std::string title, int itemsCount);
    ~Menu();
};