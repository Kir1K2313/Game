

#include "TXLib.h"

struct Form
{
  string text_question;
  string text_answer1;
  string text_answer2;
  string text_answer3;
}
int main()
    {
    txCreateWindow (800, 600);

 Form form1={"вопрос","1","2","3"};
 Form form2={"2вопрос","1","2","3"};
 Form form3{"3)Как зовут нашего помощника?","1)Итер","2) Паймон","3)Люмин"};
 Form form4{"4)Как называют защитника региона?","1)Боги истоков","2)Фатуи","3)Архонт"};
 Form form5{"5)Как предмет помогает овладеть элементом?","1)Глаз бога","2)","3)Архонт"};

 if(n_question == 1) form = form1;
 if(n_question == 2) form = form2;
 if(n_question == 3) form = form3;
 if(n_question == 4) form = form4;
 if(n_question == 5) form = form5;

    return 0;
    }

