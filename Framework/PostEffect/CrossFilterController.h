//=====================================
//
//クロスフィルタコントローラヘッダ[CrossFilterController.h]
//Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _CROSSFILTERCONTROLLER_H_
#define _CROSSFILTERCONTROLLER_H_

#include "../../main.h"
#include "BaseEffectController.h"

/**************************************
前方宣言
***************************************/
class CrossBlurFilter;
class BloomFilter;

/**************************************
クラス定義
***************************************/
class CrossFilterController : public BaseEffectController
{
public:
	CrossFilterController();
	~CrossFilterController();

	void Draw(LPDIRECT3DTEXTURE9 targetTexture);
	void SetPower(float power1, float power2, float power3);
	void SetThrethold(float threthold1, float threthold2, float threthold3);

	static const float DefaultPower;
	static const float DefaultThrethold;

private:
	enum Const
	{
		NumReduction = 3,
		NumBlur = 2
	};

	void SampleBrightness(LPDIRECT3DTEXTURE9 targetTexture);
	void ProcessBlur();
	void BlendBloom();

	BloomFilter *bloomFilter[NumReduction];
	BloomFilter *bloomBlender;
	CrossBlurFilter *blurFilter[NumReduction];

	LPDIRECT3DTEXTURE9 blurTexture[NumReduction][NumBlur];
	LPDIRECT3DSURFACE9 blurSurface[NumReduction][NumBlur];

	D3DVIEWPORT9 blurViewPort[NumReduction];
	D3DVIEWPORT9 oldViewPort;

	int cntBlur;

	float bloomPower[NumReduction];
	float bloomThrethold[NumReduction];

	DWORD reducedWidth[NumReduction];
	DWORD reducedHeight[NumReduction];

};

#endif