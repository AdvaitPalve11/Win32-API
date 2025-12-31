#include<windows.h>

LRESULT CALLBACK WndProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam){
  switch (uMsg)
  {
  case WM_CLOSE:
    PostQuitMessage(0);
    return 0;
    break;
    case WM_KEYDOWN:
      if(wParam == 'A')
        MessageBox(hWnd,"You Pressed A","Key",MB_OKCANCEL);
  default:
    break;
  }

   return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hIntstance , HINSTANCE hPrev, LPSTR args,int ncmd){

  WNDCLASSW wc ={};
  wc.lpfnWndProc = WndProc;
  wc.hInstance = hIntstance;
  wc.lpszClassName = L"Basic Window";

  CreateWindow("Basic Window" , "First Window" , WS_OVERLAPPEDWINDOW,100,100,800,600,NULL,NULL,hIntstance,NULL);
}

