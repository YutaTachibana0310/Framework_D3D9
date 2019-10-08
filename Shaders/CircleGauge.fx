//=====================================
//
//�~�`�Q�[�W�V�F�[�_[CircleGauge.fx]
//Author:GP12B332 21 ���ԗY��
//
//=====================================

/***************************************
�O���[�o���ϐ�
***************************************/
float percent;			//�Q�[�W���ǂ��܂ŕ\�����邩��% ( 0.0f ~ 1.0f)
float4x4 transform;		//���_�ϊ��s��
float4x4 projection;	//�X�N���[�����e�s��

/***************************************
�e�N�X�`���T���v��
***************************************/
sampler s0 : register(s0);

/***************************************
���_�V�F�[�_�o�͍\����
***************************************/
struct VS_OUTPUT
{
	float4 pos	: POSITION;
	float2 tex	: TEXCOORD0;
	float2 uv	: TEXCOORD1;
};

/***************************************
���_�V�F�[�_
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
�s�N�Z���V�F�[�_(�E�n�_)
***************************************/
float4 PS_RIGHT(VS_OUTPUT In) : COLOR0
{
	//UV���W����p�x�����߂�
	float rad = atan2(In.uv.y, In.uv.x);

	//-PI ~ PI �� 0 ~ 1�@�ɕϊ�����
	float val = (rad + 3.1415) / (6.283);

	//�������l�ȉ��Ȃ�\�����Ȃ�
	clip(val - percent - 0.0001f);

	return tex2D(s0, In.tex);
}

/***************************************
�s�N�Z���V�F�[�_�i��n�_�j
***************************************/
float4 PS_TOP(VS_OUTPUT In) : COLOR0
{
	//UV���W����p�x�����߂�
	float rad = atan2(In.uv.x, -In.uv.y);

	//-PI ~ PI �� 0 ~ 1�@�ɕϊ�����
	float val = (rad + 3.1415) / (6.283);

	//�������l�ȉ��Ȃ�\�����Ȃ�
	clip(val - percent - 0.0001f);

	return tex2D(s0, In.tex);
}

/***************************************
�s�N�Z���V�F�[�_�i���n�_�j
***************************************/
float4 PS_LEFT(VS_OUTPUT In) : COLOR0
{
	//UV���W����p�x�����߂�
	float rad = atan2(-In.uv.y, -In.uv.x);

	//-PI ~ PI �� 0 ~ 1�@�ɕϊ�����
	float val = (rad + 3.1415) / (6.283);

	//�������l�ȉ��Ȃ�\�����Ȃ�
	clip(val - percent - 0.0001f);

	return tex2D(s0, In.tex);
}

/***************************************
�s�N�Z���V�F�[�_�i���n�_�j
***************************************/
float4 PS_BOTTOM(VS_OUTPUT In) : COLOR0
{
	//UV���W����p�x�����߂�
	float rad = atan2(-In.uv.x, In.uv.y);

	//-PI ~ PI �� 0 ~ 1�@�ɕϊ�����
	float val = (rad + 3.1415) / (6.283);

	//�������l�ȉ��Ȃ�\�����Ȃ�
	clip(val - percent - 0.0001f);

	return tex2D(s0, In.tex);
}

/***************************************
�e�N�j�b�N
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