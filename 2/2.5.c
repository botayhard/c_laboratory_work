//
// Created by botayhard on 11.02.19.
//

#include<stdio.h>

int iamautist(unsigned long long n){
    unsigned long long cerf;
    char str[11];
    if(n<10){return n;}
    if(n<190){
        cerf = (n-10)/2+10;
        str[0] = cerf%10; cerf/=10;
        str[1] = cerf;
        return str[1-n%2];
    }
    if(n<2890){
        cerf = (n-190)/3+100;
        str[0] = cerf%10; cerf/=10;
        str[1] = cerf%10; cerf/=10;
        str[2] = cerf;
        return str[2-((n-190)%3)];
    }
    if(n<38890){
        cerf = (n-2890)/4+1000;
        str[0] = cerf%10; cerf /= 10;
        str[1] = cerf%10; cerf /= 10;
        str[2] = cerf%10; cerf /= 10;
        str[3] = cerf;
        return str[3-((n-2890)%4)];
    }
    if(n<488890){
        cerf = (n-38890)/5+10000;
        str[0] = cerf%10; cerf /= 10;
        str[1] = cerf%10; cerf /= 10;
        str[2] = cerf%10; cerf /= 10;
        str[3] = cerf%10; cerf /= 10;
        str[4] = cerf;
        return str[4-((n-38890)%5)];
    }
    if(n<5888890){
        cerf = (n-488890)/6+100000;
        str[0] = cerf%10; cerf /= 10;
        str[1] = cerf%10; cerf /= 10;
        str[2] = cerf%10; cerf /= 10;
        str[3] = cerf%10; cerf /= 10;
        str[4] = cerf%10; cerf /= 10;
        str[5] = cerf;
        return str[5-((n-488890)%6)];
    }
    if(n<68888890){
        cerf = (n-5888890)/7+1000000;
        str[0] = cerf%10; cerf /= 10;
        str[1] = cerf%10; cerf /= 10;
        str[2] = cerf%10; cerf /= 10;
        str[3] = cerf%10; cerf /= 10;
        str[4] = cerf%10; cerf /= 10;
        str[5] = cerf%10; cerf /= 10;
        str[6] = cerf;
        return str[6-((n-5888890)%7)];
    }
    if(n<788888890){
        cerf = (n-68888890)/8+10000000;
        str[0] = cerf%10; cerf /= 10;
        str[1] = cerf%10; cerf /= 10;
        str[2] = cerf%10; cerf /= 10;
        str[3] = cerf%10; cerf /= 10;
        str[4] = cerf%10; cerf /= 10;
        str[5] = cerf%10; cerf /= 10;
        str[6] = cerf%10; cerf /= 10;
        str[7] = cerf;
        return str[7-((n-68888890)%8)];
    }
    if(n<8888888890){
        cerf = (n-788888890)/9+100000000;
        str[0] = cerf%10; cerf /= 10;
        str[1] = cerf%10; cerf /= 10;
        str[2] = cerf%10; cerf /= 10;
        str[3] = cerf%10; cerf /= 10;
        str[4] = cerf%10; cerf /= 10;
        str[5] = cerf%10; cerf /= 10;
        str[6] = cerf%10; cerf /= 10;
        str[8] = cerf%10; cerf /= 10;
        str[9] = cerf;
        return str[8-((n-788888890)%9)];
    }
}

int main(){
    unsigned long long n;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%lld",&n);
    printf("%d",iamautist(n));
}