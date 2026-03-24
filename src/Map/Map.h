#pragma once

#include <vector>
#include "../ObjectBase.h"
#include "../../System/ProjectConfig.h"
//#include "../Tile/Tile.h"

const int MAP_WIDTH = 32;
const int MAP_HEIGHT = 18;
#define MAPCHIP_SIZE (40)

class Map
{
private:
	// マップデータを保存する二次元配列
	std::vector<std::vector<char>> map_data;
	// タイル画像の読み込み
	int tileImages[3];
	int tile_image;
	int balloon_image;

//private:
//	std::vector<ObjectBase*>tiles; // タイルをオブジェクトとして管理
public:
	Map();
	~Map();

	void Load(int mapData[MAP_HEIGHT][MAP_WIDTH], int tileImages[]);
	// csvを読み込んでステージの情報配列を作成
	std::vector<std::vector<char>> Load(std::string file_path);
	void Draw();
	bool CanMove(float x, float y);

	// マップとの当たり判定
	bool MapCollision(ObjectBase* object, int x, int y);
};