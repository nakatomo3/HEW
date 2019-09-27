#pragma once
#include "Singleton.h"
#include <Windows.h>
#include <mmsystem.h>
#include <time.h>

class Time : public Singleton<Time> {
public:
	friend class Singleton<Time>;
	
	//現在のFPSを取得します
	int GetFPS();
	//今現在アップデート出来るかを取得します(設定FPSを超えないようにしています)
	bool IsUpdate();

	//1フレーム前との時間の差を取得します
	double GetDeltaTime();

	//スタートしてからのフレーム数を取得します
	int GetFrameFromStart();

	//スタートしてからの時間を取得します
	float GetTimeFromStart();

	//時間が流れる速さを変更します
	 void SetTimeSpeed(float speed);
	//時間が流れる速さを取得します
	float GetTimeSpeed();

private :
	float FPS;
	float timeSpeed;
	
	double deltaTime;

	int frameCount;
	
	LARGE_INTEGER m_Counter;
	LONGLONG beforeFrameClock;
	double clocksPerSecond;

	double interval;


	Time();
	~Time();

};