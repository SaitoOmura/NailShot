#include "Balloon.h"
#include "../../Utility/UserTemplate.h"
#include "../../Utility/ResourceManager.h"
#include "../../System/System.h"
#include "../ObjectManager.h"
#include "../../System/StageData.h"
#include "DxLib.h"

Balloon::Balloon() :
	break_animation(NULL),
	animation_count(0),
	animation_num(0),
	break_flag(FALSE)
{

}

Balloon::~Balloon()
{

}

void Balloon::Initialize()
{
	ResourceManager* rm = ResourceManager::GetInstance();
	graphic_images = rm->GetImages("Resource/Objects/Balloon/Balloon.png",1,1,1,40,40)[0];
	break_animation = rm->GetImages("Resource/Objects/Balloon/Break_Balloon.png", 3, 3, 1, 40, 40);
	sounds = rm->GetSounds("Resource/Sounds/SE/Balloon.mp3");
	box_size = 20.0f;
	z_layer = 2;
	object_collision.object_type = eObjectType::eBalloon;
	object_collision.hit_object_type.push_back(eObjectType::eNail);
}

void Balloon::Update()
{
	if (break_flag == TRUE)
	{
		AnimationControl();
	}
}

void Balloon::Draw() const
{
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, graphic_images, TRUE, direction);

	__super::Draw();
}

void Balloon::Finalize()
{

}

void Balloon::OnHitCollision(ObjectBase* target)
{
	Collision tc = target->GetObjectCollision();
	if (tc.object_type == eObjectType::eNail && break_flag == false)
	{
		ResourceManager* rm = ResourceManager::GetInstance();
		break_flag = TRUE;
		graphic_images = break_animation[animation_num];
		StageData* sd = StageData::GetInstance();
		sd->AddScore(1);
		rm->PlaySoundBack(sounds, true);
	}
}

void Balloon::AnimationControl()
{
	animation_count ++;
	if (animation_count >= 5)
	{
		if (animation_num < 2)
		{
			animation_num++;
			animation_count = 0;
			graphic_images = break_animation[animation_num];
		}
		else
		{

			ObjectManager* om = ObjectManager::GetInstance();
			om->DestroyGameObject(this);
		
		}
	}
}
