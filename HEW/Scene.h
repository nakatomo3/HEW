#pragma once
#include <string>
#include "GameObject.h"
#include "ObjectManager.h"
using namespace std;

class Scene {
public:
	Scene(string name);

	string name;
	int sceneNumber;

	virtual void Start();

	virtual void Load();

	virtual void UnLoad();

	virtual void Update();

	void Destroy();

protected:

	~Scene();

private:

};