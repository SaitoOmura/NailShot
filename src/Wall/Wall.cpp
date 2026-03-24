#include "Wall.h"
#include "../../Utility/ResourceManager.h"

Wall::Wall()
{

}

Wall::~Wall()
{

}

void Wall::Initialize()
{
	ResourceManager* rm = ResourceManager::GetInstance();
	graphic_images = (rm->GetImages("Resource/Objects/Tile/Tile1.png"))[0];
	box_size = 20.0f;
	object_collision.object_type = eObjectType::eBlock;
	z_layer = 2;
}

void Wall::Draw() const
{
	DrawRotaGraphF(location.x, location.y, 1.0, 0.0, graphic_images, TRUE);
	__super::Draw();
}

void Wall::Finalize()
{
	
}