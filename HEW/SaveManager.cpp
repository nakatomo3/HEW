#include "SaveManager.h"
#include "LogWriter.h"

enum CLASS_ID {
	INT = 0,
	FLOAT = 1,
	STRING = 2,
	LAST
};

SaveManager::SaveManager() {
	LogWriter::GetInstance().Log("セーブマネージャーが正常に初期化されました");
}

SaveManager::~SaveManager() {

}

//セーブが成功したかどうか
bool SaveManager::SaveAll(const char* fileName) {
	bool isSuccess = true;
	FILE* file = fopen(fileName, "wb");
	if (file == NULL) {
		LogWriter::GetInstance().LogWorning("ファイルが見つかりませんでしたので、新規作成しました\n");
		file = fopen(fileName, "w");
		file = fopen(fileName, "wb");
	}

	int saveCount;
	saveCount = intKeys.size() + floatKeys.size() + stringKeys.size();
	fwrite(&saveCount, sizeof(int), 1, file);

	for (unsigned int i = 0; i < intKeys.size(); i++) {
		const int classID = INT;
		const int size = intKeys[i].length();
		fwrite(&classID, sizeof(int), 1, file);
		fwrite(&size, sizeof(int), 1, file);
		for (unsigned int j = 0; j < intKeys[i].length(); j++) {
			fwrite(&intKeys[i][j],sizeof(char),1,file);
		}
		fwrite(&intSaves[intKeys[i]], sizeof(int), 1, file);
	}

	for (unsigned int i = 0; i < floatKeys.size(); i++) {
		const int classID = FLOAT;
		const int size = floatKeys[i].length();
		fwrite(&classID, sizeof(float), 1, file);
		fwrite(&size, sizeof(float), 1, file);
		for (unsigned int j = 0; j < floatKeys[i].length(); j++) {
			fwrite(&floatKeys[i][j], sizeof(char), 1, file);
		}
		fwrite(&floatSaves[floatKeys[i]], sizeof(float), 1, file);
	}

	

	if (isSuccess == true) {
		LogWriter::GetInstance().Log("セーブが正常に完了しました\n");
	}

	fclose(file);
	return isSuccess;
}

bool SaveManager::LoadAll(const char* fileName) {
	bool isSuccess = true;

	FILE* file = fopen(fileName, "rb");
	if (file == NULL) {
		LogWriter::GetInstance().LogWorning("ファイルが見つかりませんでしたので、新規作成しました\n");
		file = fopen(fileName, "w");
		file = fopen(fileName, "rb");
		return false;
	}

	int saveCount;
	fread(&saveCount, sizeof(int), 1, file);
	for (int i = 0; i < saveCount; i++) {
		int classID;
		int size;
		fread(&classID, sizeof(int), 1, file);
		string name;
		switch (classID) {
			default:
				LogWriter::GetInstance().LogError("CLASS_IDを登録してください\n");
				isSuccess = false;
				break;
			case INT:
				fread(&size, sizeof(int), 1, file);
				for (int j = 0; j < size; j++) {
					char oneChar;
					fread(&oneChar, sizeof(char), 1, file);
					name += oneChar;
				}
				int intValue;
				fread(&intValue, sizeof(int), 1, file);
				intKeys[i] = name;
				intSaves[name] = intValue;
				break;
			case FLOAT:
				fread(&size, sizeof(int), 1, file);
				for (int j = 0; j < size; j++) {
					char oneChar;
					fread(&oneChar, sizeof(char), 1, file);
					name += oneChar;
				}
				float floatValue;
				fread(&floatValue, sizeof(float), 1, file);
				break;
			case STRING :
				
				break;
		}
	}


	if (isSuccess == true) {
		LogWriter::GetInstance().Log("ロードが正常に完了しました\n");
	} else {
		LogWriter::GetInstance().LogWorning("ロードが正常に完了しませんでした\n");
	}
	fclose(file);
	return isSuccess;
}

void SaveManager::AddInt(string key, int value) {
	if (intSaves[key] == NULL) {
		intKeys[intKeys.size()] = key;
	}
	intSaves[key] = value;
}

void SaveManager::AddFloat(string key, float value) {
	floatKeys[intKeys.size()] = key;
	if (floatSaves[key] == NULL) {
		floatKeys[floatSaves.size()] = key;
	}
	floatSaves[key] = value;
}

int SaveManager::GetInt(string key) {
	return intSaves[key];
}

int SaveManager::GetInt(string key, int defaultValue) {
	if (intSaves[key] == NULL) {
		return defaultValue;
	}
	return intSaves[key];
}

float SaveManager::GetFloat(string key) {
	return floatSaves[key];
}

float SaveManager::GetFloat(string key, float defaultValue) {
	if (floatSaves[key] == NULL) {
		return defaultValue;
	}
	return floatSaves[key];
}

//saveCount(int) {classID(int) saveNameSize(int) saveName(const char*) object<T>} {classID(int) saveNameSize(int) saveName(const char*) object}