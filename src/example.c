#include <mruby.h>
#include <mruby/string.h>
#include <stdio.h>
#include <raylib.h>
#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif
const int screenWidth = 800;
const int screenHeight = 450;
void UpdateDrawFrame(void);     // Update and Draw one frame

	static mrb_value
mrb_c_method(mrb_state *mrb, mrb_value self)
{
	// Initialization
	//--------------------------------------------------------------------------------------
	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
/*
#if defined(PLATFORM_WEB)
        printf("Web!\n");
	emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
        printf("Desktop!\n");
	SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		UpdateDrawFrame();
	}
#endif
*/
	while (true)
	{
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------


	return self;
}


//----------------------------------------------------------------------------------
// Module Functions Definition
//----------------------------------------------------------------------------------
void UpdateDrawFrame(void)
{
	// Update
	//----------------------------------------------------------------------------------
	// TODO: Update your variables here
	//----------------------------------------------------------------------------------

	// Draw
	//----------------------------------------------------------------------------------
	BeginDrawing();

	ClearBackground(RAYWHITE);

	DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

	EndDrawing();
	//----------------------------------------------------------------------------------
}

void
mrb_my_silly_extension_gem_init(mrb_state* mrb) {
	struct RClass *class_cextension = mrb_define_module(mrb, "Ye");
	mrb_define_class_method(mrb, class_cextension, "c_method", mrb_c_method, MRB_ARGS_NONE());
}

void
mrb_my_silly_extension_gem_final(mrb_state* mrb) {
	/* finalizer */
}
