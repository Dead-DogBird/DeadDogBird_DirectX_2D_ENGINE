#include "stdafx.h"
#include "InputManager.h"
POINT InputManager::mouses = POINT();
InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

POINT InputManager::GetMousePosition()
{

	::GetCursorPos(&mouses);
	::ScreenToClient(GrapicManager::window, &mouses);
	return mouses;
}
