#pragma once
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include<stdio.h>
#include<string>
#include"Singleton.h"
#include<list>
class SaveManager : public Singleton<SaveManager>{
private:

	SaveManager();
	~SaveManager();

	static const int NAME_LEN_MAX;

	map<string, int>    intSaves;
	map<int, string>    intKeys;

	map<string, float>  floatSaves;
	map<int, string>     floatKeys;

	map<string, string> stringSaves;
	map<int, string>     stringKeys;

public:
	friend class Singleton<SaveManager>;

	bool SaveAll(const char* fileName);
	bool LoadAll(const char* fileName);
	//template<class T>
	//void Save(char * fileName, T instance, string key);

	void AddInt(string, int value);
	void AddFloat(string, float value);

	int GetInt(string key);
	int GetInt(string key, int defaultValue);

	float GetFloat(string key);
	float GetFloat(string key, float defaultValue);

private:

};

