#include "WaterBalloon.h"
#include "BmpManager.h"

WaterBalloon::WaterBalloon()
{
    //CreateCollider();
}

WaterBalloon::~WaterBalloon()
{
}

void WaterBalloon::Init()
{
    BmpManager::GetInstance()->InsertBmp(L"Bomb", L"Image/balloons/Bubble.bmp"); // 스프라이트 4개

    BmpManager::GetInstance()->InsertBmp(L"Center", L"Image/balloons/center.bmp"); // 스프라이트 6개
    BmpManager::GetInstance()->InsertBmp(L"Down1", L"Image/balloons/down1.bmp"); // 스프라이트 11개
    BmpManager::GetInstance()->InsertBmp(L"Down2", L"Image/balloons/down2.bmp");
    BmpManager::GetInstance()->InsertBmp(L"Right1", L"Image/balloons/right1.bmp");
    BmpManager::GetInstance()->InsertBmp(L"Right2", L"Image/balloons/right2.bmp");
    BmpManager::GetInstance()->InsertBmp(L"Left1", L"Image/balloons/left2.bmp");
    BmpManager::GetInstance()->InsertBmp(L"Left2", L"Image/balloons/left2.bmp");
    BmpManager::GetInstance()->InsertBmp(L"Up1", L"Image/balloons/up1.bmp");
    BmpManager::GetInstance()->InsertBmp(L"Up2", L"Image/balloons/up2.bmp");

    curState = L"Bomb";

    frame.Cur = frame.Start;
    frame.Timer = GetTickCount();
    BoomTime = GetTickCount();
}

void WaterBalloon::Update()
{
    if (GetTickCount() >= BoomTime + 3000) // 1000 = 1초
    {
        curState = L"Pop";
    }
    UpdateFrame(g_hWnd);
}


void WaterBalloon::Render(HDC hdc)
{
    HDC memDC1;

    if (curState == L"Bomb") // 56 X 54
    {
        frame.Start = 0;
        frame.End = 3;
        frame.Speed = 100.f;
        HDC memDC = BmpManager::GetInstance()->FindImage(L"Bomb");
        GdiTransparentBlt(hdc, info.posX, info.posY, 40, 40, memDC, frame.Cur * 56, 0, 56, 54, RGB(255, 0, 255));
    }
    if (curState == L"Pop")
    {
        {
            frame.Start = 0;
            frame.End = 5;
            frame.Speed = 50.f;
            memDC1 = BmpManager::GetInstance()->FindImage(L"Center"); // 52 X 52
            GdiTransparentBlt(hdc, info.posX, info.posY, 40, 40, memDC1, frame.Cur * 52, 0, 52, 52, RGB(255, 0, 255));
        }

        {
            frame.Start = 0;
            frame.End = 10;
            frame.Speed = 100.f;

            memDC1 = BmpManager::GetInstance()->FindImage(L"Down1");
            GdiTransparentBlt(hdc, info.posX, info.posY + 40, 40, 40, memDC1, frame.Cur * 52, 0, 52, 52, RGB(255, 0, 255));

            memDC1 = BmpManager::GetInstance()->FindImage(L"Left1");
            GdiTransparentBlt(hdc, info.posX - 40, info.posY, 40, 40, memDC1, frame.Cur * 52, 0, 52, 52, RGB(255, 0, 255));

            memDC1 = BmpManager::GetInstance()->FindImage(L"Right1");
            GdiTransparentBlt(hdc, info.posX + 40, info.posY, 40, 40, memDC1, frame.Cur * 52, 0, 52, 52, RGB(255, 0, 255));

            memDC1 = BmpManager::GetInstance()->FindImage(L"Up1");
            GdiTransparentBlt(hdc, info.posX, info.posY - 40, 40, 40, memDC1, frame.Cur * 52, 0, 52, 52, RGB(255, 0, 255));
        }
    }

}

void WaterBalloon::Release()
{

}

