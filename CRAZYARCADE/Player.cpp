#include "Player.h"
#include "BmpManager.h"
//#include "WaterBalloon.h"
//#include "Scene.h"
//#include "SceneManager.h"

Player::Player()
    :Speed(8.0f)
{
}

Player::~Player()
{
}

void Player::Init()
{
    // 65 X 76
    BmpManager::getInstance()->InsertBmp(L"Idle", L"Image/player/Bazzi/jump.bmp");
    BmpManager::getInstance()->InsertBmp(L"Down", L"Image/player/Bazzi/down.bmp");
    BmpManager::getInstance()->InsertBmp(L"Left", L"Image/player/Bazzi/left.bmp");
    BmpManager::getInstance()->InsertBmp(L"Right", L"Image/player/Bazzi/right.bmp");
    BmpManager::getInstance()->InsertBmp(L"Up", L"Image/player/Bazzi/up.bmp");
    BmpManager::getInstance()->InsertBmp(L"Trap", L"Image/player/Bazzi/trap.bmp");
    BmpManager::getInstance()->InsertBmp(L"Die", L"Image/player/Bazzi/die.bmp");
    BmpManager::getInstance()->InsertBmp(L"Live", L"Image/player/Bazzi/live.bmp");
    BmpManager::getInstance()->InsertBmp(L"Arrow", L"Image/player/solo_player.bmp");

    frameKey = L"Idle";

    Pos = { 15, 20 };
    frame.Cur = frame.Start;
    frame.Timer = GetTickCount();
}


void Player::Update()
{
    KeyUpdate();

    if (Pos.x < 15)
    {
        Pos.x += Speed;
    }
    if (Pos.x > 580)
    {
        Pos.x -= Speed;
    }
    if (Pos.y < 19)
    {
        Pos.y += Speed;
    }
    if (Pos.y > 500)
    {
        Pos.y -= Speed;
    }
}

void Player::LateUpdate()
{
}



void Player::Render(HDC hdc)
{
    HDC memDC;

    //HDC memDC3 = BmpManager::getInstance()->FindImage(L"Shadow");
    //GdiTransparentBlt(hdc, Info.Pos.x + 5, Info.Pos.y + 48, 40, 19, memDC3, 0, 0, 42, 19, RGB(255, 0, 255));

    if (frameKey == L"Idle")
    {
        frame.Start = 0;
        frame.End = 2;
        memDC = BmpManager::getInstance()->FindImage(L"Idle");
        GdiTransparentBlt(hdc, Pos.x, Pos.y, 50, 60, memDC, frame.Start * 64, 0, 64, 76, RGB(255, 0, 255));
        //Rectangle(hdc, Info.Pos.x + 5, Info.Pos.y + 20, Info.Pos.x + 45, Info.Pos.y + 60);
    }
    if (frameKey == L"Up")
    {
        frame.Start = 0;
        frame.End = 7;
        memDC = BmpManager::getInstance()->FindImage(L"Up");
        GdiTransparentBlt(hdc, Pos.x, Pos.y, 50, 60, memDC, frame.Cur * 64, 0, 64, 76, RGB(255, 0, 255));
    }
    if (frameKey == L"Right")
    {
        frame.Start = 0;
        frame.End = 5;
        memDC = BmpManager::getInstance()->FindImage(L"Right");
        GdiTransparentBlt(hdc, Pos.x, Pos.y, 50, 60, memDC, frame.Cur * 64, 0, 64, 76, RGB(255, 0, 255));

    }
    if (frameKey == L"Left")
    {
        frame.Start = 0;
        frame.End = 5;
        memDC = BmpManager::getInstance()->FindImage(L"Left");
        GdiTransparentBlt(hdc, Pos.x, Pos.y, 50, 60, memDC, frame.Cur * 64, 0, 64, 76, RGB(255, 0, 255));
    }
    if (frameKey == L"Down")
    {
        frame.Start = 0;
        frame.End = 7;
        memDC = BmpManager::getInstance()->FindImage(L"Down");
        GdiTransparentBlt(hdc, Pos.x, Pos.y, 50, 60, memDC, frame.Cur * 64, 0, 64, 76, RGB(255, 0, 255));
    }

    HDC memDC2 = BmpManager::getInstance()->FindImage(L"Arrow");
    GdiTransparentBlt(hdc, Pos.x + 14, Pos.y - 24, 20, 24, memDC2, 0, 0, 24, 28, RGB(255, 0, 255));


}

void Player::Release()
{
}

void Player::CreateBalloon()
{
    /*balloon = new WaterBalloon();
    balloon->SetPos((int)((Pos.x + 5) / 40) * 40 + 20, (int)((Pos.y + 19) / 40) * 40 + 40);

    Scene* CurScene = SceneManager::GetInstance()->GetCurScene();
    CurScene->addObject(balloon, OBJTYPE::BALLOON);*/
}



void Player::KeyUpdate()
{
    frameKey = L"Idle";

    if (GetKeyState(VK_DOWN) & 0x8000)
    {
        Pos.y += Speed;
        frameKey = L"Down";
    }
    else if (GetKeyState(VK_UP) & 0x8000)
    {
        Pos.y -= Speed;
        frameKey = L"Up";
    }
    else if (GetKeyState(VK_LEFT) & 0x8000)
    {
        Pos.x -= Speed;
        frameKey = L"Left";
    }
    else if (GetKeyState(VK_RIGHT) & 0x8000)
    {
        Pos.x += Speed;
        frameKey = L"Right";
    }

    /*if (GetKeyState(VK_SPACE) & 0x8000)
    {
        CreateBalloon();
    }*/
}
