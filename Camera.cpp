#include "DXUT.h"
#include "Camera.h"
#include "SkillContestTry1.h"

D3DXVECTOR2 Camera::position = { 0,0 };
float Camera::degree = 0;
float Camera::scale = 0;
D3DXVECTOR2 Camera::shake = { 0,0 };

D3DXMATRIX Camera::GetCameraMatrix()
{
    D3DXMATRIX mat, matDegree, matScale, matPosition, matScreen;

    D3DXMatrixTranslation(&matPosition, -position.x, -position.y, 0);
    D3DXMatrixRotationZ(&matDegree, D3DXToRadian(degree));
    D3DXMatrixScaling(&matScale, 1 / scale, 1 / scale, 1);
    D3DXMatrixTranslation(&matScreen, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);

    mat = matPosition * matScale * matDegree * matScreen;

    return mat;
}
