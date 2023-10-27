/*
    Vitaliy Polyakov (c), polyakov.vs@mail.ru, 2023.

    Library menu (версия 1.0).
    This C++ library includes menu.h and menu.cpp files.

    The library designed for user interaction with console program 
    through a menu like:
    MENU NAME
    [a] - menu item 1
    [b] - menu item 2
    [c] - menu item 3
    [.] - menu item N (maximum 10 items, default)
    
    Sample use

    #include "menu.h"
    Menu main_menu("MAIN MENU:", 3);
    main_menu.addItem(0, 'n', "start new game");
    main_menu.addItem(1, 'r', "display game rules");
    main_menu.addItem(2, 'e', "exit game");
    char c;
    c = main_menu.getItem();

    Console output

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
    // ~Menu();
    bool addItem(int position, char hotkey, std::string caption);
    char getItem();
};

Menu::Menu(std::string title, int itemsCount)
{
    _title = title;
    _itemsCount = itemsCount;
}

// Menu::~Menu()
// {
// }

bool Menu::addItem(int position, char hotkey, std::string caption)
{
    if (position <= _itemsCount)
    {
        _items[position]._hotkey = hotkey;
        _items[position]._caption = caption;
        return true;
    }
    else return false;
}

char Menu::getItem()
{
    // display menu
    std::cout << _title << std::endl;
    for (int i = 0; i <= _itemsCount - 1; i++)
    {
        std::cout   << "[" << _items[i]._hotkey << "] - "
                    << _items[i]._caption << std::endl;
    }
 
    // get user choice
    char _userChoice;
    bool _flag = true;
    while (_flag)
    {
        std::cout << "Enter your choice and press [ENTER]-key: ";
        std::cin >> _userChoice;

        // check user choice value
        for (int i = 0; i <= _itemsCount - 1; i++)
        {
            if (_userChoice == _items[i]._hotkey)
            {
                _flag = false;
            }
        }
        if (_flag)
        {
            std::cout << "Invalid value. Try again.\n";
        }
    }
    return _userChoice;
}

int main()
{
    Menu main_menu("MAIN MENU:", 3);
    main_menu.addItem(0, 'n', "start new game");
    main_menu.addItem(1, 'r', "display game rules");
    main_menu.addItem(2, 'e', "exit game");
    main_menu.getItem();

    return 0;
}
