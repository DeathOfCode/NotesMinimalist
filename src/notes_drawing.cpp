#include "notesdrawing/notes_drawing.h"
#include <ftxui/component/component_base.hpp>
#include <cstdio>
#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <vector>
#include <iostream>

using namespace ftxui;

void NotesDrawing::Display(){
  std::vector<std::string> menuItems = {
    "New note",
    "Sort order",
    "Exit"
  };
  std::vector<std::string> noteItems = {
    "note 1",
    "note 2",
    "note 3"
  };

  int selected_menu = 0;
  int selected_note = 0;
  int selected_tab = 0;
  int selected_tab_input = 1;
  std::string write_note;
  std::string write_note_1;

 auto tab_input_container = Container::Tab(
      {
        Input(&write_note, "Add note..."),
        Input(&write_note_1, "Add note111111...")
      },
      &selected_note);
 

  auto tab_note_container = Container::Tab(
      {
      Menu(&noteItems,&selected_note)
      },
      &selected_tab);
 
  auto component_list_menu = Toggle(&menuItems, &selected_menu);
  auto layoutMenu = Container::Vertical({component_list_menu, tab_note_container, tab_input_container});
 
  auto layoutLeft = Renderer(layoutMenu, [&] {
    return vbox({
               component_list_menu->Render(),
               separator(),
               tab_note_container->Render(),
           });
  });

  auto renderer = Renderer(layoutLeft, [&]{
    return hbox({
     layoutLeft->Render(),
       separator(),
     tab_input_container->Render()  
    }) | border;
    });
auto screen = ScreenInteractive::TerminalOutput();

renderer |= CatchEvent([&](Event event) {
  if (event == Event::Character('\n')) {
    screen.ExitLoopClosure()();
    return true;
  }
  return false;
});
     
  screen.Loop(renderer);  
}

