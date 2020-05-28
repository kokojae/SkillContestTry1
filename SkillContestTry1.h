#pragma once

#define SCREEN_WIDTH 1250
#define SCREEN_HEIGHT 720
#define WINDOWED true

// Component
#include "BoxCollider.h"
#include "TextureInfo.h"

// GameObject
// Base
#include "GameObject.h"
#include "Text.h"
// Bullet
#include "PlayerBullet.h"
// Player
#include "Player.h"

// Managers
#include "Camera.h"
#include "GameManager.h"
#include "GraphicManager.h"
#include "Layer.h"
#include "MouseManager.h"
#include "ObjectManager.h"
#include "SceneManager.h"
#include "SoundManager.h"
#include "TextureManager.h"

#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console") 
