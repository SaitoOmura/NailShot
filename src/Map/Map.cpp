#include "Map.h"
#include "DxLib.h"

#include "../../Utility/ResourceManager.h"
#include "../../System/StageData.h"

#include <fstream>
#include <iostream>
#include <sstream>

// �R���X�g���N�^
Map::Map()
{
	// �摜�Ǘ��N���X�̌Ăяo��
	ResourceManager* rm = ResourceManager::GetInstance();

	tileImages[0] = 0;
	tileImages[1] = (rm->GetImages("Resource/Objects/Tile/Tile1.png"))[0];
	tileImages[2] = (rm->GetImages("Resource/Objects/Tile/Tile2.png"))[0];
	balloon_image = (rm->GetImages("Resource/Objects/Balloon/Balloon.png"))[0];

	StageData* sd = StageData::GetInstance();
	int s_number = sd->GetNowStageNumber();

	switch (s_number)
	{
	case 1:
		map_data = Load("Resource/Map/MapData/Stage_Data1.csv");
		break;
	case 2:
		map_data = Load("Resource/Map/MapData/Stage_Data2.csv");
		break;
	case 3:
		map_data = Load("Resource/Map/MapData/Stage_Data3.csv");
		break;
	case 4:
		map_data = Load("Resource/Map/MapData/Stage_Data4.csv");
		break;
	case 5:
		map_data = Load("Resource/Map/MapData/Stage_Data5.csv");
		break;
	case 6:
		map_data = Load("Resource/Map/MapData/Stage_Data6.csv");
		break;
	case 7:
		map_data = Load("Resource/Map/MapData/Stage_Data7.csv");
		break;
	case 8:
		map_data = Load("Resource/Map/MapData/Stage_Data8.csv");
		break;
	case 9:
		map_data = Load("Resource/Map/MapData/Stage_Data9.csv");
		break;
	case 10:
		map_data = Load("Resource/Map/MapData/Stage_Data10.csv");
		break;
	default:
		break;
	}
}

// �f�X�g���N�^
Map::~Map()
{
	//for (auto tile : tiles)delete tile;
}

void Map::Load(int mapData[MAP_HEIGHT][MAP_WIDTH], int tileImages[])
{
	//for (int y = 0; y < MAP_HEIGHT; y++)
	//{
	//	for (int x = 0; x < MAP_WIDTH; x++)
	//	{
	//		int tileID = mapData[y][x];
	//		float px = x * TILE_SIZE;
	//		float py = y * TILE_SIZE;

	//		switch (tileID)
	//		{
	//		default:
	//			tiles.push_back(new Tile(px, py, tileImages[tileID]));
	//			break;
	//		}
	//	}
	//}
}

// csv��ǂݍ���ŃX�e�[�W�̏��z���쐬
std::vector<std::vector<char>> Map::Load(std::string file_path)
{
	// �ǂݍ��ރt�@�C������w��
	std::string file_name = file_path;
	// �w��t�@�C����ǂݍ���
	std::ifstream ifs(file_name);

	// �G���[�`�F�b�N
	if (ifs.fail())
	{
		throw (file_name + "I can't open it.\n");
	}

	// �߂�l�p�}�b�v���z��
	std::vector<std::vector<char>> data;
	// csv��1�s�̕������ۑ�����ϐ�
	std::string line;

	// getline��csv�t�@�C����1�s�̕������ǂݍ��݁A�����line�ɑ��
	while (std::getline(ifs, line))
	{
		std::vector<char> row;
		// line�ɓ����Ă��镶�����J���}��؂�ŕ���
		std::stringstream ss(line);
		std::string cell;

		// getline�ŃJ���}�ŋ�؂�ꂽ������ǂݍ���
		while (std::getline(ss, cell, ','))
		{
			// �ŏ��̕����݂̂𒊏o
			row.push_back(cell[0]);
		}
		// �P�s�̕������S�ĕ������ꂽ��ԂŊi�[
		data.push_back(row);
	}

	// �쐬�����X�e�[�W�̏��z��
	return data;
}

void Map::Draw()
{
	//for (auto tile : tiles)
	//{
	//	tile->Draw();
	//}

		// �摜�Ǘ��N���X�̌Ăяo��
	ResourceManager* rm = ResourceManager::GetInstance();

	// �}�b�v���̏c�̕���
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		// �}�b�v���̉��̕���
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			// �P�����𒊏o
			char c = map_data[i][j];
			// �����Ă��镶���ŉ摜�̕ύX
			switch (c)
			{
				// ��
				// �󒆂̂�̂͋�̉摜��\���Ă���
				
				// �n��
			case '1':
			//case '4':
				tile_image = tileImages[2];
				break;
				// �n�ʂ̒�
			case '2':
			//case '3':
				tile_image = tileImages[1];
				break;
			/*case '5':
				tile_image = balloon_image;
				break;*/
				// �ȉ��ɒǉ�
			default:
				continue;
			}
			// �}�b�v������ĕ`��
			DrawRotaGraphF((MAPCHIP_SIZE / 2) + (MAPCHIP_SIZE * j), (MAPCHIP_SIZE / 2) + (MAPCHIP_SIZE * i), 1.0, 0.0, tile_image, TRUE);
		}
	}
}

bool Map::CanMove(float x, float y)
{
	//for (auto tile : tiles)
	//{
	//	if (!tile->IsWalkable())
	//	{
	//		return false;
	//	}
	//}
	return true;
}

bool Map::MapCollision(ObjectBase* object, int x, int y)
{
	// 座標を保存
	Vector2D object_rect = object->GetLocation() - (MAPCHIP_SIZE / 2);
	// サイズを保存
	Vector2D object_box = object->GetBoxSize();

	// 範囲外だったらあたってない
	if (object_rect.x < 0 || object_rect.x  >= D_WINDOW_SIZE_X - object_box.x)
	{
		return true; // マップ範囲外
	}
	if (object_rect.y < 0 || object_rect.y >= D_WINDOW_SIZE_Y - object_box.y)
	{
		return false;
	}
	 
	// 四つの頂点を保存
	Vector2D vertices[4] =
	{
		// 左上の座標
		Vector2D(object_rect - object_box),
		// 左下の座標
		Vector2D(object_rect.x - object_box.x, object_rect.y + object_box.y),
		// 右上の座標
		Vector2D(object_rect.x + object_box.x, object_rect.y - object_box.y),
		// 右下の座標
		Vector2D(object_rect + object_box),
	};

	for (int i = 0; i < 4; i++)
	{
		// プレイヤーの現在のマスの位置
		int x_id = std::floor(vertices[i].x) / MAPCHIP_SIZE;
		int y_id = std::floor(vertices[i].y) / MAPCHIP_SIZE;
		// 当たり判定を付ける背景
		if (map_data[y_id + y][x_id + x] == '1')
		{
			// どのポイントが当たっているか
			int id = i;
			// 当たっている
			return true;
		}
	}
	// 当たっていない
	return false;
}
