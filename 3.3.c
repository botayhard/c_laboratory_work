#include <stdio.h>

int check_day(int m, int y){
    int monday[12]={31,28,31,30,31,30,31,31,30,31,30,31},cor=0;
    if(m==2&&((y%4==0&&y%100!=0)||y%400==0)){cor+=1;}
    return monday[m-1]+cor;
}

int all_days(int day,int month,int year){
    int sum[12]={0,31,59,90,120,151,181,212,243,273,304,334},sumV[12]={0,31,60,91,121,152,182,213,244,274,305,335};
    int check_year=((year%4)==0&&(year%100)!=0)||(year%400)==0;
    return year*365+(year+3)/4-(year+99)/100+(year+399)/400+((check_year)?sumV:sum)[month-1]+day-1;
}

int main() {
    int temp,d1,m1,y1,d2,m2,y2;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d %d %d\n",&d1,&m1,&y1);
    scanf("%d %d %d\n",&d2,&m2,&y2);
    if(d1>check_day(m1,y1)||m1>12||y1>2012||d1<1||m1<1||y1<1){printf("ERROR");return 0;}
    if(d2>check_day(m2,y2)||m2>12||y2>2012||d2<1||m2<1||y2<1){printf("ERROR");return 0;}
    temp=all_days(d1,m1,y1)-all_days(d2,m2,y2);
    printf("%d",(temp<0)?(-1*temp):(temp));
}