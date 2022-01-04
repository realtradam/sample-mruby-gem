#include <mruby.h>
#include <mruby/string.h>
#include <stdio.h>
#include "raylib.h"
const int screenWidth = 800;
const int screenHeight = 450;

	static mrb_value
mrb_c_method(mrb_state *mrb, mrb_value self)
{
	//mrb_ensure_string_type(mrb, self);
	//printf("%s: A C Extension\n", mrb_str_to_cstr(mrb, self));
	// Initialization
	//--------------------------------------------------------------------------------------

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	Texture2D texture = LoadTexture("assets/HYPERS.png");
	struct Vector2 position = { 0, 0 };

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawTextureEx(texture, position, 0.0f, 4.0f, WHITE);

		DrawText("HYPERS!", 500, 50, 20, RED);

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}

void
mrb_my_silly_extension_gem_init(mrb_state* mrb) {
	struct RClass *class_cextension = mrb_define_module(mrb, "CRubyExtension");
	mrb_define_class_method(mrb, class_cextension, "c_method", mrb_c_method, MRB_ARGS_NONE());
}

void
mrb_my_silly_extension_gem_final(mrb_state* mrb) {
	/* finalizer */
}
