#pragma once
class Object{
public:
	Object();
	~Object();

	void Destroy();

	bool IsActive();
	void SetActive(bool active);

protected:
	bool isActive;
};

