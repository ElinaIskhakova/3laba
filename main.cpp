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
   int n, i, c, k;
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
}
