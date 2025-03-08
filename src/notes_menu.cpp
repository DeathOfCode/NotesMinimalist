#include <ftxui/component/component_base.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/screen/screen.hpp>
#include <vector>
#include <string>
#include "notesmenu/notes_menu.h"

#include <ftxui/component/captured_mouse.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/component/screen_interactive.hpp>
using namespace notesmenu;
using namespace ftxui;

NotesMenu::NotesMenu() {}; 
Component NotesMenu::ListMenu(){ 
  std::vector<std::string> menuItems = {
    "Add note",
    "Notes list",
    "Exit"
  };
  int selected = 0;
  MenuOption option;
  Component menu = Menu(&menuItems,&selected);
  return menu;
}
