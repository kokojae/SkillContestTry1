#pragma once
class SceneManager
{
public:
	enum class Scene { TITLE, RANK_BOARD, STAGE1, STAGE2, RESULT, RANK_INPUT };

	static Scene currentScene;

	static void LoadScene(Scene scene);
};

