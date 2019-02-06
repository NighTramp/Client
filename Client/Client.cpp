// Client.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include <iostream>
#include <Windows.h>                  //��� ����� � �������������, ���������
#include <windowsx.h>                  //� ����������� ������� Windows
//���������� ���������� ��� ��������� ����
HINSTANCE hInstance; HINSTANCE hPrevInst;
LPSTR lpszArgs; int nWinMode;
/*�������� ������������ � ��������� ������� ������� */
LRESULT CALLBACK WindowFunc(HWND, UINT, WPARAM, LPARAM);
/*������������ �����*/
class exemple
{
public:
	/*������� ������� ���������� WinMain*/
	int  WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst,
		LPSTR lpszArgs, int nWinMode) {
		char szWinName[] = "MyWindow";      //������������ ��� ������ �������� ����
		char szTitle[] = "Prog";               //������������ ��������� ����
		MSG msg;                    //��������� msg ���� MSG ��� ��������� ��������� Windows
		WNDCLASS wc;                                  //��������� wc ���� WNDCLASS ��� ������� 
													  //������������� ����
													  /*���������� ��������� wc ���� WNDCLASS ��� �������� ������ �������� ����*/
		ZeroMemory(&wc, sizeof(wc));                             //��������� ���� ������ ��������� wc
		wc.hInstance = hInstance;                                       // ���������� ����������
		wc.lpszClassName = (LPCTSTR)szWinName;                           // ��� ������ ����
		wc.lpfnWndProc = WindowFunc;                           // ����������� ������� ������� 
		wc.style = 0;                                                            // ����� �� ���������
		wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);           //����������� �����������
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);              //����������� ������ ����
		wc.hbrBackground = GetStockBrush(WHITE_BRUSH);         // ����� ��� ����
		wc.lpszMenuName = NULL;                                  // ��� ����
		wc.cbClsExtra = 0;                                                  // ��� �������������� ����������
		wc.cbWndExtra = 0;												    // ��� �������������� ����������
																		  /*����������� ������ �������� ����*/
		if (!RegisterClass(&wc))                                         //���� ����� ���� �� ��������������
		{                                    // ������� ��������� � ����������� ���������� ���������
			MessageBox(NULL, (LPCTSTR)"���� ����������������", (LPCTSTR)"Error", MB_OK);
			return 1;
		}                                                           // ���������� ��� ������
																	/*�������� �������� ���� � ����������� ��� �� ��������*/
		HWND hwnd = CreateWindow(                           //����� ������� API ��� �������� ��-��
			(LPCTSTR)szWinName,                                             // ��� ������ �������� ����
			(LPCTSTR)szTitle,                                                       // ��������� ����
			WS_OVERLAPPEDWINDOW,               // ����� ���� 
			100,                                                            // x-���������� ������ ���� ����
			100,                                                            // y-���������� ������ ���� ����
			500,                                                            // ������ ����
			100,                                                            // ������ ����
			HWND_DESKTOP,                                  // ��� ������������� ����
			NULL,                                                       // ��� ����
			hInstance,                                                  // ���������� ����������
			NULL);                                                     // ��� �������������� ����������
		ShowWindow(hwnd, SW_SHOWNORMAL);       //  ����� ������� API
											   // ��� ����������� ���� 
											   /*����������� ����� ����������� ���������*/
		while (GetMessage(&msg, NULL, 0, 0))               // ���� ���� ���������, �������� ���
														   // ������ ����������
			DispatchMessage(&msg);                               //� ������� ������� ������� WindowFunc 
		return 0;                                                     //����� ������ �� ����� ��������� � Windows
	}                                                                    //����� ������� WinMain

};

/*������� ������� WindowFunc �������� ����, ���������� Windows � ���������� � �������� ��������� ��������� �� ������� ��������� ������� ���������� */
LRESULT CALLBACK WindowFunc(HWND hwnd, UINT message,
	WPARAM wParam, LPARAM lParam) {
	switch (message) {                                      // ����� �� �������� ��������� (message)
	case WM_DESTROY:                           //��� ���������� ���������� �������������
		PostQuitMessage(0);                           //������� ������� API ���������� ����������
		break;
	default:                                    // ��� ���������, �� �������������� ������ ��������,
												// ������������ �� ��������� �� ��������� 
		return DefWindowProc(hwnd, message, wParam, lParam);
	}                                                           //����� ��������� switch
	return 0;
}
//������� ������� ����������� ����������
int main(void)
{

	setlocale(LC_ALL, "Russian_Russia.1251");//��������� ��������� ��� ������ �������� ����� 
SYSTEMCRASH: //����� ��������
	std::cout << "������� 1 ��� �� ���������� ����, \n��� ������ ������� ������� 2 :";
	char ch_chose = '\0';
	std::cin >> ch_chose;
	class exemple val;
	switch (ch_chose)
	{
	case '2':
		exit(0);
		break;
	case '1':
		val.WinMain(hInstance, hPrevInst,
			lpszArgs, nWinMode);
		break;
	default:
		std::cout << "������������ ������ ���������� ���! \n";
		goto SYSTEMCRASH;
	}


}


/*int main()
{
	system("pause");
	return 0;
}*/


