#include "components/input_note.h"
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>

ftxui::Component InputNote::GetInputNote(){
  auto write_note = InputNote::write_note;
   return ftxui::Input(write_note,"Add note...");
}
