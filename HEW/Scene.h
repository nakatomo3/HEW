#pragma once
#include <string>
using namespace std;

class Scene {
public:
	Scene(string name);
	~Scene();

	string name;
	int sceneNumber;

	virtual void Start();

	virtual void Load();

	virtual void UnLoad();
};