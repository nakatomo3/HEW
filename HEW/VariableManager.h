#pragma once
#include "Singleton.h"
#include <map>
#include <string> 
using namespace std;
class VariableManager : public Singleton<VariableManager> {
public:

	friend class Singleton<VariableManager>;

	VariableManager();
	~VariableManager();

	int GetInt(string name);
	float GetFloat(string name);
	string GetString(string name);

	void SetInt(string name, int value);
	void SetFloat(string name, float value);
	void SetString(string name, string value);

private :
	map<string, int> intMap;
	map<string, float> floatMap;
	map<string, string> stringMap;
};

