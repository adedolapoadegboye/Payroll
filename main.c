#include <stdio.h>
#include <stdbool.h>
#include <string.h>  // Required for strcmp()

int main() {
    // Payroll Calculator;
    char username[20];
    char choice;
    bool validChoice;
    const char *choiceList[] = {"Hourly", "Daily", "Weekly", "Bi-Weekly", "Monthly", "Yearly"};
    
    float hours;
    float days;
    float userHourlyRate;
    float userDailyRate;
    float userWeeklyRate;
    float userBiWeeklyRate;
    float userMonthlyRate;
    float userYearlyRate;
    
    float overtimeHours;
    float userHourlyOvertimeRate;
    float userDailyOvertimeRate;
    float userWeeklyOvertimeRate;
    float userBiWeeklyOvertimeRate;
    float userMonthlyOvertimeRate;
    float userYearlyOvertimeRate;

    printf("\nWelcome to the Payroll Calculator. Please enter your name to get started: \n");
    scanf("%s", username);

    printf("\nHello, %s. Welcome to the Payroll Calculator. \n", username);

    do {
        printf("\nPlease choose one of the following income options: \n");
        printf("0. Hourly \n");
        printf("1. Daily \n");
        printf("2. Weekly \n");
        printf("3. Bi-Weekly \n");
        printf("4. Monthly \n");
        printf("5. Yearly \n");

        validChoice = scanf(" %c", &choice) == 1 && choice >= '0' && choice <= '5';

        if (!validChoice) {
            printf("\nInvalid choice. Please try again. \n");
            // Clear the input buffer
            while (getchar() != '\n' && getchar() != EOF);
        } else {
            // Convert character choice to an integer index
            int index = choice - '0';
            const char *userChoice = choiceList[index];

            // Clear the input buffer after user input
            while (getchar() != '\n' && getchar() != EOF);

            // Use strcmp to compare the strings
            if (strcmp(userChoice, "Hourly") == 0) {
                // Standard rates
                printf("\nWhat is your hourly rate (CAD)? \n");
                scanf("%f", &userHourlyRate);

                printf("\nHow many hours do you work in a day (standard, non-overtime)? \n");
                scanf("%f", &hours);

                printf("\nHow many days do you work in a week (standard, non-overtime)? \n");
                scanf("%f", &days);

                userDailyRate = hours * userHourlyRate;
                userWeeklyRate = userDailyRate * days;
                userBiWeeklyRate = userWeeklyRate * 2;
                userMonthlyRate = userBiWeeklyRate * 2;
                userYearlyRate = userMonthlyRate * 12;

                // Overtime rates
                printf("\nHow many hours do you usually work overtime in a day? \n");
                scanf("%f", &overtimeHours);

                userHourlyOvertimeRate = 1.5 * userHourlyRate;
                userDailyOvertimeRate = userHourlyOvertimeRate * overtimeHours;
                userWeeklyOvertimeRate = userDailyOvertimeRate * days;
                userBiWeeklyOvertimeRate = userWeeklyOvertimeRate * 2;
                userMonthlyOvertimeRate = userBiWeeklyOvertimeRate * 2;
                userYearlyOvertimeRate = userMonthlyOvertimeRate * 12;

                // Total Gross Income 
                float totalDailyIncome = userDailyRate + userDailyOvertimeRate;
                float totalWeeklyIncome = userWeeklyRate + userWeeklyOvertimeRate;
                float totalBiWeeklyIncome = userBiWeeklyRate + userBiWeeklyOvertimeRate;
                float totalMonthlyIncome = userMonthlyRate + userMonthlyOvertimeRate;
                float totalYearlyIncome = userYearlyRate + userYearlyOvertimeRate;

                printf("\nHere's the breakdown of your gross income (income before tax): \n");
                printf("\nYour estimated total daily income: %.2f CAD\n", totalDailyIncome);
                printf("Your estimated weekly income: %.2f CAD\n", totalWeeklyIncome);
                printf("Your estimated biweekly income: %.2f CAD\n", totalBiWeeklyIncome);
                printf("Your estimated monthly income: %.2f CAD\n", totalMonthlyIncome);
                printf("Your estimated yearly income: %.2f CAD\n", totalYearlyIncome);

            } else if (strcmp(userChoice, "Daily") == 0) {
                // Standard rates
                printf("\nWhat is your daily rate (CAD)? \n");
                scanf("%f", &userDailyRate);

                printf("\nHow many hours do you work in a day (standard, non-overtime)? \n");
                scanf("%f", &hours);

                printf("\nHow many days do you work in a week (standard, non-overtime)? \n");
                scanf("%f", &days);

                userHourlyRate = userDailyRate / hours;
                userWeeklyRate = userDailyRate * days;
                userBiWeeklyRate = userWeeklyRate * 2;
                userMonthlyRate = userBiWeeklyRate * 2;
                userYearlyRate = userMonthlyRate * 12;

                // Overtime rates
                printf("\nHow many hours do you usually work overtime in a day? \n");
                scanf("%f", &overtimeHours);

                userHourlyOvertimeRate = 1.5 * userHourlyRate;
                userDailyOvertimeRate = userHourlyOvertimeRate * overtimeHours;
                userWeeklyOvertimeRate = userDailyOvertimeRate * days;
                userBiWeeklyOvertimeRate = userWeeklyOvertimeRate * 2;
                userMonthlyOvertimeRate = userBiWeeklyOvertimeRate * 2;
                userYearlyOvertimeRate = userMonthlyOvertimeRate * 12;

                // Total Gross Income 
                float totalDailyIncome = userDailyRate + userDailyOvertimeRate;
                float totalWeeklyIncome = userWeeklyRate + userWeeklyOvertimeRate;
                float totalBiWeeklyIncome = userBiWeeklyRate + userBiWeeklyOvertimeRate;
                float totalMonthlyIncome = userMonthlyRate + userMonthlyOvertimeRate;
                float totalYearlyIncome = userYearlyRate + userYearlyOvertimeRate;

                printf("\nHere's the breakdown of your gross income (income before tax): \n");
                printf("\nYour estimated total daily income: %.2f CAD\n", totalDailyIncome);
                printf("Your estimated weekly income: %.2f CAD\n", totalWeeklyIncome);
                printf("Your estimated biweekly income: %.2f CAD\n", totalBiWeeklyIncome);
                printf("Your estimated monthly income: %.2f CAD\n", totalMonthlyIncome);
                printf("Your estimated yearly income: %.2f CAD\n", totalYearlyIncome);


            } else if (strcmp(userChoice, "Weekly") == 0) {
                // Standard rates
                printf("\nWhat is your weekly rate (CAD)? \n");
                scanf("%f", &userWeeklyRate);

                printf("\nHow many hours do you work in a day (standard, non-overtime)? \n");
                scanf("%f", &hours);

                printf("\nHow many days do you work in a week (standard, non-overtime)? \n");
                scanf("%f", &days);

                userDailyRate = userWeeklyRate / days;
                userHourlyRate = userDailyRate / hours;
                userBiWeeklyRate = userWeeklyRate * 2;
                userMonthlyRate = userBiWeeklyRate * 2;
                userYearlyRate = userMonthlyRate * 12;

                // Overtime rates
                printf("\nHow many hours do you usually work overtime in a day? \n");
                scanf("%f", &overtimeHours);

                userHourlyOvertimeRate = 1.5 * userHourlyRate;
                userDailyOvertimeRate = userHourlyOvertimeRate * overtimeHours;
                userWeeklyOvertimeRate = userDailyOvertimeRate * days;
                userBiWeeklyOvertimeRate = userWeeklyOvertimeRate * 2;
                userMonthlyOvertimeRate = userBiWeeklyOvertimeRate * 2;
                userYearlyOvertimeRate = userMonthlyOvertimeRate * 12;

                // Total Gross Income 
                float totalDailyIncome = userDailyRate + userDailyOvertimeRate;
                float totalWeeklyIncome = userWeeklyRate + userWeeklyOvertimeRate;
                float totalBiWeeklyIncome = userBiWeeklyRate + userBiWeeklyOvertimeRate;
                float totalMonthlyIncome = userMonthlyRate + userMonthlyOvertimeRate;
                float totalYearlyIncome = userYearlyRate + userYearlyOvertimeRate;

                printf("\nHere's the breakdown of your gross income (income before tax): \n");
                printf("\nYour estimated total daily income: %.2f CAD\n", totalDailyIncome);
                printf("Your estimated weekly income: %.2f CAD\n", totalWeeklyIncome);
                printf("Your estimated biweekly income: %.2f CAD\n", totalBiWeeklyIncome);
                printf("Your estimated monthly income: %.2f CAD\n", totalMonthlyIncome);
                printf("Your estimated yearly income: %.2f CAD\n", totalYearlyIncome);


            } else if (strcmp(userChoice, "Bi-Weekly") == 0) {
                // Standard rates
                printf("\nWhat is your bi-weekly rate (CAD)? \n");
                scanf("%f", &userBiWeeklyRate);

                printf("\nHow many hours do you work in a day (standard, non-overtime)? \n");
                scanf("%f", &hours);

                printf("\nHow many days do you work in a week (standard, non-overtime)? \n");
                scanf("%f", &days);

                userWeeklyRate = userBiWeeklyRate / 2;
                userDailyRate = userWeeklyRate / days;
                userHourlyRate = userDailyRate / hours;
                userMonthlyRate = userBiWeeklyRate * 2;
                userYearlyRate = userMonthlyRate * 12;

                // Overtime rates
                printf("\nHow many hours do you usually work overtime in a day? \n");
                scanf("%f", &overtimeHours);

                userHourlyOvertimeRate = 1.5 * userHourlyRate;
                userDailyOvertimeRate = userHourlyOvertimeRate * overtimeHours;
                userWeeklyOvertimeRate = userDailyOvertimeRate * days;
                userBiWeeklyOvertimeRate = userWeeklyOvertimeRate * 2;
                userMonthlyOvertimeRate = userBiWeeklyOvertimeRate * 2;
                userYearlyOvertimeRate = userMonthlyOvertimeRate * 12;

                // Total Gross Income 
                float totalDailyIncome = userDailyRate + userDailyOvertimeRate;
                float totalWeeklyIncome = userWeeklyRate + userWeeklyOvertimeRate;
                float totalBiWeeklyIncome = userBiWeeklyRate + userBiWeeklyOvertimeRate;
                float totalMonthlyIncome = userMonthlyRate + userMonthlyOvertimeRate;
                float totalYearlyIncome = userYearlyRate + userYearlyOvertimeRate;

                printf("\nHere's the breakdown of your gross income (income before tax): \n");
                printf("\nYour estimated total daily income: %.2f CAD\n", totalDailyIncome);
                printf("Your estimated weekly income: %.2f CAD\n", totalWeeklyIncome);
                printf("Your estimated biweekly income: %.2f CAD\n", totalBiWeeklyIncome);
                printf("Your estimated monthly income: %.2f CAD\n", totalMonthlyIncome);
                printf("Your estimated yearly income: %.2f CAD\n", totalYearlyIncome);


            } else if (strcmp(userChoice, "Monthly") == 0) {
                // Standard rates
                printf("\nWhat is your monthly rate (CAD)? \n");
                scanf("%f", &userMonthlyRate);

                printf("\nHow many hours do you work in a day (standard, non-overtime)? \n");
                scanf("%f", &hours);

                printf("\nHow many days do you work in a week (standard, non-overtime)? \n");
                scanf("%f", &days);

                userBiWeeklyRate = userMonthlyRate / 2;
                userWeeklyRate = userBiWeeklyRate / 2;
                userDailyRate = userWeeklyRate / days;
                userHourlyRate = userDailyRate / hours;
                userYearlyRate = userMonthlyRate * 12;

                // Overtime rates
                printf("\nHow many hours do you usually work overtime in a day? \n");
                scanf("%f", &overtimeHours);

                userHourlyOvertimeRate = 1.5 * userHourlyRate;
                userDailyOvertimeRate = userHourlyOvertimeRate * overtimeHours;
                userWeeklyOvertimeRate = userDailyOvertimeRate * days;
                userBiWeeklyOvertimeRate = userWeeklyOvertimeRate * 2;
                userMonthlyOvertimeRate = userBiWeeklyOvertimeRate * 2;
                userYearlyOvertimeRate = userMonthlyOvertimeRate * 12;

                // Total Gross Income 
                float totalDailyIncome = userDailyRate + userDailyOvertimeRate;
                float totalWeeklyIncome = userWeeklyRate + userWeeklyOvertimeRate;
                float totalBiWeeklyIncome = userBiWeeklyRate + userBiWeeklyOvertimeRate;
                float totalMonthlyIncome = userMonthlyRate + userMonthlyOvertimeRate;
                float totalYearlyIncome = userYearlyRate + userYearlyOvertimeRate;

                printf("\nHere's the breakdown of your gross income (income before tax): \n");
                printf("\nYour estimated total daily income: %.2f CAD\n", totalDailyIncome);
                printf("Your estimated weekly income: %.2f CAD\n", totalWeeklyIncome);
                printf("Your estimated biweekly income: %.2f CAD\n", totalBiWeeklyIncome);
                printf("Your estimated monthly income: %.2f CAD\n", totalMonthlyIncome);
                printf("Your estimated yearly income: %.2f CAD\n", totalYearlyIncome);

                
            } else if (strcmp(userChoice, "Yearly") == 0) {
                // Standard rates
                printf("\nWhat is your yearly rate (CAD)? \n");
                scanf("%f", &userYearlyRate);

                printf("\nHow many hours do you work in a day (standard, non-overtime)? \n");
                scanf("%f", &hours);

                printf("\nHow many days do you work in a week (standard, non-overtime)? \n");
                scanf("%f", &days);

                userMonthlyRate = userYearlyRate / 12;
                userBiWeeklyRate = userMonthlyRate / 2;
                userWeeklyRate = userBiWeeklyRate / 2;
                userDailyRate = userWeeklyRate / days;
                userHourlyRate = userDailyRate / hours;

                // Overtime rates
                printf("\nHow many hours do you usually work overtime in a day? \n");
                scanf("%f", &overtimeHours);

                userHourlyOvertimeRate = 1.5 * userHourlyRate;
                userDailyOvertimeRate = userHourlyOvertimeRate * overtimeHours;
                userWeeklyOvertimeRate = userDailyOvertimeRate * days;
                userBiWeeklyOvertimeRate = userWeeklyOvertimeRate * 2;
                userMonthlyOvertimeRate = userBiWeeklyOvertimeRate * 2;
                userYearlyOvertimeRate = userMonthlyOvertimeRate * 12;

                // Total Gross Income 
                float totalDailyIncome = userDailyRate + userDailyOvertimeRate;
                float totalWeeklyIncome = userWeeklyRate + userWeeklyOvertimeRate;
                float totalBiWeeklyIncome = userBiWeeklyRate + userBiWeeklyOvertimeRate;
                float totalMonthlyIncome = userMonthlyRate + userMonthlyOvertimeRate;
                float totalYearlyIncome = userYearlyRate + userYearlyOvertimeRate;

                printf("\n\033[1;32mHere's the breakdown of your gross income (income before tax): \n");
                printf("\nYour estimated total daily income: %.2f CAD\n", totalDailyIncome);
                printf("Your estimated weekly income: %.2f CAD\n", totalWeeklyIncome);
                printf("Your estimated biweekly income: %.2f CAD\n", totalBiWeeklyIncome);
                printf("Your estimated monthly income: %.2f CAD\n", totalMonthlyIncome);
                printf("Your estimated yearly income: %.2f CAD\33[0m\n", totalYearlyIncome);

            }
        }

    } while (!validChoice);

    return 0;
}
