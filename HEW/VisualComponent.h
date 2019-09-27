#pragma once
#include "Component.h"

//ポジションの基準値。基本は真ん中だが変更可能
typedef enum Criterion {
	CENTER,
	LEFT_UP,
	UP,
	RIGHT_UP,
	RIGHT,
	RIGHT_DOWN,
	DOWN,
	DOWN_LEFT,
	LEFT
};

class VisualComponent :	public Component {
public:
	VisualComponent();
	~VisualComponent();

	//描画に干渉するコンポーネントである時これをオーバーライドして使用。
	virtual void Draw();

	//最後に描画する用の関数。UIなどを想定
	virtual void LateDraw();

};

