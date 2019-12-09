#pragma once
#include "Scene.h"
#include <string>
using namespace std;

class Archery :	public Scene {
public:
	Archery(string name);
	~Archery();

	void Load();
	void Start();
	void Update();
	
};

