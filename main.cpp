#include<iostream>
#include<fstream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctime>
#include <windows.h>
using namespace std;
int score = 0;
int a;
int totaltime;
int totaltime2;
char duvar;
int koordx;
int koordy;
char car1;
char *pointercar1;
char car2;
char *pointercar2;
char car3;
char *pointercar3;
char cartype;
void swapp(int *x,int *y){
int temp=0;
temp=*x;
*x=*y;
*y=temp;

}
void cartypefun(){
char *pointercartype;
  pointercartype=&car3;
  *pointercartype=car3;
  cartype=*pointercartype;
}
int maze1[23][30] = {
 // 1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 },
  { 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1 },
  { 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1 },
  { 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
  { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
  { 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1 },
  { 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1 },
  { 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1 },
  { 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1 },
  { 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1 },
  { 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1 },
  { 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1 },
  { 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1 },
  { 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1 },
  { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1 },
  { 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1 },
  { 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1 },
  { 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1 },
  { 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1 },
  { 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1 },
  { 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1 },
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 1 },
};
int maze2[23][30] = {
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 1, 2, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
  { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
  { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1 },
  { 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 4 },
  { 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1 },
  { 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
  { 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
  { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
  { 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1 },
  { 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1 },
  { 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1 },
  { 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
};
void bonus(){
 int a = rand() % 3;
 switch (a){
 case 0:
  score += 30;
  cartypefun();

 case 1:
  score -= 10;
  system("COLOR 2B");
 case 2:
     system("COLOR 03");
}
 }
void coutmaze1(){
 int bonus1x = rand() % 30;
 int bonus1y = rand() % 30;
 if (maze1[bonus1y][bonus1x] == 0){
  maze1[bonus1y][bonus1x] = 3;
 }

 for (int x = 0; x < 23; x++)
 {
  for (int y = 0; y < 30; y++)
  {
   switch (maze1[x][y])
   {
   case 0:
    cout << " ";
    break;
   case 1:
    cout << char(219);
    break;
   case 2:
    cout << cartype;
    break;
   case 3:
    cout << char(236);
    break;
   case 4:
    cout << "x";
   }
  }
  cout << " " << endl;
 }
}
void coutmaze2(){
 int bonus1x = rand() % 30;
 int bonus1y = rand() % 23;
 if (maze2[bonus1y][bonus1x] == 0){
  maze2[bonus1y][bonus1x] = 3;
 }

 for (int x = 0; x < 23; x++)
 {
  for (int y = 0; y < 30; y++)
  {
   switch (maze2[x][y])
   {
   case 0:
    cout << " ";
    break;
   case 1:
    cout << char(219);
    break;
   case 2:
   cout<<  cartype;
    break;
   case 3:
    cout << char(236);
    break;
   case 4:
    cout << "x";
   }
  }
  cout << " " << endl;
 }
}
void gameforcmp1(){
int koordx ;
 int koordy ;
 int koordxbef;
 int koordybef;
 int *pkoordxbef;
 int *pkoordybef;
 int *pkoordx;
 int *pkoordy;
 pkoordx=&koordx;
 pkoordy=&koordy;
  pkoordxbef=&koordxbef;
 pkoordybef=&koordybef;
 *pkoordx=1;
 *pkoordy=1;
  *pkoordxbef=1;
 *pkoordybef=1;



 bool apple = 1;
 char input;


 if (input == 'a'){
  score = 100;
 }
 coutmaze1();
 int start = time(NULL);
 int finish;
 int totaltime;
 while (apple){
  finish = time(NULL);
  totaltime = finish - start;
  if (totaltime>45){
   system("CLS");
   break;
  }
  srand(time(NULL));
  int q;
  q = rand() % 4;
  switch (q){
  case 0:
   input = 'w';
   break;
  case 1:
   input = 'a';
   break;
  case 2:
   input = 's';
   break;
  case 3:
   input = 'd';
   break;
  }

  if (input == 'w'){
   switch (maze1[koordy-1][koordx]){
   case 0:
       *pkoordy-=1;
     maze1[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze1[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef-= 1;
break;
   case 3:
     *pkoordy-=1;
     maze1[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze1[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef-= 1;
    bonus();
    break;
   case 1:
    if(duvar== 'n'){
        cout << "\a";
    maze1[koordy - 1][koordx] = 1;
    maze1[koordy][koordx] = 2;

    }
    if(duvar== 'y'){
            if(maze1[koordy-2][koordx]== 0 || maze1[koordy-2][koordx]== 3 || maze1[koordy-2][koordx]== 4){
                    score-=30;
      *pkoordy-=2;
     maze1[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze1[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef-= 2;

}
    }
    break;
   case 4:
    *pkoordy-=1;
     maze1[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze1[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef-= 1;
    break;
   }
   system("CLS");
   coutmaze1();
  }
  else if (input == 's'){
   switch (maze1[koordy + 1][koordx]){
   case 0:
    *pkoordy+=1;
     maze1[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze1[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef+= 1;
    break;
   case 3:
    *pkoordy+=1;
     maze1[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze1[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef+= 1;
    bonus();
    break;
   case 1:
    if(duvar== 'n'){
        cout << "\a";
    maze1[koordy + 1 ][koordx] = 1;
    maze1[koordy][koordx] = 2;
    }
    if(duvar== 'y'){
            if(maze1[koordy+2][koordx]== 0 || maze1[koordy+2][koordx]== 3 || maze1[koordy+2][koordx]== 4){
     *pkoordy+=2;
     maze1[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze1[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef+= 2;
    score-=30;

            }
    } break;
   case 4:
    *pkoordy+=1;
     maze1[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze1[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef+= 1;
    break;
   }
   system("CLS");
   coutmaze1();
  }
  else if (input == 'd'){
   switch (maze1[koordy][koordx + 1]){
   case 0:
    *pkoordx+=1;
    maze1[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze1[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef+=1;
    break;
   case 3:
     *pkoordx+=1;
    maze1[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze1[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef+=1;
    bonus();
    break;
   case 1:
    if(duvar== 'n'){
        cout << "\a";
    maze1[koordy ][koordx+1] = 1;
    maze1[koordy][koordx] = 2;
    }
    if(duvar== 'y'){
            if(maze1[koordy][koordx+2]== 0 || maze1[koordy][koordx+2]== 3 || maze1[koordy][koordx+2]== 4){
      *pkoordx+=2;
    maze1[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze1[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef+=2;
    score-=30;


            }
    }break;
   case 4:
     *pkoordx+=1;
    maze1[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze1[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef+=1;
    break;
   }

   system("CLS");
   coutmaze1();
  }
  else if (input == 'a'){
   switch (maze1[koordy][koordx - 1]){
   case 0:
     *pkoordx-=1;
    maze1[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze1[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef-=1;
    break;
   case 3:
     *pkoordx-=1;
    maze1[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze1[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef-=1;
    bonus();
    break;
   case 1:
    if(duvar== 'n'){
        cout << "\a";
    maze1[koordy ][koordx-1] = 1;
    maze1[koordy][koordx] = 2;
    }
    if(duvar== 'y'){
            if(maze1[koordy][koordx-2]== 0  || maze1[koordy][koordx-2]== 3 || maze1[koordy][koordx-2]== 4){
      *pkoordx-=2;
    maze1[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze1[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef-=2;
    score-=30;
            }} break;
   case 4:
     *pkoordx-=1;
    maze1[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze1[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef-=1;
    break;
   }
   system("CLS");
   coutmaze1();
  }
  if (koordy == 22){
   if (koordx == 28){
    apple = 0;
   }
  }

 }
 if (totaltime <= 45){
  system("CLS");
  cout << "Your score is" << " " << score << endl;
  Sleep(6000);
 }
 else{
  cout << "GAME OVER \n Your Score is  " << " " << score << endl;
 }
}
void gameforcmp2(){
 int koordx ;
 int koordy ;
 int koordxbef;
 int koordybef;
 int *pkoordxbef;
 int *pkoordybef;
 int *pkoordx;
 int *pkoordy;
 pkoordx=&koordx;
 pkoordy=&koordy;
  pkoordxbef=&koordxbef;
 pkoordybef=&koordybef;
 *pkoordx=1;
 *pkoordy=1;
  *pkoordxbef=1;
 *pkoordybef=1;

 bool apple = 1;
 char input;

 //cheat1
 if (input == 'a'){
  score = 100;
 }
 coutmaze2();
 int start = time(NULL);
 int finish;
 int totaltime;
 while (apple){
  finish = time(NULL);
  totaltime = finish - start;
  if (totaltime>45){
   system("CLS");
   break;
  }
  srand(time(NULL));
  int q;
  q = rand() % 4;
  switch (q){
  case 0:
   input = 'w';
   break;
  case 1:
   input = 'a';
   break;
  case 2:
   input = 's';
   break;
  case 3:
   input = 'd';
   break;
  }

  if (input == 'w'){
   switch (maze2[koordy-1][koordx]){
   case 0:
       *pkoordy-=1;
     maze2[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze2[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef-= 1;
break;
   case 3:
     *pkoordy-=1;
     maze2[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze2[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef-= 1;
    bonus();
    break;
   case 1:
    if(duvar== 'n'){
        cout << "\a";
    maze2[koordy - 1][koordx] = 1;
    maze2[koordy][koordx] = 2;

    }
    if(duvar== 'y'){
            if(maze2[koordy-2][koordx]== 0 || maze2[koordy-2][koordx]== 3 || maze2[koordy-2][koordx]== 4){
                    score-=30;
      *pkoordy-=2;
     maze2[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze2[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef-= 2;

}
    }
    break;
   case 4:
    *pkoordy-=1;
     maze2[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze2[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef-= 1;
    break;
   }
   system("CLS");
   coutmaze2();
  }
  else if (input == 's'){
   switch (maze2[koordy + 1][koordx]){
   case 0:
    *pkoordy+=1;
     maze2[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze2[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef+= 1;
    break;
   case 3:
    *pkoordy+=1;
     maze2[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze2[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef+= 1;
    bonus();
    break;
   case 1:
    if(duvar== 'n'){
        cout << "\a";
    maze2[koordy + 1 ][koordx] = 1;
    maze2[koordy][koordx] = 2;
    }
    if(duvar== 'y'){
            if(maze2[koordy+2][koordx]== 0 || maze2[koordy+2][koordx]== 3 || maze2[koordy+2][koordx]== 4){
     *pkoordy+=2;
     maze2[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze2[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef+= 2;
    score-=30;

            }
    } break;
   case 4:
    *pkoordy+=1;
     maze2[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze2[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef+= 1;
    break;
   }
   system("CLS");
   coutmaze2();
  }
  else if (input == 'd'){
   switch (maze2[koordy][koordx + 1]){
   case 0:
    *pkoordx+=1;
    maze2[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze2[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef+=1;
    break;
   case 3:
     *pkoordx+=1;
    maze2[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze2[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef+=1;
    bonus();
    break;
   case 1:
    if(duvar== 'n'){
        cout << "\a";
    maze2[koordy ][koordx+1] = 1;
    maze2[koordy][koordx] = 2;
    break;
    }
    if(duvar== 'y'){
            if(maze2[koordy][koordx+2]== 0 || maze2[koordy][koordx+2]== 3 || maze2[koordy][koordx+2]== 4){
      *pkoordx+=2;
    maze2[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze2[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef+=2;
    score-=30;

            }
    }break;
   case 4:
     *pkoordx+=1;
    maze2[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze2[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef+=1;
    break;
   }

   system("CLS");
   coutmaze2();
  }
  else if (input == 'a'){
   switch (maze2[koordy][koordx - 1]){
   case 0:
     *pkoordx-=1;
    maze2[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze2[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef-=1;
    break;
   case 3:
     *pkoordx-=1;
    maze2[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze2[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef-=1;
    bonus();
    break;
   case 1:
    if(duvar== 'n'){
        cout << "\a";
    maze2[koordy ][koordx-1] = 1;
    maze2[koordy][koordx] = 2;
    }
    if(duvar== 'y'){
            if(maze2[koordy][koordx-2]== 0  || maze2[koordy][koordx-2]== 3 || maze2[koordy][koordx-2]== 4){
      *pkoordx-=2;
    maze2[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze2[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef-=2;
    score-=30;
            }} break;
   case 4:
     *pkoordx-=1;
    maze2[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze2[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef-=1;
    break;
   }
   system("CLS");
   coutmaze2();
  }
  if (koordy == 11){
   if (koordx == 29){
    apple = 0;
   }
  }
 }
  if (koordy == 22){
   if (koordx == 28){
    apple = 0;
   }
  }
 if (totaltime <= 45){
  system("CLS");
  cout << "Your score is" << " " << score << endl << "you can now play level2" << endl;
  Sleep(3000);
 }
 else{
  cout << "GAME OVER \n Your Score is  " << " " << score << endl;
 }
}
void gameforplayer1(){
int koordx ;
 int koordy ;
 int koordxbef;
 int koordybef;
 int *pkoordxbef;
 int *pkoordybef;
 int *pkoordx;
 int *pkoordy;
 pkoordx=&koordx;
 pkoordy=&koordy;
  pkoordxbef=&koordxbef;
 pkoordybef=&koordybef;
 *pkoordx=1;
 *pkoordy=1;
  *pkoordxbef=1;
 *pkoordybef=1;

 bool apple = 1;
 char input;
 cout << "Press something and then enter to start to game" << endl;
 cin >> input;
 //cheat1
 if (input == 'a'){
  score = 100;
 }
 cout << " press a to go left \n       d to go right \n       w to go up \n       s to go down " << endl << endl;
 coutmaze1();
 int start = time(NULL);
 int finish;
 int totaltime;
 while (apple){
  finish = time(NULL);
  totaltime = finish - start;
  if (totaltime > 45){
   system("CLS");
   break;
  }
  input = _getch();
  if (input == 'w'){
   switch (maze1[koordy-1][koordx]){
   case 0:
       *pkoordy-=1;
     maze1[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze1[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef-= 1;
break;
   case 3:
     *pkoordy-=1;
     maze1[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze1[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef-= 1;
    bonus();
    break;
   case 1:
    if(duvar== 'n'){
        cout << "\a";
    maze1[koordy - 1][koordx] = 1;
    maze1[koordy][koordx] = 2;

    }
    if(duvar== 'y'){
            if(maze1[koordy-2][koordx]== 0 || maze1[koordy-2][koordx]== 3 || maze1[koordy-2][koordx]== 4){
                    score-=30;
      *pkoordy-=2;
     maze1[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze1[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef-= 2;

}
    }
    break;
   case 4:
    *pkoordy-=1;
     maze1[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze1[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef-= 1;
    break;
   }
   system("CLS");
   coutmaze1();
  }
  else if (input == 's'){
   switch (maze1[koordy + 1][koordx]){
   case 0:
    *pkoordy+=1;
     maze1[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze1[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef+= 1;
    break;
   case 3:
    *pkoordy+=1;
     maze1[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze1[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef+= 1;
    bonus();
    break;
   case 1:
    if(duvar== 'n'){
        cout << "\a";
    maze1[koordy + 1 ][koordx] = 1;
    maze1[koordy][koordx] = 2;
    }
    if(duvar== 'y'){
            if(maze1[koordy+2][koordx]== 0 || maze1[koordy+2][koordx]== 3 || maze1[koordy+2][koordx]== 4){
     *pkoordy+=2;
     maze1[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze1[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef+= 2;
    score-=30;

            }
    } break;
   case 4:
    *pkoordy+=1;
     maze1[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze1[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef+= 1;
    break;
   }
   system("CLS");
   coutmaze1();
  }
  else if (input == 'd'){
   switch (maze1[koordy][koordx + 1]){
   case 0:
    *pkoordx+=1;
    maze1[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze1[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef+=1;
    break;
   case 3:
     *pkoordx+=1;
    maze1[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze1[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef+=1;
    bonus();
    break;
   case 1:
    if(duvar== 'n'){
        cout << "\a";
    maze1[koordy ][koordx+1] = 1;
    maze1[koordy][koordx] = 2;
    break;
    }
    if(duvar== 'y'){
            if(maze1[koordy][koordx+2]== 0 || maze1[koordy][koordx+2]== 3 || maze1[koordy][koordx+2]== 4){
      *pkoordx+=2;
    maze1[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze1[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef+=2;
    score-=30;


            }
    }break;
   case 4:
     *pkoordx+=1;
    maze1[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze1[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef+=1;
    break;
   }

   system("CLS");
   coutmaze1();
  }
  else if (input == 'a'){
   switch (maze1[koordy][koordx - 1]){
   case 0:
     *pkoordx-=1;
    maze1[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze1[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef-=1;
    break;
   case 3:
     *pkoordx-=1;
    maze1[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze1[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef-=1;
    bonus();
    break;
   case 1:
    if(duvar== 'n'){
        cout << "\a";
    maze1[koordy ][koordx-1] = 1;
    maze1[koordy][koordx] = 2;
    }
    if(duvar== 'y'){
            if(maze1[koordy][koordx-2]== 0  || maze1[koordy][koordx-2]== 3 || maze1[koordy][koordx-2]== 4){
      *pkoordx-=2;
    maze1[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze1[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef-=2;
    score-=30;
            }} break;
   case 4:
     *pkoordx-=1;
    maze1[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze1[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef-=1;
break;
   }
   system("CLS");
   coutmaze1();
  }
  if (koordy == 22){
   if (koordx == 28){
    apple = 0;
   }
  }
 }

  if (totaltime <= 45){
   system("CLS");
   cout << "Your score is" << " " << score << endl << "you can now play level2" << endl;
   Sleep(4000);
  }
  else{
   cout << "GAME OVER \n Your Score is  " << " " << score << endl;
  }

}
void gameforplayer2(){
 int koordx ;
 int koordy ;
 int koordxbef;
 int koordybef;
 int *pkoordxbef;
 int *pkoordybef;
 int *pkoordx;
 int *pkoordy;
 pkoordx=&koordx;
 pkoordy=&koordy;
  pkoordxbef=&koordxbef;
 pkoordybef=&koordybef;
 *pkoordx=1;
 *pkoordy=1;
  *pkoordxbef=1;
 *pkoordybef=1;

 bool apple = 1;
 char input;
 cout << "Press something and then enter to start to game" << endl;
 cin >> input;
 cout << " press a to go left \n       d to go right \n       w to go up \n       s to go down " << endl << endl;
 coutmaze2();
 int start = time(NULL);
 int finish;
 int totaltime;
 while (apple){
  finish = time(NULL);
  totaltime = finish - start;
  if (totaltime > 90){
   system("CLS");
   break;
  }
  input = _getch();
  if (input == 'w'){
   switch (maze2[koordy-1][koordx]){
   case 0:
       *pkoordy-=1;
     maze2[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze2[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef-= 1;
break;
   case 3:
     *pkoordy-=1;
     maze2[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze2[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef-= 1;
    bonus();
    break;
   case 1:
    if(duvar== 'n'){
        cout << "\a";
    maze2[koordy - 1][koordx] = 1;
    maze2[koordy][koordx] = 2;

    }
    if(duvar== 'y'){
            if(maze2[koordy-2][koordx]== 0 || maze2[koordy-2][koordx]== 3 || maze2[koordy-2][koordx]== 4){
                    score-=30;
      *pkoordy-=2;
     maze2[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze2[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef-= 2;

}
    }
    break;
   case 4:
    *pkoordy-=1;
     maze2[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze2[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef-= 1;
    break;
   }
   system("CLS");
   coutmaze2();
  }
  else if (input == 's'){
   switch (maze2[koordy + 1][koordx]){
   case 0:
    *pkoordy+=1;
     maze2[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze2[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef+= 1;
    break;
   case 3:
    *pkoordy+=1;
     maze2[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze2[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef+= 1;
    bonus();
    break;
   case 1:
    if(duvar== 'n'){
        cout << "\a";
    maze2[koordy + 1 ][koordx] = 1;
    maze2[koordy][koordx] = 2;
    }
    if(duvar== 'y'){
            if(maze2[koordy+2][koordx]== 0 || maze2[koordy+2][koordx]== 3 || maze2[koordy+2][koordx]== 4){
     *pkoordy+=2;
     maze2[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze2[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef+= 2;
    score-=30;

            }
    } break;
   case 4:
    *pkoordy+=1;
     maze2[*pkoordy][koordx] = 2;
     swapp(pkoordy,pkoordybef);
    maze2[*pkoordy][koordx] = 0;
 swapp(pkoordy,pkoordybef);
*pkoordybef+= 1;
    break;
   }
   system("CLS");
   coutmaze2();
  }
  else if (input == 'd'){
   switch (maze2[koordy][koordx + 1]){
   case 0:
    *pkoordx+=1;
    maze2[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze2[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef+=1;
    break;
   case 3:
     *pkoordx+=1;
    maze2[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze2[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef+=1;
    bonus();
    break;
   case 1:
    if(duvar== 'n'){
        cout << "\a";
    maze2[koordy ][koordx+1] = 1;
    maze2[koordy][koordx] = 2;
    break;
    }
    if(duvar== 'y'){
            if(maze2[koordy][koordx+2]== 0 || maze2[koordy][koordx+2]== 3 || maze2[koordy][koordx+2]== 4){
      *pkoordx+=2;
    maze2[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze2[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef+=2;
    score-=30;


            }
    }break;
   case 4:
     *pkoordx+=1;
    maze2[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze2[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef+=1;
    break;
   }

   system("CLS");
   coutmaze2();
  }
  else if (input == 'a'){
   switch (maze2[koordy][koordx - 1]){
   case 0:
     *pkoordx-=1;
    maze2[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze2[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef-=1;
    break;
   case 3:
     *pkoordx-=1;
    maze2[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze2[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef-=1;
    bonus();
    break;
   case 1:
    if(duvar== 'n'){
        cout << "\a";
    maze2[koordy ][koordx-1] = 1;
    maze2[koordy][koordx] = 2;
    }
    if(duvar== 'y'){
            if(maze2[koordy][koordx-2]== 0  || maze2[koordy][koordx-2]== 3 || maze2[koordy][koordx-2]== 4){
      *pkoordx-=2;
    maze2[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze2[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef-=2;
    score-=30;
            }} break;
   case 4:
     *pkoordx-=1;
    maze2[koordy][*pkoordx]=2;
    swapp(pkoordx,pkoordxbef);
    maze2[koordy][*pkoordx]=0;
    swapp(pkoordx,pkoordxbef);
    *pkoordxbef-=1;
    break;
   }
   system("CLS");
   coutmaze2();
  }
  if (koordy == 11){
   if (koordx == 29){
    apple = 0;
   }
  }
 }

  if (totaltime <= 90){
   system("CLS");
   cout << "Your score is" << " " << score << endl;
   Sleep(4000);
  }
  else{
   cout << "GAME OVER \n Your Score is  " << " " << score << endl;
  }

}
int main(){
 pointercar1=&car1;
 *pointercar1=char(124);
 pointercar2=&car2;
 *pointercar2=char(61);
 pointercar3=&car3;
 *pointercar3=char(1);


 int m;
 cout << "If you want to play the game press 1" << endl << "If you want to watch press 2" << endl;
 cin >> m;
 if (m == 1){
        int i;
        cout<< " Please choose your car type 1 or 2 " << endl;
        cin >> i;

 if (i==1){
    cartype=car1;

 }
 else if(i==2){
    cartype=car2;
    }
 system("CLS");
   cout<< " Do you want to jump over the wall during the game? You will loose 30 points each time if you say yes " << endl;
   cout<< "If your answer is yes press y and n for otherwise" << endl;
   cin>>duvar;
 system("CLS");


int cheatlocker;
cout << "\nWould you prefer the easy way?\n" << "If you say yes, press 1.\n" << "If you say no, then press 0.\n" << endl;
cin >> cheatlocker;
int manyCheats;
if (cheatlocker == 1){
cout << "\nYou'd better be ready." << endl;
cout << "Press 1 for " << " Seeing how to gain 100 extra points! " << endl;
cout << "Press 2 for " << " Continuing to 2nd level!" << endl;
cout << "Press 3 for " << " Earning up to 500 points. " << endl;
cin >> manyCheats;
system("CLS");
switch (manyCheats)
{
case 1:
cout << "Press on button \"a\" right now. You will automatically earn 100 points." << endl;
break;

case 2:
cout << "Life will not be that easy all the time. But it's easy for this time, congratz folk!" << endl;
break;

case 3:
  srand(time(NULL));
score+= (rand() % 500)+1;
cout << "You started game with" << " " << score << endl;
Sleep(4000);

break;
}
}
if (cheatlocker == 0){
cout << " May the force be with you " << endl;
system("CLS");
gameforplayer1();
if (totaltime<=45){
gameforplayer2();}
}

if (cheatlocker == 1){
if (manyCheats==1){
    gameforplayer1();
    if (totaltime<=45){
gameforplayer2();}
 }
 if (manyCheats==2 ){
   gameforplayer2();
    }
 if(manyCheats==3){
    gameforplayer1();
    if (totaltime<=45){
gameforplayer2();}
 }
 }
 }
if (m == 2){
int i=rand()%2;
if (i==0){
    cartype=car1;
    }
 else if(i==1){
    cartype=car2;
    }
 Sleep(1000) ;

 system("CLS");
   cout<< " Do you want to jump over the wall during the game? " << endl;
   cout<< "If your answer is yes press y and n for otherwise" << endl;
   Sleep(1000) ;

   srand(time(NULL));
   int k=rand()%2;
if (k==0){
    duvar='y';
}
 if (k==1){
    duvar='n';
}
 system("CLS");



int cheatlocker;
cout << "\nWould you prefer the easy way?\n" << "If you say yes, press 1.\n" << "If you say no, then press 0.\n" << endl;
 Sleep(1000) ;
 srand(time(NULL));
 int b=rand() % 2;
 if(b==0){
  cheatlocker=1;
 }
 if(b==1){
  cheatlocker=0;
 }
int manyCheats;
if (cheatlocker == 1){
cout << "\nYou'd better be ready." << endl;
cout << "Press 0 for " << " seeing how to gain 100 extra points! " << endl;
cout << "Press 1 for " << " continuing to 2nd level!" << endl;
cout << "Press 2 for " << " earning up to 500 points. " << endl;
Sleep(1000) ;
srand(time(NULL));
int manyCheats=rand()%3;

switch (manyCheats)
{
case 0:
cout << "press on button \"a\" right now. You will automatically earn 100 points." << endl;

    gameforcmp1();
if (totaltime<=90){

gameforcmp2();
 }
break;

case 1:
cout << "Life will not be that easy all the time. But it's easy for this time, congratz folk!" << endl;
gameforcmp2();
 break;

case 2:
  srand(time(NULL));
score+= (rand() % 501);
cout << "You started game with" << " " << score << endl;
Sleep(4000);
    gameforcmp1();
if (totaltime<=90){
gameforcmp2();
 }

break;
}
}
if (cheatlocker == 0){
cout << " May the force be with you " << endl;
system("CLS");
gameforcmp1();
if(totaltime<=90){
    gameforcmp2();
}
}

 int highscore;
ifstream inputx("score.txt");
inputx >> highscore;
if (highscore > score) {

}
else {

highscore = score;
ofstream file("score.txt");
file << highscore;
}
cout << "HIGH SCORE:" << highscore << endl;
 return 0;
}}
