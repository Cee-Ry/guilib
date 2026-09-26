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

    // Window Toggling Methods
    void ToggleFullscreen() { ToggleFullscreen(); }
    void ToggleBorderless() { ToggleBorderlessWindowed(); }
    void Maximize() { MaximizeWindow(); }
    void Minimize() { MinimizeWindow(); }
    void RestoreWindow() { RestoreWindow(); }

    // Setter Methods
    void setIcon(const std::string_view path) {
      Image icon = LoadImage(path.data());
      SetWindowIcon(icon);
      UnloadImage(icon);
    }


    bool isOpen() const { return !WindowShouldClose(); }
    
  }; // Window
} // namespace 

