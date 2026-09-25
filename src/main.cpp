#include "guilib.hpp"

int main() {
  gui::Window window(250, 250, "Title");

  while(window.isOpen()) {
    auto frame = window.startRender();
  }

  return 0;
}
