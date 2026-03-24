#include "Break_Wall.h"
#include "../../Utility/ResourceManager.h"
#include "../ObjectManager.h"

Break_Wall::Break_Wall() :
	break_flag(FALSE)
{

}

Break_Wall::~Break_Wall()
{

}

void Break_Wall::Initialize()
{
	ResourceManager* rm = ResourceManager::GetInstance();
	graphic_images = (rm->GetImages("Resource/Objects/Tile/Tile3.png"))[0];
	sounds = rm->GetSounds("Resource/Sounds/SE/brake_wall.mp3");
	box_size = 24.0f;
	z_layer = 2;
	object_collision.object_type = eObjectType::eBrake_Block;
	object_collision.hit_object_type.push_back(eObjectType::eNail);
}

void Break_Wall::Draw() const
{
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, graphic_images, TRUE);
	__super::Draw();
}

void Break_Wall::Finalize()
{

}

void Break_Wall::OnHitCollision(ObjectBase* target)
{
	Collision tc = target->GetObjectCollision();
	if (tc.object_type == eObjectType::eNail)
	{
		ObjectManager* om = ObjectManager::GetInstance();
		PlaySoundMem(sounds, DX_PLAYTYPE_BACK, true);
		om->DestroyGameObject(this);
	}
}