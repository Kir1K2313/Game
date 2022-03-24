
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

    HDC fon = txLoadImage("Картинки/фон/фон.bmp");

    HDC right = txLoadImage("Картинки/машина/right.bmp");

    HDC mon = txLoadImage("Картинки/монета/money1.bmp");

    HDC Ship = txLoadImage("Картинки/препятствие/Шипы.bmp");


   char score_list[100];
   int score = 0;
   int level = 1;
    txSetColor(TX_WHITE);
    txSetFillColor (TX_BLACK);

    Personage car = {50, 750, right, true};

    int kolmoney = 20;
    Personage money[kolmoney];
    for(int i=0; i<kolmoney; i++)
    {
        money[i]= {random(800,6000), random(500,900), mon, true};
    }

    int kolship = 20;
    Personage ship[kolship];
    for(int i=0; i<kolship; i++)
    {
        ship[i] = {random(1000,6000), random(500,900), Ship, true};
    }

   string PAGE = "Меню";

    int nc=0;

    int kolroad = 500;
    Object road1[1000];
    road1[0] = {50, 820, 100, 10};

    Object road2[1000];
    road2[0] = {50, 670, 100, 10};


    Object road3[1000];
    road3[0] = {50, 520, 100, 10};


    while (true)
    {
        txClear();


        if(PAGE=="Меню")
        {
            txSetFillColor (TX_BLACK);
            txRectangle(500,100,700,150);
            txDrawText(500,100,700,150,"START");

            if(txMouseX() >= 500 && txMouseY()>= 100 &&
               txMouseX() <= 700 && txMouseY()<= 150 &&
               txMouseButtons() == 1)
            {
               PAGE="Игра";
            }

               txRectangle(500,200,700,250);
               txDrawText(500,200,700,250,"EXIT");

            if(txMouseX() >= 500 && txMouseY()>= 200 &&
               txMouseX() <= 700 && txMouseY()<= 250 &&
               txMouseButtons() == 1)
            {
               return 0;
            }
        }

        if(PAGE =="Игра")
        {

            txBegin();

             if(GetAsyncKeyState(VK_ESCAPE))
             {
                PAGE= "Меню";
             }

            txTransparentBlt (txDC(), 0, 0, 1200,900, fon, 0, 0,TX_GREEN);


            txSetFillColor(TX_GRAY);
            txRectangle(0, 750, 1200, 900);
            txRectangle(0, 600, 1200, 750);
            txRectangle(0, 450, 1200, 600);


            sprintf(score_list, "Очки = %d", score);
            txTextOut(50, 100, score_list);


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


            for(int i=0; i<kolship; i++)
            {
                if(ship[i].visible)
                {
                    txTransparentBlt (txDC(), ship[i].x, ship[i].y, 49, 51 , ship[i].pic, 0, 0, TX_WHITE);
                    ship[i].x= ship[i].x - 10;
                }
            }

            if(car.visible)
            txTransparentBlt (txDC(), car.x, car.y, 300, 93, car.pic, 0, 0, TX_WHITE);

            for(int i=0; i<kolmoney; i++)
            {
                if(money[i].visible)
                {
                    txTransparentBlt (txDC(), money[i].x, money[i].y, 80, 79, money[i].pic, nc*80, 0, TX_WHITE);
                    money[i].x= money[i].x - 10;
                }
            }

            nc++;
            if(nc>=7) nc=0;


            for(int i=0; i<kolmoney; i++)
            {
                if(car.x<=money[i].x && car.x+300>=money[i].x+80 &&
                   car.y<=money[i].y && car.y+93 >=money[i].y+80)
                {
                  txTextOut(100, 300, "УДАР");
                  money[i].visible = false;
                  score++;
                }
            }

            for(int i=0; i<kolship; i++)
            {
               if(car.x+330>=ship[i].x && car.x+330<=ship[i].x+5 && car.y+90>=ship[i].y+40 && car.y<=ship[i].y+40)
              {
                ship[i].visible = false;
                car.visible = false;
              }
            }

            if(car.visible == false)
            {
                txSetFillColor(TX_RED);
                txRectangle(500,100,1000,400);
                txDrawText(500,100,1000,150,"Game over");
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
        }

      txSleep(10);
    }
    txDeleteDC(right);
    txDeleteDC(mon);
    txDeleteDC(fon);
    txDeleteDC(Ship);

return 0;

}





