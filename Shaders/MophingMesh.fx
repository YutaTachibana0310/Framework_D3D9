//=====================================
//
//�C���X�^���V���O���b�V���V�F�[�_[ModelInstancing.fx]
//Author:GP12B332 21 ���ԗY��
//
//=====================================

/**************************************
*�O���[�o���ϐ�
***************************************/
float4x4 mtxWorld;				//���[���h�s��
float4x4 mtxView;				//�r���[�s��
float4x4 mtxProjection;			//�v���W�F�N�V�����s��

float4 materialDiffuse;			//�}�e���A���f�B�t���[�Y
float4 materialAmbient;			//�}�e���A���A���r�G���g
float4 materialSpecular;		//�}�e���A���X�y�L�����[

float4 nextMaterialDiffuse;		//���̃}�e���A���f�B�t���[�Y
float4 nextMaterialAmbient;		//���̃}�e���A���A���r�G���g
float4 nextMaterialSpecular;	//���̃}�e���A���X�y�L����

float4 lightDiffuse[3];			//���C�g�f�B�t���[�Y
float4 lightAmbient[3];			//���C�g�A���r�G���g
float4 lightSpecular[3];		//���C�g�X�y�L����
float4 lightDirection[3];		//���C�g����

float t;						//�ω���

texture nextTexture;			//�ω���̃e�N�X�`��

/**************************************
*�e�N�X�`���T���v���[
***************************************/
sampler s0 : register(s0);

sampler nextSampler = sampler_state
{
	Texture = <nextTexture>;
	MagFilter = Linear;
	MinFilter = Linear;
};

/**************************************
*���_�V�F�[�_�o�͍\����
***************************************/
struct VS_OUT {
	float4 pos	: POSITION;
	float2 uv1	: TEXCOORD0;
	float2 uv2 : TEXCOORD1;
	float4 color : COLOR0;
};

/**************************************
*���_�V�F�[�_
***************************************/
VS_OUT VS(
	float3 pos0 : POSITION0,
	float3 normal0 : NORMAL0,
	float2 uv0 : TEXCOORD0,
	float3 pos1 : POSITION1,
	float3 normal1 : NORMAL1,
	float2 uv1 : TEXCOORD1)
{
	VS_OUT Out = (VS_OUT)0;

	//���_�ϊ�
	float3 position = lerp(pos0, pos1, t);
	Out.pos = mul(float4(position, 1.0f), mtxWorld);
	Out.pos = mul(Out.pos, mtxView);
	Out.pos = mul(Out.pos, mtxProjection);

	//�@�������[���h�ϊ�
	float3 N = mul(lerp(normal0, normal1, t), (float3x3)mtxWorld);
	N = normalize(N);

	//UV���W���i�[
	Out.uv1 = uv0;
	Out.uv2 = uv1;

	//���C�g�ɂ��F���v�Z
	float4 diffuse = (float4)0;
	float4 ambient = (float4)0;

	for (int i = 0; i < 3; i++)
	{
		float3 L = normalize(-lightDirection[i].xyz);
		diffuse += max(0.0f, dot(L, N)) * lightDiffuse[i];
		ambient += lightAmbient[i];
	}

	float4 matDiffuse = float4(lerp(materialDiffuse.rgb, nextMaterialDiffuse.rgb, t), 1.0f);
	float4 matAmbient = lerp(materialAmbient, nextMaterialAmbient, t);
	Out.color = saturate(diffuse * matDiffuse + ambient * matAmbient);

	Out.color.a = 1.0f;

	return Out;
}

/**************************************
*�s�N�Z���V�F�[�_
***************************************/
float4 PS(VS_OUT In) : COLOR0
{
	 float4 col0 = tex2D(s0, In.uv1);
	 float4 col1 = tex2D(nextSampler, In.uv2);
	 float4 texColor = lerp(col0, col1, t);

	 if (texColor.r == 0.0f && texColor.g == 0.0f && texColor.b == 0.0f)
		 return  In.color;
	 else
		 return texColor * In.color;
}

/**************************************
*�e�N�j�b�N
**************************************/
technique tech
{
	pass p0 {
		VertexShader = compile vs_2_0 VS();
		PixelShader = compile ps_2_0 PS();
	}
};