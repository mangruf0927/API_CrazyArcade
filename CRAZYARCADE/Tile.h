#pragma once
#include "Object.h"
#include "enum.h"

class Tile : public Object
{
private:
	TCHAR* tileKey;
	BLOCKTYPE blockType;

public :
	Tile();
	~Tile();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	void SetTileKey(TCHAR* key) { tileKey = key; }
	TCHAR* GetTileKey() { return tileKey; }

	void SetTile(BLOCKTYPE type) { blockType = type; }
	BLOCKTYPE GetTile() { return blockType; }
};

