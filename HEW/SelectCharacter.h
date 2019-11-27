#pragma once
#include "Scene.h"
class SelectCharacter :	public Scene {
public:

	void Start();
	void Load();

	SelectCharacter(string name);
	~SelectCharacter();

private:
	vector<bool> isReady;
};