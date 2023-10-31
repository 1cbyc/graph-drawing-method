// Created by Isaac Nsisong
// Instagram: @NsisongLabs

#include <iostream>
#include <string>
const int DMS = 17;

/* This is probably one of the craziest shit that I've attempted at the time. It took me one sleepless night to calculate and discover the algorithm behind converting a mxm array to a (not so) proper *coughs* cartesian plane, AND I HAD TO FIX DISPLAY ISSUE BECAUSE SOME SCREENS DOESN'T DISPLAY ASCII CHARACTER WIDTH PROPERLY AND MESSED UP THE GRAPH. I originally wanted to make the values float, but now ehn, I just want to go and sleep for the rest of the day. 

 * Input integer values for m and c, to plot graph coordinates of straight line y = mx + c, where m is the gradient of the line and c (or also commonly known as b) is the y-intercept of the line. */ 

void plot(int m, int c, std::string arr[DMS][DMS*2+1])
{
    for (int x=-DMS; x<DMS+1; x++)
        if ((-(m*x+c)+DMS/2)<DMS&&(-(m*x+c)+DMS/2)>=0&&(x*2+DMS)<DMS*2+1&&(x*2+DMS)>= 0)
            arr[(-(m*x+c)+ DMS/2)][x*2+DMS] = "x";
}
            
int main()
{try
{
    std::string arr[DMS][DMS*2+1];
    int m, c; std::cin >> m >> c;
 
    if (std::cin.fail()) throw 1;

    for (int i=0; i<DMS; i++)
        for (int j=0; j<DMS*2+1; j++)
            arr[i][j]=(i==DMS/2?std::string(1,'-'):(j==DMS?std::string(1,char(197)):" "));
        
    arr[DMS/2][DMS] = std::string(1, char(197));
    
    plot(m,c,arr);

    for (int i=0; i<DMS; i++, std::cout << "\n")
        for (int j=0; j<DMS*2+1; j++)
            std::cout << arr[i][j];
            
    return 0;
}
catch(int err)
{
    std::cout << "Invalid input. Please try again.";
}}
