#include <iostream>  
#include <cstdio>  
#include <cstdlib>  
#include <cmath>  
#include <algorithm>  

using namespace std;  

char flag;
double num;
bool fT,fD,fH;
double T,D,H;
double E,humidex;
/*
指数运算 exp log
*/
int main()
{
    while(scanf("%c",&flag)){
        if( flag == 'E'){
            break;
        }
        fT = fD = fH = false;
        scanf("%lf",&num);
        if(flag == 'T')
        {
            T = num;
            fT = true;
        }

        if(flag == 'D')
        {
            D = num;
            fD = true;
        }

        if(flag == 'H')
        {
            humidex = num;
            fH = true;
        }

        getchar();
        scanf("%c",&flag);
        getchar();
        scanf("%lf",&num);

         if(flag == 'T')
        {
            T = num;
            fT = true;
        }

        if(flag == 'D')
        {
            D = num;
            fD = true;
        }

        if(flag == 'H')
        {
            humidex = num;
            fH = true;
        }

        if(fT && fD)
        {
            E = 6.11 * exp((5417.7530)*((1/273.16)-(1/(D+273.16))));
            H = (0.5555)*(E-10.0);
            humidex = T + H;
        }else if(fT && fH)
        {
            H = humidex - T;
            E = H/(0.5555)+10.0;
            D = 1/(-(log(E/6.11)/5417.7530)+(1/273.16))-273.16;
        }else if(fH && fD){
             E = 6.11 * exp((5417.7530)*((1/273.16)-(1/(D+273.16))));
             H = (0.5555)*(E -10.0);
             T = humidex - H;
        }
        printf("T %.1lf D %.1lf H %.1lf\n",T,D,humidex);  
      getchar();

    }
    return 0;
}
