#pragma once
#include "Component.h"

//ポジションの基準値。基本は真ん中だが変更可能
typedef enum Criterion {
	CENTER = (0 + 0),
	LEFT = (0 + 1),
	RIGHT = (0 + 2),
	UP = (4 + 0),
	UP_LEFT = (4 + 1),
	UP_RIGHT = (4 + 2),
	DOWN = (8 + 0),
	DOWN_LEFT = (8 + 1),
	DOWN_RIGHT = (8 + 2),
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

