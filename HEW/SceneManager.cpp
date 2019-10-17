#include "SceneManager.h"
#include "LogWriter.h"

SceneManager::SceneManager() {
	LogWriter::GetInstance().Log("シーンマネージャーが初期化されました");

}

SceneManager::~SceneManager() {

}

void SceneManager::LoadScene(Scene* scene) {
	scene->Load();
	scene->Start();
	nowScene = scene;
}

void SceneManager::LoadScene(string name) {
	for (unsigned int i = 0; i < sceneList.size(); i++) {
		if (sceneList[i]->name == name) {
			sceneList[i]->Load();
			sceneList[i]->Start();
			LogWriter::GetInstance().Log("%sというシーンを読み込みました", name);
			nowScene = sceneList[i];
			return;
		}
	}
	LogWriter::GetInstance().LogWorning("%sというシーンは存在しませんでした",name);
}

void SceneManager::LoadScene(unsigned int num) {
	if (sceneList.size() < num) {
		//シーンリストのサイズよりも大きい場合エラー
		LogWriter::GetInstance().LogWorning("%d番目のシーンは存在しませんでした。シーン数は%dです", num, sceneList.size());
		return;
	}
	sceneList[num]->Load();
	sceneList[num]->Start();
	nowScene = sceneList[num];
}

void SceneManager::BackLoad(Scene * scene) {
	scene->Load();
}

void SceneManager::BackLoad(string name) {
	for (unsigned int i = 0; i < sceneList.size(); i++) {
		if (sceneList[i]->name == name) {
			sceneList[i]->Load();
		}
	}
	LogWriter::GetInstance().LogWorning("%sというシーンは存在しませんでした", name);
	return;
}

void SceneManager::BackLoad(unsigned int num) {
	if (sceneList.size() < num) {
		LogWriter::GetInstance().LogWorning("%d番目のシーンは存在しませんでした。シーン数は%dです", num, sceneList.size());
		return;
	}
	sceneList[num]->Load();
}

void SceneManager::UnLoad(Scene* scene) {
	scene->UnLoad();
}

Scene* SceneManager::GetScene(unsigned int num) {
	if (sceneList.size() < num) {
		LogWriter::GetInstance().LogWorning("%d番目のシーンは存在しませんでした。シーン数は%dです", num, sceneList.size());
		return nullptr;
	}
	return sceneList[num];
}

Scene* SceneManager::GetScene(string name) {
	for (unsigned int i = 0; i < sceneList.size(); i++) {
		if (sceneList[i]->name == name) {
			return sceneList[i];
		}
	}
	LogWriter::GetInstance().LogWorning("%sというシーンは存在しませんでした", name);
	return nullptr;
}

string SceneManager::GetSceneName(Scene * scene) {
	return scene->name;
}

string SceneManager::GetSceneName(unsigned int number) {
	return sceneList[number]->name;
}

void SceneManager::AddScene(Scene * scene) {
	sceneList.push_back(scene);
}

Scene * SceneManager::GetNowScene() {
	return nowScene;
}

string SceneManager::GetNowSceneName() {
	return nowScene->name;
}

int SceneManager::GetNowSceneNumber() {
	return nowScene->sceneNumber;
}