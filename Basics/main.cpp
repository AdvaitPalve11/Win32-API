#define UNICODE
#define _UNICODE
#include<windows.h>

LRESULT CALLBACK WndProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam){
  switch (uMsg)
  {
  case WM_CLOSE:
    PostQuitMessage(0);
    return 0;
    
    case WM_KEYDOWN:
      if(wParam == 'A')
        MessageBox(hWnd,L"You Pressed A",L"Key",MB_OKCANCEL);
        return 0;

  }

   return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

//Entry Point
int WINAPI WinMain(HINSTANCE hIntstance , HINSTANCE hPrev, LPSTR args,int ncmd){

  //Define window Class
  WNDCLASSW wc ={};
  wc.lpfnWndProc = WndProc;
  wc.hInstance = hIntstance;
  wc.lpszClassName = L"Basic Window";
  
  //Register Class
   RegisterClassW(&wc);

   //Create the Window
HWND hWnd = CreateWindow(L"Basic Window" , L"First Window" , WS_OVERLAPPEDWINDOW,100,100,800,600,NULL,NULL,hIntstance,NULL);

//Show The Window
ShowWindow(hWnd,ncmd);

//Message Loop
MSG msg;
while (GetMessage(&msg,NULL,0,0))
{
  DispatchMessage(&msg);
}

return 0;
}

