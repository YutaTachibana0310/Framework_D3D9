//=====================================
//
//フレームワークヘッダ[Framework.h]
//Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _FRAMEWORK_H_
#define _FRAMEWORK_H_

#include "../main.h"
#include "../Framework\Core\BaseGame.h"

/**************************************
マクロ定義
***************************************/

/**************************************
クラス定義
***************************************/
class Framework : public BaseGame
{
public:
	Framework(HINSTANCE hInstance, HWND hWnd);

	void Update();
};

#endif