#include "notesdrawing/notes_drawing.h"
#include <ftxui/component/component_base.hpp>
#include <notesmenu/notes_menu.h>
#include <cstdio>
#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
using namespace notesmenu;
using namespace notesdrawing;
using namespace ftxui;

NotesDrawing::NotesDrawing(){};
void NotesDrawing::NotesLayout(){
  NotesMenu m;
  auto listmenu = m.ListMenu();
  /*std::vector<std::string> menuItems = {
    "Add note",
    "Notes list",
    "Exit"
  };
  int selected = 0;
  MenuOption option;
  
  Component listmenu = Menu(&menuItems,&selected);
*/
  auto layout = Container::Horizontal({
    listmenu,
  });
  auto component = Renderer(layout, [&]{
    return hbox({
       listmenu->Render(),
    }) | border;
    }); 
   auto screen = ScreenInteractive::Fullscreen();
   screen.Loop(component);   
}

