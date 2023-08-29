#pragma once

enum OBJTYPE
{
	DEFAULT, 
	TILE, 
	BLOCK,
	ITEM,
	BALLOON, 
	PLAYER, 
	MONSTER, 
	END
};

enum class SCENETYPE
{
	START,
	LOBBY,
	STAGE1,
	STAGE2,
	STAGE3,
	TOOL,
	END
};

enum class BLOCKTYPE
{
	NONE,
	PUSHBLOCK, // �и��� �ν����� ��
	BLOCK, // �ν����� ��
	OBJECT, // �и����� �ʰ� �ν������� �ʴ� ��
	END
};

enum class ITEM
{
	SKATE,
	POTION,
	MAXPOTION,
	BALLOON,
	END
};