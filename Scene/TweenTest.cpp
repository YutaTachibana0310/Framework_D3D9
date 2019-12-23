//=====================================
//
// TweenTest.cpp
// 機能:トゥイーンテスト
// Author:GP12B332 21 立花雄太
//
//=====================================
#include "TweenTest.h"
#include "../Framework/Camera/Camera.h"
#include "../Framework/Renderer2D/Polygon2D.h"
#include "../Framework/Tween/Tween.h"
#include "../Framework/Tool/DebugWindow.h"
#include "../Library/nameof/nameof.hpp"
#include "../Framework/Renderer2D/TextViewer.h"

/**************************************
グローバル変数
***************************************/

/**************************************
初期化処理
***************************************/
void TweenTestScene::Init()
{
	sceneCamera = new Camera();
	Camera::SetMainCamera(sceneCamera);

	polygon = std::make_shared<Polygon2D>();
	polygon->SetPosition({ SCREEN_CENTER_X, SCREEN_CENTER_Y, 0.0f });
	polygon->SetSize({ 300.0f, 300.0f });
	polygon->LoadTexture("data/TEXTURE/circle.png");

	text = new TextViewer("", 300);
	text->SetPos((int)SCREEN_CENTER_X, 100);
	text->SetText("aaaaaaa");
	widthTextOutline = 5;
	useTextOutline = true;
	text->SetOutlineColor({ 1.0f, 0.0f, 0.0f, 0.5f });

	useExpand = true;
	close = 0;
	expand = 0;
	expandType = ExpandType::LeftToRight;
	closeType = CloseType::LeftToRight;
	easeType = EaseType::OutCubic;

	Tween::Expand(polygon, expandType, 60, easeType, [this]()
	{
		OnFinish();
	});
}

/**************************************
終了処理
***************************************/
void TweenTestScene::Uninit()
{
	SAFE_DELETE(sceneCamera);
	polygon.reset();
}

/**************************************
更新処理
***************************************/
void TweenTestScene::Update()
{
	sceneCamera->Update();

	Debug::Begin("TweenTest");

	Debug::CheckBox("Expand", useExpand);

	Debug::Text("expand");
	if (Debug::RadioButton("LtoR", expand, 0))
	{
		expandType = ExpandType::LeftToRight;
	}
	if (Debug::RadioButton("RtoL", expand, 1))
	{
		expandType = ExpandType::RightToLeft;
	}
	if (Debug::RadioButton("UtoD", expand, 2))
	{
		expandType = ExpandType::UpToDown;
	}
	if (Debug::RadioButton("DtoU", expand, 3))
	{
		expandType = ExpandType::DownToUp;
	}
	if (Debug::RadioButton("toUD", expand, 4))
	{
		expandType = ExpandType::ToUpDown;
	}
	if (Debug::RadioButton("toLR", expand, 5))
	{
		expandType = ExpandType::ToLeftRight;
	}

	Debug::NewLine();
	Debug::Text("close");
	if (Debug::RadioButton("C LtoR", close, 0))
	{
		closeType = CloseType::LeftToRight;
	}
	if (Debug::RadioButton("C RtoL", close, 1))
	{
		closeType = CloseType::RightToLeft;
	}
	if (Debug::RadioButton("C UtoD", close, 2))
	{
		closeType = CloseType::UpToDown;
	}
	if (Debug::RadioButton("C DtoU", close, 3))
	{
		closeType = CloseType::DownToUp;
	}
	if (Debug::RadioButton("C toUD", close, 4))
	{
		closeType = CloseType::FromUpDown;
	}
	if (Debug::RadioButton("C toLR", close, 5))
	{
		closeType = CloseType::FromLeftRight;
	}

	Debug::NewLine();
	Debug::Text("Text");
	if (Debug::Slider("Width", widthTextOutline, 0, 100))
	{
		text->SetOutlineWidth(widthTextOutline);
	}
	if (Debug::CheckBox("Use Outline", useTextOutline))
	{
		text->UseOutLine(useTextOutline);
	}

	Debug::End();
}

/**************************************
描画処理
***************************************/
void TweenTestScene::Draw()
{
	sceneCamera->Set();

	polygon->Draw();

	text->Draw();
}

/**************************************
コールバック
***************************************/
void TweenTestScene::OnFinish()
{
	if (useExpand)
	{
		Tween::Expand(polygon, expandType, 60, easeType, [this]()
		{
			OnFinish();
		});
	}
	else
	{
		Tween::Close(polygon, closeType, 60, easeType, [this]()
		{
			OnFinish();
		});
	}
}
