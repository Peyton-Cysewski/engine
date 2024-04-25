#pragma once

#include <Windows.h>

class OS
{
// Windows Implementation Start //

public:
	// Constructor and Destructor
	OS();
	~OS();

	// member variables
private:
	WNDCLASS wc_ = {};
	HWND hwnd_ = {};
public:

	// member functions
private:
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	int RegisterWindowClass();
	int CreateOSWindow();
	void MessageLoop();
public:
	void test();
// Windows Implementation Stop //
};