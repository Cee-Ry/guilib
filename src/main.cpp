#include "guilib.hpp"
#include <raylib.h>

int main() {
  gui::Window game(800, 600, "Wrapper Tester");
  gui::Texture test {"textures/redSniper.png"};

  while (game.isOpen()) {
    gui::Button btn1(float(game.centerX() - 75), float(game.centerY() - 25), 150.0, 50.0, "START");
    if (btn1.update()) std::println("CLICKEd");

    auto frame = game.startRender(BLUE);
    test.display(0, 0, RAYWHITE);

    btn1.draw();
  }

  return 0;
}
