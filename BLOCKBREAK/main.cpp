#include <stdio.h>
#include <d3d9.h>

INT main() 
{
		MSG msg;
		DWORD time = timeGetTime();
		DWORD prevtime = 0;
		DWORD TIME = timeGetTime();
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{

		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
			{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{

			time = timeGetTime();
			if (time - prevtime < 1000 / 60)
			{

			}
			prevtime = time;

		}


	}


	return 0;
}