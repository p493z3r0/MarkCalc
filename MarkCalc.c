//
//  MarkCalc.c
//
//Created by Dominic Järmann on 20.10.15.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int cleanup(){
    exit(0);
}

int OnError(char* errormsg, int errorint){
    printf("Error: <%s> occurret. Error code is: %d\n", errormsg, errorint);
    exit(errorint);
}

void MarkGenerator(int argc, char * argv[])
{
    double MaxPoint = strtod(argv[2], NULL);
    double PointsReached = strtod(argv[1], NULL);
    double temp = 0;
    if (PointsReached > MaxPoint){
        printf("\x1b[31m Not Compartible input detected. Correcting Data.. \x1b[0m \n");
        temp = MaxPoint;
        MaxPoint = PointsReached;
        PointsReached = 0;
        PointsReached = temp;
        temp = 0;
        printf("\x1b[32m Data Corrected. Continuing.. \x1b[0m \n");
    }
    temp = PointsReached / MaxPoint;
    temp = temp * 5;
    temp = temp +1;
    if (temp > 6){
        
        printf("\x1b[31m Need superuser, please type in your password.\x1b[0m \n");
        system("sudo true");
        FILE *f = fopen("/Library/Logs/calc.log", "w");
        if (f == NULL)
        {
            OnError("Error opening file", 22);
            exit(1);
        }
        fprintf(f, "Content Of Temp: %lf\n", temp);
        fprintf(f, "Content Of MaxPoint: %lf\n", MaxPoint);
        fprintf(f, "Content Of PointsReached: %lf\n", PointsReached);
        fprintf(f, "Content Of argv[1]: %s\n", argv[1]);
        fprintf(f, "Content Of argv[2]: %s\n", argv[2]);
        fclose(f);
        OnError("\x1b[31m Somthing went wrong. The output is greater than six. If You know about this bug, please send an email to dominic.jaermann@icloud.com and attach the Log File (stored in /Library/Logs/calc.log)\x1b[0m ", -3);
        temp = 0;
    }
    if (temp != temp){
        printf("\n%lf\n", temp);
        OnError("\x1b[31m NaN, or Stringoverflow Detected \x1b[0m", -34);
        
    }else{
        float val = temp;
        float nearest = roundf(val * 100) / 100;
        printf("\x1b[32m %.1f\n \x1b[0m", nearest);
        cleanup();
    }
}
int main(int argc, char* argv[]){
    if (argc < 3) {
        printf("Usage: %s <Points Reached> <Max Point>\n", argv[0]);
        printf("Example:\n %s 60 120\n", argv[0]);
        printf("\x1b[32m Output:\n 3.5 \x1b[0m \n");
        exit(1);
    }
    if (argc > 3){
        printf("Usage: %s <Points Reached> <Max Point>\n", argv[0]);
        printf("Example:\n %s 60 120\n", argv[0]);
        printf("\x1b[32m Output:\n 3.5 \x1b[0m \n\x1b[32m \n");
        exit(1);
    }
    
    MarkGenerator(argc, argv);
    return 0;
}

