#include <stdio.h>
int main(){
    int score;
    printf("Enter 0 or 1 to STOP\n");
    printf("Enter the NFL score: ");
    scanf("%d", &score);

    //TD represents the number of touchdowns, FG represents the number of fieldgoals, etc.
    while (score > 1){
        printf("Possible combinations of scoring plays:\n");
        for (int TD = 0; TD <= score/6; TD++){
            for (int FG = 0; FG <= score/3; FG++){
                for (int safety = 0; safety <= score/2; safety++){
                    for (int TD_twopt = 0; TD_twopt <= score/8; TD_twopt++){
                        for (int TD_oneptFG = 0; TD_oneptFG <= score/7; TD_oneptFG ++){
                            if (score == 6*TD + 3*FG + 2*safety + 8*TD_twopt + 7*TD_oneptFG){
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", TD_twopt, TD_oneptFG, TD, FG, safety);
                            }
                        }
                    }
                
                    }
                }
            }
        
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        }
    return 0;
    }
   
    

