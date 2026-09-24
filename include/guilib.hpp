#pragma once

#include <raylib.h>
#include <string_view>

namespace gui {
  // Window Class
  class Window {
  public:
    // Constructor
    Window(int width, int height, const std::string_view title) {
      InitWindow(width, height, title.data());
      SetTargetFPS(60);
    }

    // Deconstructor
    ~Window() {
      CloseWindow();
    }

    // Methods
    bool isOpen() const {
      return !WindowShouldClose();
    }
    void startRender(Color setColor) {
      BeginDrawing();
      ClearBackground(setColor);
    }
    void endRender() {
      EndDrawing();
    }
  }; // Window
} // namespace 
