//========================================================================
//! @file       Main.cpp
//{=======================================================================
//!
//! @brief      <���������>\n
//! @brief      <������������>
//!
//! @version    [Version 0.01 alpha, build 1]
//! @author     Copyright (C) <�����>, <���> (<���> <�����>)
//! @date       <����>
//!
//! @par        ��������������
//!           - (TODO: ������ ��������)
//!
//! @todo     - (TODO: ������ ��������� ������ �� ����� �����)
//!
//! @bug      - (TODO: ������ ��������� ������ � ���� �����)
//!
//! @par        ������� ��������� �����
//!           - ������ 0.01 Alpha
//!             - ������ ��� ��������� ����
//!
//}=======================================================================

#include "TXLib.h"

int main()
    {
    txCreateWindow (800, 600);

    int x=10;
    int y=400;
    int v=-100;
    int r=-100;
    HDC  carright = txLoadImage ("��������/������/carright.bmp");
    HDC  carleft = txLoadImage  ("��������/������/carleft.bmp");
    HDC  money = txLoadImage ("�������/��
    HDC  car=carright;
   // char str=[100]
    txSetColor(TX_WHITE);
    txSetFillColor (TX_BLACK);


    while (true)
    {
          txClear();

         // txBitBlt (txDC(), 0, 0, 300, 93, car);
          /*
          sprintf(str, "���� = %d", car);
          txTextOut(100,100,str)
          txSetColor(TX_BLUE);
          txSetFillColor (TX_BLUE);
          txRectangle(0,0,800,600);
          txSetColor(TX_BLACK);
          txSetFillColor (TX_BLACK);
          txRectangle(0,400,800,600);
          txSetColor(TX_WHITE);
          txSetFillColor (TX_WHITE);
          txLine(0,470,800,470);
          txLine(0,540,800,540);

          */
          txTransparentBlt (txDC(), x, y, 300, 93, car,0,0, TX_WHITE);



      if(GetAsyncKeyState(VK_DOWN))
      {
      y=y+10;
      }

      if(GetAsyncKeyState(VK_UP))
      {
      y=y-10;
      }

      if(GetAsyncKeyState(VK_RIGHT))
      {
      car=carright;
      x=x+10;
      }

      if(GetAsyncKeyState(VK_LEFT))
      {
      car=carleft;
      x=x-10;
      }


      txSleep(10);
     }
    txDeleteDC(carright);
    txDeleteDC(carleft);
     return 0;
  }





