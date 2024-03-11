#include <stdio.h>
#include <math.h>

void sales_report(double sales[12], char* months[12]){
    /*print monthly sales report*/
   printf("Monthly sales report for 2022:\n");
   printf("Month\t\t\tSales\n");
   for (int i = 0; i < 12; i++){
       printf("%-10s\t\t", months[i]); 
       printf("$");
       printf("%.2f\n", sales[i]);
   }
}

void sales_summary(double sales[12], char* months[12]){
   /*find min sale*/
   double min_sale = sales[0];
   for (int i = 1; i < 12; i++){
       if  (sales[i] < min_sale){
           min_sale = sales[i];
       }
   }
   
   /* find max sale */
   double max_sale = sales[0];
   for (int i = 1; i < 12; i++){
       if  (sales[i] > max_sale){
           max_sale = sales[i];
       }
   }

   /*find average sale*/
   double sum_of_sales = sales[0];
   for (int i = 1; i < 12; i++){
       sum_of_sales += sales[i];
   }
   double average_sale = sum_of_sales/12;

   /*find month of min sale and max sale*/
   char *min_month, *max_month;
   for (int i = 0; i < 12; i++){
       if  (sales[i] == min_sale){
           min_month = months[i]; //min_month is a character pointer
       }
       if  (sales[i] == max_sale){
           max_month = months[i]; //max_month is a character pointer
       }
   }

   /*print sales summary*/
   printf("Sales summary:\n");
   printf("Minimum sales:\t\t$%-10.2f(%s)\n", min_sale, min_month);
   printf("Maximum sales:\t\t$%-10.2f(%s)\n", max_sale, max_month);
   printf("Average sale:\t\t$%-10.2f\n", average_sale);
}

void moving_avg_report(double sales[12], char* months[12]){
    printf("Six-Month Moving Average Report:\n");
    for (int i = 0; i < 7; i++){
        char* first_month = months[i]; //first_month points to the first character in months[i]
        char* last_month = months[i+5];
        
        double sum_of_sales = sales[i];
        for (int n = i+1; n < i+6; n++){
            sum_of_sales += sales[n];
        }
        double average_sale = roundf((sum_of_sales/6)*100)/100;

        printf("%-10s -  %-10s $%.2f\n", first_month, last_month, average_sale);
    }
}

void hi_low_sales(double sales[12], char* months[12]){
    printf("Month\t\tSales\n");
    double ranked_sales[12];
    char* ranked_months[12];

    //Copy original array values to the ranked arrays
    for (int i = 0; i < 12; i++){
        ranked_sales[i] = sales[i];
        ranked_months[i] = months[i];
    }

    //bubble sort
    /*for (int i = 0; i < 11; i++){
        for (int j = 0; j < 12-i-1; j++){
            
            if (sales[j] > sales[j+1]){
                sales[j] = sales[j+1];
                printf("%.2f\n", sales[j]);
                months[j] = months[j+1];
                printf("%s\n", months[j]);

                sales[j+1] = sales[j];
                months[j+1] = months[j];
            }
        }
        
    }*/
    for (int i = 0; i < 12 - 1; i++) {
        for (int j = 0; j < 12 - i - 1; j++) {
            if (ranked_sales[j] < ranked_sales[j + 1]) {
                // Swap sales
                double temp_sales = ranked_sales[j];
                ranked_sales[j] = ranked_sales[j + 1];
                ranked_sales[j + 1] = temp_sales;
                
                // Swap months
                char* temp_months = ranked_months[j];
                ranked_months[j] = ranked_months[j + 1];
                ranked_months[j + 1] = temp_months;

                
            }
        }
    }

    for (int i = 0; i < 12; i++){
        printf("%-10s\t$%.2f\n", ranked_months[i], ranked_sales[i]);
    }
}
int main(){
    double sales[12] = {23458.01,40112.00,56011.85,37820.88,37904.67,60200.22,72400.31,56210.89,67230.84,68233.12,80950.34,95225.22};
    char* months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    sales_report(sales, months);
    printf("\n");
    sales_summary(sales, months);
    printf("\n");
    moving_avg_report(sales, months);
    printf("\n");
    hi_low_sales(sales, months);
}