#include <iostream>
#include "menu/menu.h"

using namespace menu;
Menu::Menu() {}; 

void Menu::display() {
  std::cout << "Test display";
};

void Menu::test(){
   std::cout << "Test method";
}
