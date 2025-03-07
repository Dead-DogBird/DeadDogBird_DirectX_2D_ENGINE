// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>

// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
#include <d3d9.h>
#include <d3dx9.h>
#include <mmsystem.h>

#pragma comment (lib,"d3d9.lib")
#pragma comment (lib,"d3dx9.lib")
#pragma comment (lib, "winmm.lib")

using namespace std;
#include <vector>
#include <list>
#include <map>
#include <math.h>
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define FULLSCREEN false;
#define PI 3.14


#include "GrapicManager.h"
#include "TextureManager.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "Transform.h"
#include "Test.h"
#include "Camera.h"
#include "BoxCollider.h"
#include "Test2.h"
#include "Map.h"
#include "Shadow.h"
#include <math.h>
#include "BackGround.h"
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console") 
#include "PGun.h"
#include "Bullet.h"
#include "MouseCur.h"
#include "SceneManager.h"