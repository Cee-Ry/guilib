#pragma once

#include <algorithm>
#include <cstdlib>
#include <print>
#include <raylib.h>
#include <string_view>
#include <type_traits>

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

  class Button {
  private:
    Rectangle bounds;
    std::string_view text {};
    bool isHovered {false};

  public:
    Button(float x, float y, float width, float height, const std::string_view text) 
      : bounds {x, y, width, height}, text(std::move(text)) {}

    // Methods
    // Returns true only on the exact frame the button is clicked
    [[nodiscard]] bool update() {
      isHovered = CheckCollisionPointRec(GetMousePosition(), bounds);

      // MOUSE_BUTTON_LEFT is defined by Raylib
      return isHovered && IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
    }

    void draw() {
      // Swap colors based on hover state
      Color bg_color = isHovered ? LIGHTGRAY : RAYWHITE;

      // Draw background and a clean border
      DrawRectangleRec(bounds, bg_color);
      DrawRectangleLinesEx(bounds, 2.0f, DARKGRAY);

      // Calculate text centering
      int font_size = 20;
      int text_width = MeasureText(text.data(), font_size);

      float text_x = bounds.x + (bounds.width - text_width) / 2.0f;
      float text_y = bounds.y + (bounds.height - font_size) / 2.0f;

      DrawText(text.data(), int(text_x), int(text_y), font_size, BLACK);
    }
  };

  //   void draw() const {
  //
  //
  //
  //   }
  // }; // Button
} // namespace 

