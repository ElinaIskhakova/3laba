#include "stdio.h"
#include "conio.h"
#include <iostream>
#include <string>
using namespace std;
const int lim = 40;
void getline(char *str, int lim)
{
    int c, i;
    c = 1;
    for (i = 0; (i<lim - 1) && (c != (int)'\n'); i++)
    {
        c = getchar();
        str[i] = c;
    }
    str[i] = '\0';
}

struct book
{
    int UDKnumber;
    char autor[lim];
    char bookname[lim];
    long int year;
    int kolvo;
    book* next;
};
book* firstbook = new book;
book* lastbook = firstbook;
bool isFirst = true;


int main()
{
    setlocale(LC_ALL, "Russian");
   int n, i, c,j, k;
   int zapros;
   printf("Определите ассортимент библиотеки\n");
   cin >> n;
   for (i = 0; i <= n - 1; i++)
   {
       if (isFirst) isFirst = false;
       else
       {
           lastbook->next = new book;
           lastbook = lastbook->next;
       }
      printf("Книга №%d\n",i + 1);
      cout<<"\n"<<"UDK:";
       cin >> lastbook->UDKnumber;
       cout<<"\n"<<"Autor: ";
       cin.ignore();
    getline(&lastbook->autor[0],lim);
      cout<<"\n"<<"BookName: ";
      getline(&lastbook->bookname[0], lim);
      cout<<"\n"<<"Year: ";
       cin >> lastbook->year;
       cout<<"\n"<<"Kolvo: "<<"\n";
       cin >> lastbook->kolvo;
       lastbook->next = NULL;
   }
   for (k = 0; k >= 0; k++)
   {
      cout<<"1-Выдача книги 2-Сдача книги 3-Запрос о наличии книги 4-Выдача всех книг\n";
       cin>>c;
       switch (c)
       {
       case 1:
           cout<<"Введите УДК: ";
           cin >> zapros;
           j = 0;
           for (book* t = firstbook; t != NULL; t = t->next)
           {
               if (zapros == t->UDKnumber)
               {
                   if (t->kolvo != 0)
                   {
                       t->kolvo = t->kolvo - 1;
                       break;
                   }
                   else
                   {
                       cout<<"Книга отсутствует\n";
                       break;
                   }
               }
               if (j == n - 1)cout<<"Такой книги нет в ассортименте\n";
               j++;
           }
           break;
       case 2:
           cout<<"Введите УДК: ";
           cin >> zapros;
           j = 0;
           for (book* t = firstbook; t != NULL; t = t->next)
           {
               if (zapros == t->UDKnumber)
               {
                   t->kolvo = t->kolvo + 1;
                   break;
               }
               if (j == n - 1) cout<<"Такой книги нет в ассортименте\n";
               t = t->next;
               j++;
           }
           break;
       case 3:
           cout<<"Введите УДК: ";
           cin >> zapros;
           j = 0;
           for (book* t = firstbook; t != NULL; t = t->next)
           {

               if (zapros == t->UDKnumber)
               {
                   printf("%d      ", t->UDKnumber);
                                   for (i = 0; t->autor[i] != 10; i++)
                                       cout << t->autor[i];
                                   cout << "    ";
                                   for (i = 0; t->bookname[i] != 10; i++)
                                       cout << t->bookname[i];
                                   cout << "    ";
                                   printf("%d  ", t->year);
                                   printf("%d\n", t->kolvo);
                   break;
               }
               else
               {
                   cout<<"Такой книги нет в ассортименте\n";
               }

           }
            break;
       case 4:
            printf("UDK | AUTOR | NAMEBOOK  | YEAR | COUNT\n");
           for (book* t = firstbook; t != NULL; t = t->next)
           {
            printf("%d      ", t->UDKnumber);
            for (i = 0; t->autor[i] != 10; i++)
                cout << t->autor[i];
            cout << "    ";
            for (i = 0; t->bookname[i] != 10; i++)
                cout << t->bookname[i];
            cout << "    ";
            printf("%d  ", t->year);
            printf("%d\n", t->kolvo);
           }
           break;

       }
   }
}
