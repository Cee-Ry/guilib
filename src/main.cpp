#include "guilib.hpp"
#include <print>
using namespace gui;

int main() {
  Window game(400, 400, "Wrapper Tester");

  while (game.isOpen()) {
    Button btn1(float(game.centerX() - 100), float(game.centerY() - 35), 200, 70, "BUTTON TEST");
    if (btn1.update()) std::println("CLICKEd");

    auto frame = game.startRender(BLUE);

    btn1.draw();
  }

  return 0;
}
