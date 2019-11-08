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

	bool GetBool(string name);
	int GetInt(string name);
	float GetFloat(string name);
	string GetString(string name);

	void SetBool(string name, bool value);
	void SetInt(string name, int value);
	void SetFloat(string name, float value);
	void SetString(string name, string value);

protected:

	~Scene();

	map<string, bool> boolMap;
	map<string, int> intMap;
	map<string, float> floatMap;
	map<string, string> stringMap;

private:

};