#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <conio.h>

static HWND  hConWnd;
HWND BCX_Bitmap(char*,HWND=0,int=0,int=0,int=0,int=0,int=0,int=0,int=0,int=0);
HWND GetConsoleWndHandle(void);
void gotoxy(int column, int line) {
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int main()
{
  hConWnd = GetConsoleWndHandle();
  if (hConWnd)
  {
	  BCX_Bitmap("Image.bmp",hConWnd,350,350,1,0,0);

    getchar();  
  }
  return 0;
}
//dibuja la imagen
HWND BCX_Bitmap(char* Text,HWND hWnd,int id,int X,int Y,int W,int H,int Res,int Style,int Exstyle)
{
  HWND A;
  HBITMAP hBitmap;

  // define el estilo
  if (!Style) Style = WS_CLIPSIBLINGS|WS_CHILD|WS_VISIBLE|SS_BITMAP|WS_TABSTOP;

  // recupera la imagen y la forma
  A = CreateWindowEx(Exstyle,"static",NULL,Style,X,Y,0,0,hWnd,(HMENU)id,GetModuleHandle(0),NULL);

  // contiene el nombre de la imagen
  hBitmap=(HBITMAP)LoadImage(0,Text,IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
  // ajusta el largo y ancho
  if (W || H) hBitmap = (HBITMAP)CopyImage(hBitmap,IMAGE_BITMAP,W,H,LR_COPYRETURNORG);
  SendMessage(A,(UINT)STM_SETIMAGE,(WPARAM)IMAGE_BITMAP,(LPARAM)hBitmap);
  if (W || H) SetWindowPos(A,HWND_TOP,X,Y,W,H,SWP_DRAWFRAME);
  return A;
}
// carga en la consola de windows
HWND GetConsoleWndHandle(void)
{
  HWND hConWnd;
  OSVERSIONINFO os;
  char szTempTitle[64], szClassName[128], szOriginalTitle[1024];
  os.dwOSVersionInfoSize = sizeof( OSVERSIONINFO );
  GetVersionEx( &os );
  // version para
  if ( os.dwPlatformId == VER_PLATFORM_WIN32s ) return 0;
  GetConsoleTitle( szOriginalTitle, sizeof ( szOriginalTitle ) );
  sprintf( szTempTitle,"%u - %u", GetTickCount(), GetCurrentProcessId() );
  SetConsoleTitle( szTempTitle );
  Sleep(40);

  hConWnd = FindWindow( NULL, szTempTitle );
  SetConsoleTitle( szOriginalTitle );

  if ( os.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS )
  {
    hConWnd = GetWindow( hConWnd, GW_CHILD );
    if ( hConWnd == NULL ) return 0;
    GetClassName( hConWnd, szClassName, sizeof ( szClassName ) );
    // while ( _stricmp( szClassName, "ttyGrab" ) != 0 )
    while ( strcmp( szClassName, "ttyGrab" ) != 0 )
    {
      hConWnd = GetNextWindow( hConWnd, GW_HWNDNEXT );
      if ( hConWnd == NULL ) return 0;
      GetClassName( hConWnd, szClassName, sizeof( szClassName ) );
    }
  }
  return hConWnd;
}

