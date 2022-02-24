
#include "TXLib.h"


struct Personage
{
  int x;
  int y;
  HDC pic;
  bool visible;
};


struct Object
{
    int x;
    int y;
    int w;
    int v;
};

void drawRoad(Object road)
{
    txSetColor(TX_WHITE);
    txSetFillColor(TX_WHITE);
    txRectangle(road.x, road.y, road.x+road.w, road.y+10);
}



int main()
    {
    txCreateWindow (1200, 900);

    HDC fon = txLoadImage("��������/���/���.bmp");

    HDC right = txLoadImage("��������/������/right.bmp");

    HDC mon = txLoadImage("��������/������/money.bmp");


   //char str=[100]
    txSetColor(TX_WHITE);
    txSetFillColor (TX_BLACK);

    Personage car = {50, 750, right};
    Personage money = {1500, 700, mon, true};


    int kolroad = 500;
    Object road1[1000];
    road1[0] = {50, 820, 100, 10};

    Object road2[1000];
    road2[0] = {50, 670, 100, 10};


    Object road3[1000];
    road3[0] = {50, 520, 100, 10};

    while (!GetAsyncKeyState(VK_ESCAPE))
    {
        txClear();
        txBegin();

    //  sprintf(str, "���� = %d", car);
     // txTextOut(100,100,str);

        txTransparentBlt (txDC(), 0, 0, 1200,900, fon, 0, 0,TX_GREEN);


        txSetFillColor(TX_GRAY);
        txRectangle(0, 750, 1200, 900);
        txRectangle(0, 600, 1200, 750);
        txRectangle(0, 450, 1200, 600);

        if(money.visible)
        txTransparentBlt (txDC(), money.x, money.y, 81, 79, money.pic, 0, 0, RGB(247, 247, 247));

        for(int i=0; i<kolroad; i++)
        {
            road1[i] = {road1[0].x+(150*i), road1[0].y, road1[0].w};
            drawRoad(road1[i]);
            road2[i] = {road2[0].x+(150*i), road2[0].y, road2[0].w};
            drawRoad(road2[i]);
            road3[i] = {road3[0].x+(150*i), road3[0].y, road3[0].w};
            drawRoad(road3[i]);
        }



        road1[0].x = road1[0].x - 10;
        road2[0].x = road2[0].x - 10;
        road3[0].x = road3[0].x - 10;

        money.x= money.x - 10;



        txTransparentBlt (txDC(), car.x, car.y, 300, 93, car.pic, 0, 0, TX_WHITE);

        if(car.x+310>=money.x && car.y+90>=money.y+40 && car.y<=money.y+40)
        {
          money.visible = false;
        }

      if(GetAsyncKeyState(VK_DOWN))
      {
      car.y=car.y+20;
      }

      if(GetAsyncKeyState(VK_UP))
      {
      car.y=car.y-20;
      }

      if(GetAsyncKeyState(VK_RIGHT))
      {
      car.x=car.x+20;
      }

      if(GetAsyncKeyState(VK_LEFT))
      {
      car.x=car.x-10;
      }

      txEnd();
      txSleep(10);
     }
    txDeleteDC(right);
    txDeleteDC(mon);
    txDeleteDC(fon);
     return 0;
  }




