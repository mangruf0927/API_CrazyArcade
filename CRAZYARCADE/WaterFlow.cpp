#include "WaterFlow.h"
#include "BmpManager.h"

WaterFlow::WaterFlow()
{
}

WaterFlow::~WaterFlow()
{
}

void WaterFlow::Init()
{
    BmpManager::GetInstance()->InsertBmp(L"Center", L"Image/balloons/center.bmp"); // 스프라이트 6개

    BmpManager::GetInstance()->InsertBmp(L"Down1", L"Image/balloons/down1.bmp"); // 스프라이트 11개
    BmpManager::GetInstance()->InsertBmp(L"Down2", L"Image/balloons/down2.bmp");

    BmpManager::GetInstance()->InsertBmp(L"Right1", L"Image/balloons/right1.bmp");
    BmpManager::GetInstance()->InsertBmp(L"Right2", L"Image/balloons/right2.bmp");

    BmpManager::GetInstance()->InsertBmp(L"Left1", L"Image/balloons/left1.bmp");
    BmpManager::GetInstance()->InsertBmp(L"Left2", L"Image/balloons/left2.bmp");

    BmpManager::GetInstance()->InsertBmp(L"Up1", L"Image/balloons/up1.bmp");
    BmpManager::GetInstance()->InsertBmp(L"Up2", L"Image/balloons/up2.bmp");

    info.sizeX = 40;
    info.sizeY = 40;

    frame.Cur = frame.Start;
    frame.Timer = GetTickCount();
    waveTime = GetTickCount();

    isDead = false;
}

int WaterFlow::Update()
{
    if (isDead) return DEAD;

    UpdateFrame(g_hWnd);
    SetCenter();
    SetRect();
    return LIVE;
}

void WaterFlow::LateUpdate()
{
    if (GetTickCount() >= waveTime + 1000)
    {
        isDead = true;
        waveTime = GetTickCount();
    }
}

void WaterFlow::Render(HDC hdc)
{
    //DIR dir;
    HDC memDC;
    if (objName == L"Center")
    {
        frame.Start = 0;
        frame.End = 5;
        frame.Speed = 50.f;
        memDC = BmpManager::GetInstance()->FindImage(L"Center");
        GdiTransparentBlt(hdc, info.posX, info.posY, 40, 40, memDC, frame.Cur * 52, 0, 52, 52, RGB(255, 0, 255));
        Rectangle(hdc, centerPos.x - 20, centerPos.y - 20, centerPos.x + 20, centerPos.y + 20);
    }
    if (objName == L"UpEdge")
    {
        frame.Start = 0;
        frame.End = 10;
        frame.Speed = 100.f;
        memDC = BmpManager::GetInstance()->FindImage(L"Up1");
        GdiTransparentBlt(hdc, info.posX, info.posY, 40, 40, memDC, frame.Cur * 52, 0, 52, 52, RGB(255, 0, 255));
    }
    if (objName == L"DownEdge")
    {
        frame.Start = 0;
        frame.End = 10;
        frame.Speed = 100.f;
        memDC = BmpManager::GetInstance()->FindImage(L"Down1");
        GdiTransparentBlt(hdc, info.posX, info.posY, 40, 40, memDC, frame.Cur * 52, 0, 52, 52, RGB(255, 0, 255));
    }
    if (objName == L"RightEdge")
    {
        frame.Start = 0;
        frame.End = 10;
        frame.Speed = 100.f;
        memDC = BmpManager::GetInstance()->FindImage(L"Right1");
        GdiTransparentBlt(hdc, info.posX, info.posY, 40, 40, memDC, frame.Cur * 52, 0, 52, 52, RGB(255, 0, 255));
    }
    if (objName == L"LeftEdge")
    {
        frame.Start = 0;
        frame.End = 10;
        frame.Speed = 100.f;
        memDC = BmpManager::GetInstance()->FindImage(L"Left1");
        GdiTransparentBlt(hdc, info.posX, info.posY, 40, 40, memDC, frame.Cur * 52, 0, 52, 52, RGB(255, 0, 255));
    }
    if (objName == L"Up")
    {
        frame.Start = 0;
        frame.End = 10;
        frame.Speed = 100.f;
        memDC = BmpManager::GetInstance()->FindImage(L"Up2");
        GdiTransparentBlt(hdc, info.posX, info.posY, 40, 40, memDC, frame.Cur * 52, 0, 52, 52, RGB(255, 0, 255));
    }
    if (objName == L"Down")
    {
        frame.Start = 0;
        frame.End = 10;
        frame.Speed = 100.f;
        memDC = BmpManager::GetInstance()->FindImage(L"Down2");
        GdiTransparentBlt(hdc, info.posX, info.posY, 40, 40, memDC, frame.Cur * 52, 0, 52, 52, RGB(255, 0, 255));
    }
    if (objName == L"Right")
    {
        frame.Start = 0;
        frame.End = 10;
        frame.Speed = 100.f;
        memDC = BmpManager::GetInstance()->FindImage(L"Right2");
        GdiTransparentBlt(hdc, info.posX, info.posY, 40, 40, memDC, frame.Cur * 52, 0, 52, 52, RGB(255, 0, 255));
    }
    if (objName == L"Left")
    {
        frame.Start = 0;
        frame.End = 10;
        frame.Speed = 100.f;
        memDC = BmpManager::GetInstance()->FindImage(L"Left2");
        GdiTransparentBlt(hdc, info.posX, info.posY, 40, 40, memDC, frame.Cur * 52, 0, 52, 52, RGB(255, 0, 255));
    }
}

void WaterFlow::Release()
{
}
