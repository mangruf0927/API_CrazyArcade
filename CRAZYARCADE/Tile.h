#pragma once
#include "Object.h"
#include "enum.h"

class Tile : public Object
{
private:
	//const TCHAR* tileKey;
	int drawKey;
	//BLOCKTYPE blockType;

	/*bool isPass;
	bool isPush;
	bool isBroken;*/

public :
	Tile();
	~Tile();

	virtual void Init() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	//void SetTileKey(TCHAR* skey) { tileKey = skey; }
	//const TCHAR* GetTileKey() { return tileKey; }

	//void SetTile(BLOCKTYPE type) { blockType = type; }
	//BLOCKTYPE GetTile() { return blockType; }

	void SetDrawKey(int dkey) { drawKey = dkey; }
	int GetDrawKey() { return drawKey; }
	//void SetTileType();
};

