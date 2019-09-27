#pragma once
#include "Singleton.h"
#include "Scene.h"
#include <vector>
#include <string>

using namespace std;

class SceneManager : public Singleton<SceneManager>{
public :
	friend class Singleton<SceneManager>;

	void LoadScene(Scene* scene);
	void LoadScene(string name);
	void LoadScene(unsigned int num);

	void BackLoad(Scene* scene);
	void BackLoad(string name);
	void BackLoad(unsigned int num);

	void UnLoad(Scene* scene);

	Scene* GetScene(unsigned int num);
	Scene* GetScene(string name);

	string GetSceneName(Scene* scene);
	string GetSceneName(unsigned int number);

	void AddScene(Scene* scene);

	string GetNowScene();
	int GetNowSceneNumber();

private:
	SceneManager();
	~SceneManager();

	Scene* nowScene;

	vector<Scene*> sceneList;
};