#pragma once
#include "Scene.h"
#include <string.h>
using namespace std;
class SelectPlayerCount : public Scene {
public:
	SelectPlayerCount(string name);
	~SelectPlayerCount();

	void Load();
	void UnLoad();
	void Start();
	void Update();
};

