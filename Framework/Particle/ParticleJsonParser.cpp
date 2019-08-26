//=====================================
//
//パーティクルJSONパーサ処理[ParticleJsonParser.cpp]
//Author:GP12B332 21 立花雄太
//
//=====================================
#include "ParticleJsonParser.h"
#include "../../json11/json11.hpp"
#include <fstream>

using namespace std;
/**************************************
マクロ定義
***************************************/

/**************************************
コンストラクタ
***************************************/
ParticleJsonParser::ParticleJsonParser(const char * fileName)
{
	//JSONファイルを開く
	string filePath = "data/PARTICLE/" + string(fileName);
	ifstream ifs;
	ifs.open(filePath, std::ios::in);

	//成功確認
	assert(ifs.is_open());

	//JSONデータを読み込み
	const string json((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
	ifs.close();

	string err;
	json11::Json data = json11::Json::parse(json, err);

	assert(err.empty());

	//JSONデータをパース
	texturePath = data["texturePath"].string_value();
	particleMax = data["particleMax"].int_value();
	emitterMax = data["emitterMax"].int_value();
	emitNumMin = data["emitNumMin"].int_value();
	emitNumMax = data["emitNumMax"].int_value();
	durationMin = data["durationMin"].int_value();
	durationMax = data["durationMax"].int_value();
}

/**************************************
テクスチャパス取得
***************************************/
std::string ParticleJsonParser::TexturePath() const
{
	return texturePath;
}

/**************************************
パーティクル最大数取得
***************************************/
int ParticleJsonParser::ParticleMax() const
{
	return particleMax;
}

/**************************************
エミッタ最大数取得
***************************************/
int ParticleJsonParser::EmitterMax() const
{
	return emitterMax;
}

/**************************************
放出数取得
***************************************/
int ParticleJsonParser::EmitNum() const
{
	if (emitNumMin != 0 && emitNumMax != 0)
		return Math::RandomRange(emitNumMin, emitNumMax);
	
	if (emitNumMax != 0)
		return emitNumMax;

	return emitNumMin;
}

/**************************************
放出期間取得
***************************************/
int ParticleJsonParser::Duration() const
{
	if (durationMin != 0 && durationMax != 0)
		return Math::RandomRange(durationMin, durationMax);

	if (durationMax != 0)
		return durationMax;

	return durationMin;
}
