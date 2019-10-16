#pragma once
class Object{
public:
	Object();
	~Object();

	void virtual Destroy();

	bool GetActive();
	void SetActive(bool active);

protected:
	bool isActive;
};

