#include "notesdrawing/notes_drawing.h"
#include "components/input_note.h"
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
  std::vector<std::string> noteItems = {};

  int selected_menu = 0;
  int selected_note = 0;
  int selected_tab = 0;
  int selected_tab_input = 1;
  std::string write_note;
  std::string write_note_1;
  auto tab_input_container = Container::Tab({},&selected_note);
 
 //tab_input_container->Add(Input(write_note,"Add note test..."));
 //tab_input_container->Add(Input(write_note_1,"Add note111 test..."));
  
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
  if (event == Event::Character('\n') && selected_menu == 0) {
   // screen.ExitLoopClosure()();
      noteItems.push_back("untitled");
     // InputNote input_note;
    //  ftxui::Component input = input_note.GetInputNote();
    //  tab_input_container->Add(input);
      NotesDrawing::AddInputNote(tab_input_container);
      auto sizeNote = noteItems.size();
      selected_note = sizeNote;
    return true;
  }
  return false;
}); 
  screen.Loop(renderer);  
}

void NotesDrawing::AddInputNote(ftxui::Component& tab){
     InputNote input_note;
     ftxui::Component input = input_note.GetInputNote();
     tab->Add(input);
}

