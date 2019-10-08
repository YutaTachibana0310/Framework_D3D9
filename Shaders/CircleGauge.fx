//=====================================
//
//円形ゲージシェーダ[CircleGauge.fx]
//Author:GP12B332 21 立花雄太
//
//=====================================

/***************************************
グローバル変数
***************************************/
float percent;			//ゲージをどこまで表示するかの% ( 0.0f ~ 1.0f)
float4x4 transform;		//頂点変換行列
float4x4 projection;	//スクリーン投影行列

/***************************************
テクスチャサンプラ
***************************************/
sampler s0 : register(s0);

/***************************************
頂点シェーダ出力構造体
***************************************/
struct VS_OUTPUT
{
	float4 pos	: POSITION;
	float2 tex	: TEXCOORD0;
	float2 uv	: TEXCOORD1;
};

/***************************************
頂点シェーダ
***************************************/
VS_OUTPUT VS(
	float4 pos : POSITION,
	float4 color : COLOR0,
	float2 tex : TEXCOORD0)
{
	VS_OUTPUT Out;

	Out.pos = mul(mul(pos, transform), projection);
	Out.tex = tex;
	Out.uv = 0.5f - tex;

	return Out;
}

/***************************************
ピクセルシェーダ(右始点)
***************************************/
float4 PS_RIGHT(VS_OUTPUT In) : COLOR0
{
	//UV座標から角度を求める
	float rad = atan2(In.uv.y, In.uv.x);

	//-PI ~ PI を 0 ~ 1　に変換する
	float val = (rad + 3.1415) / (6.283);

	//しきい値以下なら表示しない
	clip(val - percent - 0.0001f);

	return tex2D(s0, In.tex);
}

/***************************************
ピクセルシェーダ（上始点）
***************************************/
float4 PS_TOP(VS_OUTPUT In) : COLOR0
{
	//UV座標から角度を求める
	float rad = atan2(In.uv.x, -In.uv.y);

	//-PI ~ PI を 0 ~ 1　に変換する
	float val = (rad + 3.1415) / (6.283);

	//しきい値以下なら表示しない
	clip(val - percent - 0.0001f);

	return tex2D(s0, In.tex);
}

/***************************************
ピクセルシェーダ（左始点）
***************************************/
float4 PS_LEFT(VS_OUTPUT In) : COLOR0
{
	//UV座標から角度を求める
	float rad = atan2(-In.uv.y, -In.uv.x);

	//-PI ~ PI を 0 ~ 1　に変換する
	float val = (rad + 3.1415) / (6.283);

	//しきい値以下なら表示しない
	clip(val - percent - 0.0001f);

	return tex2D(s0, In.tex);
}

/***************************************
ピクセルシェーダ（下始点）
***************************************/
float4 PS_BOTTOM(VS_OUTPUT In) : COLOR0
{
	//UV座標から角度を求める
	float rad = atan2(-In.uv.x, In.uv.y);

	//-PI ~ PI を 0 ~ 1　に変換する
	float val = (rad + 3.1415) / (6.283);

	//しきい値以下なら表示しない
	clip(val - percent - 0.0001f);

	return tex2D(s0, In.tex);
}

/***************************************
テクニック
***************************************/
technique tech
{
	pass P0
	{
		VertexShader = compile vs_1_1 VS();
		PixelShader = compile ps_2_0 PS_RIGHT();
	}
	pass P1
	{
		VertexShader = compile vs_1_1 VS();
		PixelShader = compile ps_2_0 PS_TOP();
	}
	pass P2
	{
		VertexShader = compile vs_1_1 VS();
		PixelShader = compile ps_2_0 PS_LEFT();
	}
	pass P3
	{
		VertexShader = compile vs_1_1 VS();
		PixelShader = compile ps_2_0 PS_BOTTOM();
	}
};