#include "VariableManager.h"



VariableManager::VariableManager() {
}


VariableManager::~VariableManager() {
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

void VariableManager::SetInt(string name, int value) {
	intMap[name] = value;
}

void VariableManager::SetFloat(string name, float value) {
	floatMap[name] = value;
}

void VariableManager::SetString(string name, string value) {
	stringMap[name] = value;
}
