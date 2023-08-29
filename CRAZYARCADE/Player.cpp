#include "Player.h"
#include "BmpManager.h"
#include "WaterBalloon.h"
#include "ObjectManager.h"
#include "KeyManager.h"

Player::Player()
    :Speed(5.0f) 
{
}

Player::~Player()
{
}

void Player::Init()
{
    // 65 X 76
    BmpManager::GetInstance()->InsertBmp(L"Idle", L"Image/player/Bazzi/jump.bmp");
    BmpManager::GetInstance()->InsertBmp(L"Down", L"Image/player/Bazzi/down.bmp");
    BmpManager::GetInstance()->InsertBmp(L"Left", L"Image/player/Bazzi/left.bmp");
    BmpManager::GetInstance()->InsertBmp(L"Right", L"Image/player/Bazzi/right.bmp");
    BmpManager::GetInstance()->InsertBmp(L"Up", L"Image/player/Bazzi/up.bmp");

    BmpManager::GetInstance()->InsertBmp(L"Trap", L"Image/player/Bazzi/trap.bmp");
    BmpManager::GetInstance()->InsertBmp(L"Die", L"Image/player/Bazzi/die.bmp");
    BmpManager::GetInstance()->InsertBmp(L"Live", L"Image/player/Bazzi/live.bmp");
    
    BmpManager::GetInstance()->InsertBmp(L"Arrow", L"Image/player/solo_player.bmp");

    curState = L"Idle";

    //Pos = { 15, 20 };
    info.sizeX = 50;
    info.sizeY = 60;

    frame.Cur = frame.Start;
    frame.Timer = GetTickCount();
}


void Player::Update()
{
    KeyUpdate();
    UpdateFrame(g_hWnd);
    
    if (curState == L"Bubble")
    {
        if (dwTime + 6000 < GetTickCount())
        {
            curState = L"Dead";
            dwTime = GetTickCount();
        }
    }

    if (curState == L"Dead")
    {
        if (dwTime + 2000 < GetTickCount())
        {
            dwTime = GetTickCount();
            //CSceneManager::Get_Instance()->Scene_Change(CSceneManager::SCENE_MENU);
        }
    }

    if (info.posX < 15)
    {
        info.posX += Speed;
    }
    if (info.posX > 580)
    {
        info.posX -= Speed;
    }
    if (info.posY < 19)
    {
        info.posY += Speed;
    }
    if (info.posY > 500)
    {
        info.posY -= Speed;
    }
}

void Player::Render(HDC hdc)
{
    HDC memDC;

    //HDC memDC3 = BmpManager::GetInstance()->FindImage(L"Shadow");
    //GdiTransparentBlt(hdc, Info.Pos.x + 5, Info.Pos.y + 48, 40, 19, memDC3, 0, 0, 42, 19, RGB(255, 0, 255));

    if (curState == L"Idle")
    {
        frame.Start = 0;
        frame.End = 2;
        frame.Speed = 3.f;
        memDC = BmpManager::GetInstance()->FindImage(L"Idle");
        GdiTransparentBlt(hdc, info.posX, info.posY, info.sizeX, info.sizeY, memDC, frame.Start * 64, 0, 64, 76, RGB(255, 0, 255));
        //Rectangle(hdc, Info.Pos.x + 5, Info.Pos.y + 20, Info.Pos.x + 45, Info.Pos.y + 60);
    }
    if (curState == L"Up")
    {
        frame.Start = 0;
        frame.End = 7;
        frame.Speed = 8.f;
        memDC = BmpManager::GetInstance()->FindImage(L"Up");
        GdiTransparentBlt(hdc, info.posX, info.posY, info.sizeX, info.sizeY, memDC, frame.Cur * 64, 0, 64, 76, RGB(255, 0, 255));
    }
    if (curState == L"Right")
    {
        frame.Start = 0;
        frame.End = 5;
        frame.Speed = 6.f;
        memDC = BmpManager::GetInstance()->FindImage(L"Right");
        GdiTransparentBlt(hdc, info.posX, info.posY, info.sizeX, info.sizeY, memDC, frame.Cur * 64, 0, 64, 76, RGB(255, 0, 255));

    }
    if (curState == L"Left")
    {
        frame.Start = 0;
        frame.End = 5;
        frame.Speed = 6.f;
        memDC = BmpManager::GetInstance()->FindImage(L"Left");
        GdiTransparentBlt(hdc, info.posX, info.posY, info.sizeX, info.sizeY, memDC, frame.Cur * 64, 0, 64, 76, RGB(255, 0, 255));
    }
    if (curState == L"Down")
    {
        frame.Start = 0;
        frame.End = 7;
        frame.Speed = 8.f;
        memDC = BmpManager::GetInstance()->FindImage(L"Down");
        GdiTransparentBlt(hdc, info.posX, info.posY, info.sizeX, info.sizeY, memDC, frame.Cur * 64, 0, 64, 76, RGB(255, 0, 255));
    }

    HDC memDC2 = BmpManager::GetInstance()->FindImage(L"Arrow");
    GdiTransparentBlt(hdc, info.posX + 14, info.posY - 24, 20, 24, memDC2, 0, 0, 24, 28, RGB(255, 0, 255));


}

void Player::Release()
{
}

void Player::CreateBalloon()
{
    if (curState != L"Bubble" && curState != L"Dead")
    {
        Object* balloon = new WaterBalloon();
        balloon->SetPos((int)((info.posX + 5) / 40) * 40 + 20, (int)((info.posY + 19) / 40) * 40 + 40);
        balloon->Init();
        ObjectManager::GetInstance()->AddObject(balloon, OBJTYPE::BALLOON);
    }
}



void Player::KeyUpdate()
{
    curState = L"Idle";

    if (KeyManager::GetInstance()->GetKeyState(KEY::DOWN) == KEYSTATE::HOLD)
    {
        info.posY += Speed;
        curState = L"Down";
    }
    else if (KeyManager::GetInstance()->GetKeyState(KEY::UP) == KEYSTATE::HOLD)
    {
        info.posY -= Speed;
        curState = L"Up";
    }
    else if (KeyManager::GetInstance()->GetKeyState(KEY::LEFT) == KEYSTATE::HOLD)
    {
        info.posX -= Speed;
        curState = L"Left";
    }
    else if (KeyManager::GetInstance()->GetKeyState(KEY::RIGHT) == KEYSTATE::HOLD)
    {
        info.posX += Speed;
        curState = L"Right";
    }

    if (KeyManager::GetInstance()->GetKeyState(KEY::SPACE) == KEYSTATE::TAP)
    {
        CreateBalloon();
    }
}
