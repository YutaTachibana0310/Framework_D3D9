//=====================================
//
// TransformTest.cpp
// 機能:トランスフォームテストシーン
// Author:GP12B332 21 立花雄太
//
//=====================================
#include "TransformTest.h"
#include "../Framework/Renderer3D/TransformObject.h"
#include "../Framework/Renderer3D/BoardPolygon.h"
#include "../Framework/Resource/ResourceManager.h"
#include "../Framework/Tool/DebugWindow.h"

/**************************************
グローバル変数
***************************************/

/**************************************
初期化処理
***************************************/
void TransformTestScene::Init()
{
	ResourceManager::Instance()->MakePolygon("Transform", "data/TEXTURE/arrow.png", { 5.0f, 5.0f });

	sceneCamera = new Camera();
	Camera::SetMainCamera(sceneCamera);

	parent = new TransformObject();
	child = new ChildObject();

	parent->AddChild(child);
}

/**************************************
終了処理
***************************************/
void TransformTestScene::Uninit()
{
	SAFE_DELETE(child);
	SAFE_DELETE(parent);
	SAFE_DELETE(sceneCamera);
}

/**************************************
更新処理
***************************************/
void TransformTestScene::Update()
{
	sceneCamera->Update();

	Debug::Begin("Transform Test");

	Debug::Text("Parameter");

	static D3DXVECTOR3 position = Vector3::Zero;
	static D3DXVECTOR3 rotation = Vector3::Zero;
	static D3DXVECTOR3 scale = Vector3::One;
	Debug::Slider("Position", position, Vector3::One * -10.0f, Vector3::One * 10.0f);
	Debug::Slider("Rotation", rotation, Vector3::One * -180.0f, Vector3::One * 180.0f);
	Debug::Slider("Scale", scale, Vector3::Zero, Vector3::One * 10.0f);

	Debug::NewLine();
	Debug::Text("Parent");
	if (Debug::Button("Set Parent Position"))
		parent->SetPosition(position);
	if (Debug::Button("Set Parent Rotation"))
		parent->SetRotatition(rotation);
	if (Debug::Button("Set Parent Scale"))
		parent->SetScale(scale);

	Debug::NewLine();
	Debug::Text("Child");
	if (Debug::Button("Set Child Position"))
		child->SetPosition(position);
	if (Debug::Button("Set Child Rotation"))
		child->SetRotatition(rotation);
	if (Debug::Button("Set Child Scale"))
		child->SetScale(scale);
	if (Debug::Button("Set Child LocalPosition"))
		child->SetLocalPosition(position);
	if (Debug::Button("Set Child LocalRotation"))
		child->SetLocalRotatition(rotation);
	if (Debug::Button("Set Child LocalScale"))
		child->SetLocalScale(scale);

	Debug::NewLine();
	Debug::Text(parent->GetPosition(), "`Parent Position");
	Debug::Text(parent->GetRotation(), "Parent Rotation");
	Debug::Text(parent->GetScale(), "Parent Scale");

	Debug::NewLine();
	Debug::Text(child->GetPosition(), "Child Position");
	Debug::Text(child->GetRotation(), "Child Rotation");
	Debug::Text(child->GetScale(), "Child Scale");

	Debug::NewLine();
	Debug::Text(child->GetLocalPosition(), "Child LocalPosition");
	Debug::Text(child->GetLocalRotation(), "Child LocalRotation");
	Debug::Text(child->GetLocalScale(), "Child LocalScale");
	Debug::End();

	D3DXQUATERNION test = Quaternion::ToQuaternion({ 0.0f, 0.0f, 90.0f });

}

/**************************************
描画処理
***************************************/
void TransformTestScene::Draw()
{
	sceneCamera->Set();

	parent->Draw();

	child->Draw();
}

/**************************************
描画処理
***************************************/
ChildObject::ChildObject() :
	polygon(nullptr)
{
	polygon = new BoardPolygon();
	ResourceManager::Instance()->GetPolygon("Transform", polygon);
}

/**************************************
描画処理
***************************************/
ChildObject::~ChildObject()
{
	SAFE_DELETE(polygon);
}

/**************************************
描画処理
***************************************/
void ChildObject::Draw()
{
	polygon->Draw(transform->GetMatrix());
}
