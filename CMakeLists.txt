cmake_minimum_required(VERSION 3.14)
project(NotesMinimalist)
find_package(ftxui 6 REQUIRED)
set(SOURCES          # All .cpp files in src/
    src/notes_drawing.cpp
    src/input_note.cpp
)
set(LIBRARY_NAME engine)  # Default name for the library built from src/*.cpp (change if you wish)
set(CMAKE_CXX_STANDARD 17)
# Compile all sources into a library.
add_library(${LIBRARY_NAME} OBJECT ${SOURCES})

# Lib needs its header files, and users of the library must also see these (PUBLIC). (No change needed)
target_include_directories(${LIBRARY_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)


# Add an executable for the file app/main.cpp.
# If you add more executables, copy these lines accordingly.
add_executable(main app/main.cpp)   # Name of exec. and location of file.
target_link_libraries(main 
  PUBLIC ${LIBRARY_NAME}
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
  )  # Link the executable to library (if it uses it).
