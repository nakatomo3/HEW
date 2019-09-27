@echo off

rem ファイル名
set FILE_NAME=
echo "ファイル名を入力してください"
set /P FILE_NAME=""

if exist %FILE_NAME%.h (
  echo ファイルが存在していたので実行しませんでした
  goto end
)

rem -------ヘッダファイルの作成-------
  echo #pragma once >> %FILE_NAME%.h
  echo #include "Component.h" >> %FILE_NAME%.h
  echo class sampleComponent : public Component { >> %FILE_NAME%.h
  echo public : >> %FILE_NAME%.h
  echo 	%FILE_NAME%() {}; >> %FILE_NAME%.h
  echo 	~%FILE_NAME%() {}; >> %FILE_NAME%.h
  echo. >> %FILE_NAME%.h
  echo 	void Awake() { >> %FILE_NAME%.h
  echo. >> %FILE_NAME%.h
  echo 	} >> %FILE_NAME%.h
  echo 	void Start() { >> %FILE_NAME%.h
  echo. >> %FILE_NAME%.h
  echo 	} >> %FILE_NAME%.h
  echo 	void FirstUpdate() >> %FILE_NAME%.h
  echo. >> %FILE_NAME%.h
  echo 	} >> %FILE_NAME%.h
  echo 	void Update() { >> %FILE_NAME%.h
  echo. >> %FILE_NAME%.h
  echo 	} >> %FILE_NAME%.h
  echo 	void LastUpdate() { >> %FILE_NAME%.h
  echo. >> %FILE_NAME%.h
  echo 	} >> %FILE_NAME%.h
  echo } >> %FILE_NAME%.h

rem -------ソースファイルの作成-------


:end
timeout 60