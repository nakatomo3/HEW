#pragma once
#include "Scene.h"
#include <string>
using namespace std;
class ArcheryTitle : public Scene {
public:
	ArcheryTitle(string name);
	~ArcheryTitle();

	void Load();
	void Start();
	void Update();
};

