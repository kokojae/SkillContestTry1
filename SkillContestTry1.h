#pragma once

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define WINDOWED true

// Component
#include "BoxCollider.h"
#include "TextureInfo.h"

// GameObject
// Base
#include "GameObject.h"
#include "Text.h"
// Bullet
#include "BombBullet.h"
#include "EnemyBullet.h"
#include "PlayerBullet.h"
// Enemy
#include "Enemy.h"
// Boss
#include "Boss.h"
#include "BossHpBar.h"
// Player
#include "Player.h"
// Skill
#include "BigFuckBomb.h"
#include "Sheild.h"

// Item
#include "ItemHeal.h"
// Base
#include "ItemBase.h"

// Managers
#include "Camera.h"
#include "GameManager.h"
#include "GraphicManager.h"
#include "Layer.h"
#include "MouseManager.h"
#include "ObjectManager.h"
#include "RankManager.h"
#include "SceneManager.h"
#include "SoundManager.h"
#include "TextureManager.h"

// Scene
#include "RankBoard.h"
#include "RankInput.h"
#include "Title.h"

// Stage
#include "BackGround.h"

#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console") 
