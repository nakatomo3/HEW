#pragma once
class Object{
public:
	Object();
	~Object();

	void virtual Destroy();

	bool IsActive();
	void SetActive(bool active);

protected:
	bool isActive;
};

