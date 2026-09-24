#include "guilib.hpp"

int main() {
  gui::Window window(250, 250, "Title");
  gui::Window win(250, 250, "Title");

  while(window.isOpen()) {
    window.startRender(BLUE);

    while (win.isOpen()) {
      win.startRender(WHITE);
      win.endRender();
    }
    window.endRender();
  }

  return 0;
}
