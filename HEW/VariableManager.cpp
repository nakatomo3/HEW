#include "VariableManager.h"



VariableManager::VariableManager() {
}


VariableManager::~VariableManager() {
}

bool VariableManager::GetBool(string name) {
	return boolMap[name];
}

int VariableManager::GetInt(string name) {
	return intMap[name];
}

float VariableManager::GetFloat(string name) {
	return floatMap[name];
}

string VariableManager::GetString(string name) {
	return stringMap[name];
}

void VariableManager::SetBool(string name, bool value) {
	boolMap[name] = value;
}

void VariableManager::SetInt(string name, int value) {
	intMap[name] = value;
}

void VariableManager::SetFloat(string name, float value) {
	floatMap[name] = value;
}

void VariableManager::SetString(string name, string value) {
	stringMap[name] = value;
}
