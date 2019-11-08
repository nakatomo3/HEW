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

	bool GetBool(string name);
	int GetInt(string name);
	float GetFloat(string name);
	string GetString(string name);

	void SetBool(string name, bool value);
	void SetInt(string name, int value);
	void SetFloat(string name, float value);
	void SetString(string name, string value);

private :
	map<string, bool> boolMap;
	map<string, int> intMap;
	map<string, float> floatMap;
	map<string, string> stringMap;
};

