#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

class GameMap {
private:
	enum TileType {
		Blank,
		Player,
		Door
	};

	map<TileType, string> TileMap = {
		{TileType::Blank, "   "},
		{TileType::Player,"(P)"},
		{TileType::Door,"[|]"}
	};

	class Tile {
	public:
		TileType type;
		Tile() :type(TileType::Blank) {}
		Tile(TileType tt) :type(tt) {}
	};

	vector<vector<Tile>> map;
	vector<vector<Tile>> EmptyMap(int x, int y) {
		vector<vector<Tile>> result(y, vector<Tile>(x));
		return result;
	}
public:
	string MapString() {
		if (map.size() == 0 || map[0].size() == 0) return "";
		string rowstr = "-";
		for (int i = 0; i < map[0].size(); i++) {
			rowstr += "----";
		}
		string mapstr = rowstr;
		for (int i = 0; i < map.size(); i++) {
			mapstr += "\n|";
			for (int j = 0; j < map[i].size(); j++)
				mapstr += TileMap[map[i][j].type] + "|";
			mapstr += "\n" + rowstr;
		}
		return mapstr;
	}
	GameMap GeneratePlayer() {
		map[map.size() / 2][map[0].size() / 2].type = TileType::Player;
		return *this;
	}
	GameMap() :map(EmptyMap(0, 0)) {}
	GameMap(int x, int y) :map(EmptyMap(x, y)) {}
};

int main()
{
	int x, y;
	scanf("%d%d", &x, &y);
	GameMap gm(x, y);
	cout << gm.GeneratePlayer().MapString() << endl;
	
	/*
	-------------------------
	|   |   |mOm|   |   |   |
	-------------------------
	|   |   |]8[|   |   |   |
	-------------------------
	|   |   |(P)|[|]|   |   |
	-------------------------
	*/
	return 0;
}