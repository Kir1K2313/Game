
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

    txDisableAutoPause();

    //Загрузка картинок
    HDC fon = txLoadImage("Картинки/фон/фон.bmp");

    HDC right = txLoadImage("Картинки/машина/right.bmp");

    HDC mon = txLoadImage("Картинки/монета/money1.bmp");

    HDC Ship = txLoadImage("Картинки/препятствие/Шипы.bmp");

    HDC FON = txLoadImage("Картинки/главное меню/фон.bmp");

   char score_list[100];
   int score = 0;
   int level = 1;

    //машина
    Personage car = {50, 750, right, true};
    //Монета
    int kolmoney = 50;
    Personage money[kolmoney];
    for(int i=0; i<kolmoney; i++)
    {
        money[i]= {random(1200,16000), random(500,900), mon, true};
    }

    int kolship = 30;
    Personage ship[kolship];
    for(int i=0; i<kolship; i++)
    {
        ship[i] = {random(2000,20000), random(500,900), Ship, true};
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

        //Главное меню

        if(PAGE=="Меню")
        {

            txSetColor(TX_WHITE,5);
            txSetFillColor (TX_RED);

            txTransparentBlt (txDC(), 0, 0, 1200,900, FON, 0, 0,TX_GREEN);

            txRectangle(500,100,700,150);
            txDrawText(500,100,700,150,"START");

            if(txMouseX() >= 500 && txMouseY()>= 100 &&
               txMouseX() <= 700 && txMouseY()<= 150 &&
               txMouseButtons() == 1)
            {
               PAGE="Игра";
            }

               txRectangle(500,200,700,250);
               txDrawText(500,200,700,250,"HELP");

           if(txMouseX() >= 500 && txMouseY()>= 200 &&
           txMouseX() <= 700 && txMouseY()<= 250 &&
           txMouseButtons() == 1)
           {
                PAGE="Справка";
           }

                txRectangle(500,300,700,350);
                txDrawText(500,300,700,350,"EXIT");

            if(txMouseX() >= 500 && txMouseY()>= 300 &&
               txMouseX() <= 700 && txMouseY()<= 350 &&
               txMouseButtons() == 1)
            {
                return 0;
            }


        }

       if(PAGE=="Справка")
       {
         txRectangle(100,100,300,150);
         txDrawText(100,100,300,150, "Назад");
            if(txMouseX() >= 100 && txMouseY()>= 100 &&
            txMouseX() <= 300 && txMouseY()<= 150 &&
            txMouseButtons() == 1)
            {
                 PAGE= "Меню";
            }

         txDrawText(400,100,800,600,"Управление - стрелками\n"
                                     "\n"
                                     "монеты - прибавляют очки\n"
                                     "\n"
                                     "шипы - убивают тебя\n"
                                     "\n"
                                     "Цель игры - собрать 30 монет\n"
                                     "\n"
                                     "Удачной игры =)");

       }



        //ИГРА
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
                   car.y-10<=money[i].y && car.y+110 >=money[i].y+80)
                {
                  money[i].visible = false;
                  money[i].x = 0;
                  money[i].y = 0;
                  score++;
                }
            }

            for(int i=0; i<kolship; i++)
            {
               if(car.x<=ship[i].x && car.x+330>=ship[i].x+5 &&
                  car.y-10<=ship[i].y && car.y+110>=ship[i].y+40)
              {
                ship[i].visible = false;
                car.visible = false;
              }
            }

            if(car.visible == false)
            {
                txSetFillColor(TX_RED);
                txRectangle(500,100,700,200);
                txDrawText(500,100,700,200,"Game over");

            }

         for(int i=0; i<kolship; i++)
            if(score >= 10)
            {
              road1[0].x = road1[0].x - 15;
              road2[0].x = road2[0].x - 15;
              road3[0].x = road3[0].x - 15;
              ship[i].x = ship[i].x - 15;
              money[i].x = money[i].x - 15;

            }

              for(int i=0; i<kolship; i++)
             if(score >= 20)
            {
              road1[0].x = road1[0].x - 20;
              road2[0].x = road2[0].x - 20;
              road3[0].x = road3[0].x - 20;
              ship[i].x = ship[i].x - 20;
              money[i].x = ship[i].x - 20;

            }

        for(int i=0; i<kolship; i++)
            if(score == 30)
            {
             txSetFillColor(TX_WHITE);
             txRectangle(400,200,800,500);
             txSetFillColor(TX_BLACK);
             txDrawText(600,300,700,400,"YOU WIN!");
            }

            if(GetAsyncKeyState(VK_DOWN))
            {
                car.y=car.y+20;
            }

            if(GetAsyncKeyState(VK_UP))
            {
                car.y=car.y-20;
            }

            txEnd();
        }

      txSleep(10);
    }
        txDeleteDC(right);
        txDeleteDC(mon);
        txDeleteDC(fon);
        txDeleteDC(Ship);
        txDeleteDC(FON);

return 0;

}





