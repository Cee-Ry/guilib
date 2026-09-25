#pragma once

#include <cstdlib>
#include <print>
#include <raylib.h>
#include <string_view>

namespace gui {
  // Window Class
  class Window {
  private:
    inline static bool isInitialized {false};

  public:
    // Constructor
    Window(int width, int height, const std::string_view title) {
      if (isInitialized == true) {
        std::println(stderr, "\033[31m[GUI Warning] Attempted to open multiple windows. Must only be one [gui::Window]\033[0m");
        exit(EXIT_FAILURE);
      }

      InitWindow(width, height, title.data());
      SetTargetFPS(60);
      isInitialized = true;
    }
    // Deconstructor
    ~Window() {
      CloseWindow();
    }

    bool isOpen() const {
      return !WindowShouldClose();
    }
    
    class Renderer {
    private:
    public:
      Renderer(Color background) {
        BeginDrawing();
        ClearBackground(background);
      }
      ~Renderer() {
        EndDrawing();
      }
    }; // Renderer

    [[nodiscard]] Renderer startRender(Color background = RAYWHITE) const {
      return background;
    }
  }; // Window
} // namespace 

