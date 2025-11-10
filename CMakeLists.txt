cmake_minimum_required(VERSION 4.0)

project(MultiEditPDF)

add_executable(MultiEditPDF)

target_sources(MultiEditPDF
  PRIVATE
    ../src/main.cpp
    ../src/CreateConfig.cpp
    ../src/EditFromConfig.cpp
)
target_compile_options(MultiEditPDF PUBLIC -std=c++17)

include(FetchContent)
FetchContent_Declare(
  PDFHummus
  GIT_REPOSITORY https://github.com/galkahana/PDF-Writer.git
  GIT_TAG        v4.6.2
  FIND_PACKAGE_ARGS
)
FetchContent_MakeAvailable(PDFHummus)
target_link_libraries(MultiEditPDF PDFHummus::PDFWriter)