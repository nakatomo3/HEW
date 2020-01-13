#pragma once
#include "Scene.h"
class MegatonPunchRule : public Scene {
public:
	MegatonPunchRule(string name);
	~MegatonPunchRule();

	void Load();
	void Start();
	void Update();

	void UnLoad();

private:

};

