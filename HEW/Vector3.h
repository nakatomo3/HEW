#pragma once
class Vector3 {
public:

	//x,y,z¬•ª‚ğ0‚É‚·‚é‰Šú‰»
	Vector3() {
		x, y, z = 0;
	}

	//x,y¬•ª‚ğw’è‚·‚é‰Šú‰»
	Vector3(float X, float Y) {
		x = X;
		y = Y;
		z = 0;
	}

	//x,y,z¬•ª‚ğw’è‚·‚é‰Šú‰»
	Vector3(float X, float Y, float Z) {
		x = X;
		y = Y;
		z = Z;
	}

	~Vector3() {

	}

	//-------------------------operator-----------------------

	//‘«‚µZ
	Vector3 operator+(Vector3 vector) {
		return Vector3(x + vector.x, y + vector.y, z + vector.z);
	};

	//ˆø‚«Z
	Vector3 operator-(Vector3 vector) {
		return Vector3(x - vector.x, y - vector.y, z - vector.z);
	};

	//Š|‚¯Z
	Vector3 operator* (float value) {
		return Vector3(x * value, y * value, z * value);
	};
	Vector3 operator* (int value) {
		return Vector3(x * value, y * value, z * value);
	};


	//Š„‚èZ
	Vector3 operator/ (float value) {
		return Vector3(x / value, y / value, z / value);
	};
	Vector3 operator/ (int value) {
		return Vector3(x / value, y / value, z / value);
	};

	//“àÏ
	float operator*(Vector3 vector) {
		return x * vector.x + y * vector.y + z * vector.z;
	}



	//ŠOÏ
	Vector3 operator^(Vector3 vector) {
		return Vector3(
			y*vector.z - z * vector.y,
			z*vector.x - x * vector.z,
			x*vector.y - y * vector.x
		);
	}

	bool operator==(Vector3 vector) {
		if (x == vector.x && y == vector.y && z == vector.z) {
			return true;
		}
		return false;
	}

	bool operator!=(Vector3 vector) {
		if (x == vector.x && y == vector.y && z == vector.z) {
			return false;
		}
		return true;
	}


	//’·‚³‚ğ•Ô‚·ŠÖ”
	float Magnitude() {
		return x * x + y * y + z * z;
	}

	//’PˆÊƒxƒNƒgƒ‹‚ğ•Ô‚·ŠÖ”
	Vector3 UnitVector() {
		return Vector3(x / Magnitude(), y / Magnitude(), z / Magnitude());
	}

	void Set(float _x, float _y, float _z) {
		x = _x;
		y = _y;
		z = _z;
	}

	float GetX() {
		return x;
	}

	float GetY() {
		return y;
	}

	float GetZ() {
		return z;
	}

private:
	float x, y, z;
};



