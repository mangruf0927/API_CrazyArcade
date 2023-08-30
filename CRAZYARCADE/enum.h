#pragma once

enum class OBJTYPE
{
	DEFAULT, 
	PUSHBOX, 
	BOX,
	OBJECT,
	ITEM,
	BALLOON, 
	FLOW,
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
	PUSHBLOCK, // 밀리고 부숴지는 블럭
	BLOCK, // 부숴지는 블럭
	OBJECT, // 밀리지도 않고 부숴지지도 않는 블럭
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