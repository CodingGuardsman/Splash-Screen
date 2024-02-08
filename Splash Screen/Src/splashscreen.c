#include "cprocessing.h"
CP_Image logo;

void splash_screen_init(void)
{
	logo = CP_Image_Load("Assets/DigiPen_BLACK.png");
	CP_Settings_ImageMode(CP_POSITION_CORNER);
	CP_Settings_ImageWrapMode(CP_IMAGE_WRAP_CLAMP);
	CP_System_SetWindowSize(CP_Image_GetWidth(logo), CP_Image_GetHeight(logo));
	CP_Settings_Fill(CP_Color_Create(255, 0, 0, 255));
}

void splash_screen_update(void)
{
	float totalSeconds = CP_System_GetSeconds();
	CP_Graphics_ClearBackground(CP_Color_Create(128, 128, 128, 255));
	CP_Image_Draw(logo, 0.f, 0.f, CP_Image_GetWidth(logo), CP_Image_GetHeight(logo),(int) (totalSeconds/2*255)%255);
	CP_Graphics_DrawCircle(CP_Input_GetMouseX(), CP_Input_GetMouseY(), 20.0f);
}

void splash_screen_exit(void)
{
	CP_Image_Free(&logo);
}