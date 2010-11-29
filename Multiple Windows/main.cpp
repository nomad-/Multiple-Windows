#include "moving window.h"
#include "OpenGL window.h"

int windowCounter = 0;

int WINAPI WinMain(HINSTANCE currentInstance, HINSTANCE notUsed, LPSTR commandLine, int howToShow)
{
	HWND movingWindows[2];
	HWND openglWindows[2];

	// windows class registrations
	RegisterClass(&MovingWindow::commonAttributes);
	RegisterClass(&OpenGLWindow::commonAttributes);

	// windows creation,maniphestation,update
	for(int i = 0 ; i < length(movingWindows) ; ++i)
	{
		movingWindows[i] = CreateWindow(esquape(MovingWindow::commonAttributes),TEXT("Moving Window"),WS_OVERLAPPEDWINDOW,
								CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,currentInstance,NULL);
		ShowWindow(movingWindows[i],howToShow);
		UpdateWindow(movingWindows[i]);
	} // end for

	for(int i = 0 ; i < length(openglWindows) ; ++i)
	{
		openglWindows[i] = CreateWindow(esquape(OpenGLWindow::commonAttributes),TEXT("OpenGL Window"),WS_OVERLAPPEDWINDOW,
								CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,currentInstance,NULL);
		ShowWindow(openglWindows[i],howToShow);
		UpdateWindow(openglWindows[i]);
	} // end for

	// message loop
	MSG message;
	while(GetMessage(&message,NULL,0,0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	} // end while

	return message.wParam;
} // end function WinMain