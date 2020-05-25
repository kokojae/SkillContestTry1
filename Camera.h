#pragma once
class Camera
{
public:
	static D3DXVECTOR2 position;
	static float degree;
	static float scale;
	static D3DXVECTOR2 shake;

	static D3DXMATRIX GetCameraMatrix();
};

