// Client.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include <Windows.h>                  //Два файла с определениями, макросами
#include <windowsx.h>                  //и прототипами функций Windows
//глобальные переменные для рисования окна
HINSTANCE hInstance; HINSTANCE hPrevInst;
LPSTR lpszArgs; int nWinMode;
/*Прототип используемой в программе оконной функции */
LRESULT CALLBACK WindowFunc(HWND, UINT, WPARAM, LPARAM);
/*Произвольный класс*/
class exemple
{
public:
	/*Главная функция приложения WinMain*/
	int  WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst,
		LPSTR lpszArgs, int nWinMode) {
		char szWinName[] = "MyWindow";      //Произвольное имя класса главного окна
		char szTitle[] = "Prog";               //Произвольный заголовок окна
		MSG msg;                    //Структура msg типа MSG для получения сообщений Windows
		WNDCLASS wc;                                  //Структура wc типа WNDCLASS для задания 
													  //характеристик окна
													  /*Заполнение структуры wc типа WNDCLASS для описания класса главного окна*/
		ZeroMemory(&wc, sizeof(wc));                             //Обнуление всех членов структуры wc
		wc.hInstance = hInstance;                                       // Дескриптор приложения
		wc.lpszClassName = (LPCTSTR)szWinName;                           // Имя класса окна
		wc.lpfnWndProc = WindowFunc;                           // Определение оконной функции 
		wc.style = 0;                                                            // Стиль по умолчанию
		wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);           //Стандартная пиктограмма
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);              //Стандартный курсор мыши
		wc.hbrBackground = GetStockBrush(WHITE_BRUSH);         // Белый фон окна
		wc.lpszMenuName = NULL;                                  // Без меню
		wc.cbClsExtra = 0;                                                  // Без дополнительной информации
		wc.cbWndExtra = 0;												    // Без дополнительной информации
																		  /*Регистрация класса главного окна*/
		if (!RegisterClass(&wc))                                         //Если класс окна не регистрируется
		{                                    // выводим сообщение и заканчиваем выполнение программы
			MessageBox(NULL, (LPCTSTR)"Окно нерегестрируется", (LPCTSTR)"Error", MB_OK);
			return 1;
		}                                                           // возвращаем код ошибки
																	/*Создание главного окна и отображение его на мониторе*/
		HWND hwnd = CreateWindow(                           //Вызов функции API для создания ок-на
			(LPCTSTR)szWinName,                                             // имя класса главного окна
			(LPCTSTR)szTitle,                                                       // заголовок окна
			WS_OVERLAPPEDWINDOW,               // Стиль окна 
			100,                                                            // x-координата левого угла окна
			100,                                                            // y-координата левого угла окна
			500,                                                            // Ширина окна
			100,                                                            // Высота окна
			HWND_DESKTOP,                                  // Без родительского окна
			NULL,                                                       // Без меню
			hInstance,                                                  // Дескриптор приложения
			NULL);                                                     // Без дополнительных аргументов
		ShowWindow(hwnd, SW_SHOWNORMAL);       //  Вызов функции API
											   // для отображения окна 
											   /*Организация цикла обнаружения сообщений*/
		while (GetMessage(&msg, NULL, 0, 0))               // Если есть сообщение, передать его
														   // нашему приложению
			DispatchMessage(&msg);                               //и вызвать оконную функцию WindowFunc 
		return 0;                                                     //После выхода из цикла вернуться в Windows
	}                                                                    //Конец функции WinMain

};

/*Оконная функция WindowFunc главного окна, вызываемая Windows и получающая в качестве параметра сообщение из очереди сообщений данного приложения */
LRESULT CALLBACK WindowFunc(HWND hwnd, UINT message,
	WPARAM wParam, LPARAM lParam) {
	switch (message) {                                      // выбор по значению сообщения (message)
	case WM_DESTROY:                           //При завершении приложения пользователем
		PostQuitMessage(0);                           //вызвать функцию API завершения приложения
		break;
	default:                                    // Все сообщения, не обрабатываемые данной функцией,
												// направляются на обработку по умолчанию 
		return DefWindowProc(hwnd, message, wParam, lParam);
	}                                                           //Конец оператора switch
	return 0;
}
//главная функция консольного приложения
int main(void)
{

	setlocale(LC_ALL, "Russian_Russia.1251");//изменения кодировки для вывода русского языка 
SYSTEMCRASH: //точка возврата
	std::cout << "Введите 1 что бы нарисовать окно, \nдля выхода нажмите клавишу 2 :";
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
		std::cout << "Недопустимый символ попробуйте ещё! \n";
		goto SYSTEMCRASH;
	}


}


/*int main()
{
	system("pause");
	return 0;
}*/


