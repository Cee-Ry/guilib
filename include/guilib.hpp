#pragma once

#include <cstdlib>
#include <print>
#include <raylib.h>
#include <string_view>

namespace gui {
  // Window Class
  class Window {
  public:
    // Constructor
    Window(int width, int height, const std::string_view title) {
      if (IsWindowReady()) {
        std::println(stderr, "\033[31m[GUI Warning] Attempted to open multiple windows. Must only be one [gui::Window]\033[0m");
        exit(EXIT_FAILURE);
      }

      InitWindow(width, height, title.data());
      SetTargetFPS(60);
    }
    // Deconstructor
    ~Window() {
      CloseWindow();
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
    } // making Renderer's object into Window's member

    // Methods
    void ToggleFullscreen() { ToggleFullscreen(); }
    void ToggleBorderlessWindowed() { ToggleBorderlessWindowed(); }
    void MaximizeWindow() { MaximizeWindow(); }
    void MinimizeWindow() { MinimizeWindow(); }
    void RestoreWindow() { RestoreWindow(); }
    void SetWindowIcon(Image image) { SetWindowIcon(image); }


    bool isOpen() const { return !WindowShouldClose(); }
    
  }; // Window
} // namespace 

