/*
     HALLOWEEN SPECIAL

     SCREAMER PRANK API
     
     FROM VIDEO:
	   https://www.youtube.com/watch?v=BGyfYF-fM7U

     Use this responsibly!

     HAVE FUN !
     
     0xD3struction

     2o23

*/


#include <windows.h>
#include <mmsystem.h>

HWND hwnd;

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	switch(Message)
	{
		case WM_CREATE:
		{
		  while(true)
		  {
			Sleep(60000);  // 1 min  
		    ShowWindow(hwnd,SW_SHOWNORMAL);
			SetWindowPos(hwnd, HWND_TOPMOST, 0,0,0,0, SWP_NOMOVE | SWP_NOSIZE);
			
			HBITMAP hbmPicture;
			hbmPicture =( HBITMAP ) LoadImage( NULL, "face.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE );
	
			HDC hdcNew = CreateCompatibleDC( 0 );
    		SelectObject( hdcNew, hbmPicture );
    
    		BITMAP bmInfo;
			GetObject( hbmPicture, sizeof( bmInfo ), & bmInfo );
	
    		HDC hdc = GetDC( hwnd );
    		
			BitBlt( hdc, 0, 0, bmInfo.bmWidth, bmInfo.bmHeight, hdcNew, 0, 0, SRCCOPY );
			PlaySound(TEXT("SCREAM.wav"), NULL, SND_FILENAME);
			
			
			ReleaseDC( hwnd, hdc );
			ShowWindow(hwnd,SW_HIDE);
			}
		}
		
		
			
			
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wc; 
	MSG msg;
	memset(&wc,0,sizeof(wc));
	
	
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; 
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc .lpszClassName = "ScaryClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); 
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); 

	if(!RegisterClassEx(&wc))
		return 0;
	

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"ScaryClass"," 0xD3struction HALLOWEEN",WS_POPUP|WS_EX_TOPMOST,CW_USEDEFAULT,CW_USEDEFAULT, 1000, 1000, NULL,NULL,hInstance,NULL);
	

	if(hwnd == NULL)
		return 0;

	while(GetMessage(&msg, NULL, 0, 0) > 0)
	{ 
		TranslateMessage(&msg); 
		DispatchMessage(&msg); 
	}
	return msg.wParam;
} 
