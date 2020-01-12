#pragma once
class InputManager
{
public:
	static POINT mouses;
	InputManager();
	~InputManager();
	static POINT GetMousePosition();
};

