#include "guilib.hpp"
#include <print>
using namespace gui;

int main() {
  Window game(400, 400, "Wrapper Tester");

  Button btn1(200, 200, 150, 50, "BUTTON TEST");

  while (game.isOpen()) {
    if (btn1.update()) std::println("CLICKEd");

    auto frame = game.startRender(BLUE);

    btn1.draw();
  }

  return 0;
}
