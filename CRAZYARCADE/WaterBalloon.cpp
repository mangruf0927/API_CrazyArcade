#include "WaterBalloon.h"
#include "BmpManager.h"

WaterBalloon::WaterBalloon()
{
}

WaterBalloon::~WaterBalloon()
{
}

void WaterBalloon::Init()
{
    BmpManager::getInstance()->InsertBmp(L"Balloon", L"Image/balloons/Bubble.bmp"); // 스프라이트 4개

    BmpManager::getInstance()->InsertBmp(L"Center", L"Image/balloons/center.bmp"); // 스프라이트 6개
    BmpManager::getInstance()->InsertBmp(L"Down1", L"Image/balloons/down1.bmp"); // 스프라이트 11개
    BmpManager::getInstance()->InsertBmp(L"Down2", L"Image/balloons/down2.bmp");
    BmpManager::getInstance()->InsertBmp(L"Right1", L"Image/balloons/right1.bmp");
    BmpManager::getInstance()->InsertBmp(L"Right2", L"Image/balloons/right2.bmp");
    BmpManager::getInstance()->InsertBmp(L"Left1", L"Image/balloons/left2.bmp");
    BmpManager::getInstance()->InsertBmp(L"Left2", L"Image/balloons/left2.bmp");
    BmpManager::getInstance()->InsertBmp(L"Up1", L"Image/balloons/up1.bmp");
    BmpManager::getInstance()->InsertBmp(L"Up2", L"Image/balloons/up2.bmp");

    frameKey = L"Balloon";

    frame.Cur = frame.Start;
    frame.Timer = GetTickCount();
    BoomTime = GetTickCount();
}

void WaterBalloon::Update()
{
    if (GetTickCount() >= frame.Timer + 3000) // 1000 = 1초
    {
        frameKey = L"PopBalloon";
    }
    UpdateFrame(g_hWnd);
}

void WaterBalloon::LateUpdate()
{

}


void WaterBalloon::Render(HDC hdc)
{
    HDC memDC1;

    if (frameKey == L"Balloon") // 56 X 54
    {
        frame.Start = 0;
        frame.End = 3;

        HDC memDC = BmpManager::getInstance()->FindImage(L"Balloon");
        GdiTransparentBlt(hdc, Pos.x, Pos.y, 40, 40, memDC, frame.Cur * 56, 0, 56, 54, RGB(255, 0, 255));
    }
    if (frameKey == L"PopBalloon")
    {
        {
            frame.Start = 0;
            frame.End = 5;

            memDC1 = BmpManager::getInstance()->FindImage(L"Center"); // 52 X 52
            GdiTransparentBlt(hdc, Pos.x, Pos.y, 40, 40, memDC1, frame.Cur * 52, 0, 52, 52, RGB(255, 0, 255));
        }

        {
            frame.Start = 0;
            frame.End = 10;

            memDC1 = BmpManager::getInstance()->FindImage(L"Down1");
            GdiTransparentBlt(hdc, Pos.x, Pos.y + 40, 40, 40, memDC1, frame.Cur * 52, 0, 52, 52, RGB(255, 0, 255));

            memDC1 = BmpManager::getInstance()->FindImage(L"Left1");
            GdiTransparentBlt(hdc, Pos.x - 40, Pos.y, 40, 40, memDC1, frame.Cur * 52, 0, 52, 52, RGB(255, 0, 255));

            memDC1 = BmpManager::getInstance()->FindImage(L"Right1");
            GdiTransparentBlt(hdc, Pos.x + 40, Pos.y, 40, 40, memDC1, frame.Cur * 52, 0, 52, 52, RGB(255, 0, 255));

            memDC1 = BmpManager::getInstance()->FindImage(L"Up1");
            GdiTransparentBlt(hdc, Pos.x, Pos.y - 40, 40, 40, memDC1, frame.Cur * 52, 0, 52, 52, RGB(255, 0, 255));
        }
    }

}

void WaterBalloon::Release()
{

}

