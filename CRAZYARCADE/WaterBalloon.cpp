#include "WaterBalloon.h"
#include "WaterFlow.h"
#include "BmpManager.h"

WaterBalloon::WaterBalloon()
    :rightPower(1)
    ,leftPower(1)
    ,upPower(1)
    ,downPower(1)
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
    boomTime = GetTickCount();
    
    isDead = false;
}

int WaterBalloon::Update()
{
    if (isDead) 
    {
        /*curState = L"Pop";*/
        CreateWave();

        return DEAD;
    }

    UpdateFrame(g_hWnd);

    //if (GetTickCount() >= boomTime + 4000)
    //{
    //    return DEAD;
    //}

    return LIVE;
}

void WaterBalloon::LateUpdate()
{
    if (GetTickCount() >= boomTime + 3000) // 1000 = 1초
    {
        isDead = true;
        //boomTime = GetTickCount();
    }
    
}


void WaterBalloon::Render(HDC hdc)
{   
    // 56 X 54
    frame.Start = 0; 
    frame.End = 3;
    frame.Speed = 100.f;
    HDC memDC = BmpManager::GetInstance()->FindImage(L"Bomb");
    GdiTransparentBlt(hdc, info.posX, info.posY, 40, 40, memDC, frame.Cur * 56, 0, 56, 54, RGB(255, 0, 255));
    Rectangle(hdc, centerPos.x - 20, centerPos.y - 20, centerPos.x + 20, centerPos.y + 20);

}

void WaterBalloon::Release()
{

}

void WaterBalloon::CreateWave()
{
    // 중간
    {
        Object* obj = new WaterFlow;
        obj->SetPos(info.posX, info.posY);
        obj->SetObjName(L"Center");
        obj->Init();
        ObjectManager::GetInstance()->AddObject(obj, OBJTYPE::FLOW);
    }

    //왼
    for (int i = 1; i <= leftPower; ++i)
    {
        if (i == leftPower)
        {
            Object* left = new WaterFlow;
            left->SetPos(info.posX - 40 * i, info.posY);
            left->SetObjName(L"LeftEdge");
            left->Init();
            ObjectManager::GetInstance()->AddObject(left, OBJTYPE::FLOW);
        }
        else
        {
            Object* leftE = new WaterFlow;
            leftE->SetPos(info.posX - 40 * (i - 1), info.posY);
            leftE->SetObjName(L"Left");
            leftE->Init();
            ObjectManager::GetInstance()->AddObject(leftE, OBJTYPE::FLOW);
        }
    }

    //오
    for (int i = 1; i <= rightPower; ++i)
    {
        if (i == rightPower)
        {
            Object* right = new WaterFlow;
            right->SetPos(info.posX + 40 * i, info.posY);
            right->SetObjName(L"RightEdge");
            right->Init();
            ObjectManager::GetInstance()->AddObject(right, OBJTYPE::FLOW);
        }
        else
        {
            Object* rightE = new WaterFlow;
            rightE->SetPos(info.posX + 40 * (i - 1), info.posY);
            rightE->SetObjName(L"Right");
            rightE->Init();
            ObjectManager::GetInstance()->AddObject(rightE, OBJTYPE::FLOW);
        }
    }

    //위
    for (int i = 1; i <= upPower; ++i)
    {
        if (i == upPower)
        {
            Object* up = new WaterFlow;
            up->SetPos(info.posX, info.posY - 40 * i);
            up->SetObjName(L"UpEdge");
            up->Init();
            ObjectManager::GetInstance()->AddObject(up, OBJTYPE::FLOW);
        }
        else
        {
            Object* upE = new WaterFlow;
            upE->SetPos(info.posX, info.posY - 40 * (i - 1));
            upE->SetObjName(L"Up");
            upE->Init();
            ObjectManager::GetInstance()->AddObject(upE, OBJTYPE::FLOW);
        }
    }

    //아래
    for (int i = 1; i <= downPower; ++i)
    {
        if (i == downPower)
        {
            Object* down = new WaterFlow;
            down->Init();
            down->SetPos(info.posX, info.posY + 40 * i);
            down->SetObjName(L"DownEdge");
            ObjectManager::GetInstance()->AddObject(down, OBJTYPE::FLOW);
        }
        else
        {
            Object* downE = new WaterFlow;
            downE->Init();
            downE->SetPos(info.posX, info.posY + 40 * (i - 1));
            downE->SetObjName(L"Down");
            ObjectManager::GetInstance()->AddObject(downE, OBJTYPE::FLOW);
        }
    }
}

