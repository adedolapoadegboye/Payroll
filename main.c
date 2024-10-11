#include <stdio.h>

#include <stdbool.h>

#include <string.h> // Required for strcmp()

void clear_data(float *hours, float *days, float *userHourlyRate, float *userDailyRate,
                float *userWeeklyRate, float *userBiWeeklyRate, float *userMonthlyRate, float *userYearlyRate,
                float *overtimeHours, float *userHourlyOvertimeRate, float *userDailyOvertimeRate,
                float *userWeeklyOvertimeRate, float *userBiWeeklyOvertimeRate, float *userMonthlyOvertimeRate,
                float *userYearlyOvertimeRate, float *totalDailyIncome, float *totalWeeklyIncome,
                float *totalBiWeeklyIncome, float *totalMonthlyIncome, float *totalYearlyIncome)
{
    // Reset all variables to zero
    *hours = 0.0;
    *days = 0.0;
    *userHourlyRate = 0.0;
    *userDailyRate = 0.0;
    *userWeeklyRate = 0.0;
    *userBiWeeklyRate = 0.0;
    *userMonthlyRate = 0.0;
    *userYearlyRate = 0.0;

    *overtimeHours = 0.0;
    *userHourlyOvertimeRate = 0.0;
    *userDailyOvertimeRate = 0.0;
    *userWeeklyOvertimeRate = 0.0;
    *userBiWeeklyOvertimeRate = 0.0;
    *userMonthlyOvertimeRate = 0.0;
    *userYearlyOvertimeRate = 0.0;

    *totalDailyIncome = 0.0;
    *totalWeeklyIncome = 0.0;
    *totalBiWeeklyIncome = 0.0;
    *totalMonthlyIncome = 0.0;
    *totalYearlyIncome = 0.0;
}

int main()
{
    // Payroll Calculator;
    char username[20];
    char choice;
    bool validChoice;
    const char *choiceList[] = {
        "Hourly",
        "Daily",
        "Weekly",
        "Bi-Weekly",
        "Monthly",
        "Yearly"};

    // Initialize all variables to zero
    float hours = 0.0, days = 0.0, userHourlyRate = 0.0, userDailyRate = 0.0, userWeeklyRate = 0.0;
    float userBiWeeklyRate = 0.0, userMonthlyRate = 0.0, userYearlyRate = 0.0;
    float overtimeHours = 0.0, userHourlyOvertimeRate = 0.0, userDailyOvertimeRate = 0.0;
    float userWeeklyOvertimeRate = 0.0, userBiWeeklyOvertimeRate = 0.0, userMonthlyOvertimeRate = 0.0;
    float userYearlyOvertimeRate = 0.0;

    // Overtime multiplier
    float overtimeMultiplier = 1.5;

    // Total income calculations
    float totalDailyIncome = 0.0, totalWeeklyIncome = 0.0, totalBiWeeklyIncome = 0.0;
    float totalMonthlyIncome = 0.0, totalYearlyIncome = 0.0;

    // Start interaction with the user
    printf("\nWelcome to the Payroll Calculator. Please enter your name to get started: \n");
    scanf("%s", username);

    printf("\nHello, %s. Welcome to the Payroll Calculator. \n", username);

    bool continueProgram = true; // Flag for loop control

    while (continueProgram)
    {
        do
        {
            printf("\nPlease choose one of the following income options: \n");
            printf("0. Hourly \n");
            printf("1. Daily \n");
            printf("2. Weekly \n");
            printf("3. Bi-Weekly \n");
            printf("4. Monthly \n");
            printf("5. Yearly \n");

            validChoice = scanf(" %c", &choice) == 1 && choice >= '0' && choice <= '5';

            if (!validChoice)
            {
                printf("\nInvalid choice. Please try again. \n");
                while (getchar() != '\n' && getchar() != EOF)
                    ; // Clear input buffer
            }

        } while (!validChoice);

        // Handle user income choice (Hourly, Daily, Weekly, etc.) here
        // Convert character choice to an integer index
        int index = choice - '0';
        const char *userChoice = choiceList[index];

        // Clear the input buffer after user input
        while (getchar() != '\n' && getchar() != EOF)
            ;

        // Use strcmp to compare the strings for different income types
        if (strcmp(userChoice, "Hourly") == 0)
        {
            // Standard rates for Hourly choice
            printf("\nWhat is your hourly rate (CAD)? \n");
            scanf("%f", &userHourlyRate);

            printf("\nHow many hours do you work in a day (standard, non-overtime)? \n");
            scanf("%f", &hours);

            printf("\nHow many days do you work in a week (standard, non-overtime)? \n");
            scanf("%f", &days);

            // Calculate daily, weekly, bi-weekly, monthly, and yearly income based on the user's hourly rate
            userDailyRate = hours * userHourlyRate;
            userWeeklyRate = userDailyRate * days;
            userBiWeeklyRate = userWeeklyRate * 2;
            userMonthlyRate = userBiWeeklyRate * 2;
            userYearlyRate = userMonthlyRate * 12;

            // Overtime rates
            printf("\nHow many hours do you usually work overtime in a day? \n");
            scanf("%f", &overtimeHours);

            userHourlyOvertimeRate = overtimeMultiplier * userHourlyRate; // Overtime is 1.5x regular rate
            userDailyOvertimeRate = userHourlyOvertimeRate * overtimeHours;
            userWeeklyOvertimeRate = userDailyOvertimeRate * days;
            userBiWeeklyOvertimeRate = userWeeklyOvertimeRate * (float)2;
            userMonthlyOvertimeRate = userBiWeeklyOvertimeRate * (float)2;
            userYearlyOvertimeRate = userMonthlyOvertimeRate * (float)12;

            // Total Gross Income (Standard + Overtime)
            totalDailyIncome = userDailyRate + userDailyOvertimeRate;
            totalWeeklyIncome = userWeeklyRate + userWeeklyOvertimeRate;
            totalBiWeeklyIncome = userBiWeeklyRate + userBiWeeklyOvertimeRate;
            totalMonthlyIncome = userMonthlyRate + userMonthlyOvertimeRate;
            totalYearlyIncome = userYearlyRate + userYearlyOvertimeRate;

            // Print the results for the user
            printf("\nHere's the breakdown of your gross income (income before tax): \n");
            printf("\nYour estimated total daily income: %.2f CAD\n", totalDailyIncome);
            printf("Your estimated weekly income: %.2f CAD\n", totalWeeklyIncome);
            printf("Your estimated biweekly income: %.2f CAD\n", totalBiWeeklyIncome);
            printf("Your estimated monthly income: %.2f CAD\n", totalMonthlyIncome);
            printf("Your estimated yearly income: %.2f CAD\n", totalYearlyIncome);
        }
        else if (strcmp(userChoice, "Daily") == 0)
        {
            // Standard rates for Daily choice
            printf("\nWhat is your daily rate (CAD)? \n");
            scanf("%f", &userDailyRate);

            printf("\nHow many hours do you work in a day (standard, non-overtime)? \n");
            scanf("%f", &hours);

            printf("\nHow many days do you work in a week (standard, non-overtime)? \n");
            scanf("%f", &days);

            // Calculate hourly, weekly, bi-weekly, monthly, and yearly income based on the user's daily rate
            userHourlyRate = userDailyRate / hours;
            userWeeklyRate = userDailyRate * days;
            userBiWeeklyRate = userWeeklyRate * 2;
            userMonthlyRate = userBiWeeklyRate * 2;
            userYearlyRate = userMonthlyRate * 12;

            // Overtime rates
            printf("\nHow many hours do you usually work overtime in a day? \n");
            scanf("%f", &overtimeHours);

            userHourlyOvertimeRate = overtimeMultiplier * userHourlyRate; // Overtime is 1.5x regular rate
            userDailyOvertimeRate = userHourlyOvertimeRate * overtimeHours;
            userWeeklyOvertimeRate = userDailyOvertimeRate * days;
            userBiWeeklyOvertimeRate = userWeeklyOvertimeRate * (float)2;
            userMonthlyOvertimeRate = userBiWeeklyOvertimeRate * (float)2;
            userYearlyOvertimeRate = userMonthlyOvertimeRate * (float)12;

            // Total Gross Income (Standard + Overtime)
            totalDailyIncome = userDailyRate + userDailyOvertimeRate;
            totalWeeklyIncome = userWeeklyRate + userWeeklyOvertimeRate;
            totalBiWeeklyIncome = userBiWeeklyRate + userBiWeeklyOvertimeRate;
            totalMonthlyIncome = userMonthlyRate + userMonthlyOvertimeRate;
            totalYearlyIncome = userYearlyRate + userYearlyOvertimeRate;

            // Print the results for the user
            printf("\nHere's the breakdown of your gross income (income before tax): \n");
            printf("\nYour estimated total daily income: %.2f CAD\n", totalDailyIncome);
            printf("Your estimated weekly income: %.2f CAD\n", totalWeeklyIncome);
            printf("Your estimated biweekly income: %.2f CAD\n", totalBiWeeklyIncome);
            printf("Your estimated monthly income: %.2f CAD\n", totalMonthlyIncome);
            printf("Your estimated yearly income: %.2f CAD\n", totalYearlyIncome);
        }
        else if (strcmp(userChoice, "Weekly") == 0)
        {
            // Standard rates for Weekly choice
            printf("\nWhat is your weekly rate (CAD)? \n");
            scanf("%f", &userWeeklyRate);

            printf("\nHow many hours do you work in a day (standard, non-overtime)? \n");
            scanf("%f", &hours);

            printf("\nHow many days do you work in a week (standard, non-overtime)? \n");
            scanf("%f", &days);

            // Calculate daily, hourly, bi-weekly, monthly, and yearly income based on the user's weekly rate
            userDailyRate = userWeeklyRate / days;
            userHourlyRate = userDailyRate / hours;
            userBiWeeklyRate = userWeeklyRate * 2;
            userMonthlyRate = userBiWeeklyRate * 2;
            userYearlyRate = userMonthlyRate * 12;

            // Overtime rates
            printf("\nHow many hours do you usually work overtime in a day? \n");
            scanf("%f", &overtimeHours);

            userHourlyOvertimeRate = overtimeMultiplier * userHourlyRate; // Overtime is 1.5x regular rate
            userDailyOvertimeRate = userHourlyOvertimeRate * overtimeHours;
            userWeeklyOvertimeRate = userDailyOvertimeRate * days;
            userBiWeeklyOvertimeRate = userWeeklyOvertimeRate * (float)2;
            userMonthlyOvertimeRate = userBiWeeklyOvertimeRate * (float)2;
            userYearlyOvertimeRate = userMonthlyOvertimeRate * (float)12;

            // Total Gross Income (Standard + Overtime)
            totalDailyIncome = userDailyRate + userDailyOvertimeRate;
            totalWeeklyIncome = userWeeklyRate + userWeeklyOvertimeRate;
            totalBiWeeklyIncome = userBiWeeklyRate + userBiWeeklyOvertimeRate;
            totalMonthlyIncome = userMonthlyRate + userMonthlyOvertimeRate;
            totalYearlyIncome = userYearlyRate + userYearlyOvertimeRate;

            // Print the results for the user
            printf("\nHere's the breakdown of your gross income (income before tax): \n");
            printf("\nYour estimated total daily income: %.2f CAD\n", totalDailyIncome);
            printf("Your estimated weekly income: %.2f CAD\n", totalWeeklyIncome);
            printf("Your estimated biweekly income: %.2f CAD\n", totalBiWeeklyIncome);
            printf("Your estimated monthly income: %.2f CAD\n", totalMonthlyIncome);
            printf("Your estimated yearly income: %.2f CAD\n", totalYearlyIncome);
        }
        else if (strcmp(userChoice, "Bi-Weekly") == 0)
        {
            // Standard rates for Bi-Weekly choice
            printf("\nWhat is your bi-weekly rate (CAD)? \n");
            scanf("%f", &userBiWeeklyRate);

            printf("\nHow many hours do you work in a day (standard, non-overtime)? \n");
            scanf("%f", &hours);

            printf("\nHow many days do you work in a week (standard, non-overtime)? \n");
            scanf("%f", &days);

            // Calculate weekly, daily, hourly, monthly, and yearly income based on the user's bi-weekly rate
            userWeeklyRate = userBiWeeklyRate / (float)2;
            userDailyRate = userWeeklyRate / days;
            userHourlyRate = userDailyRate / hours;
            userMonthlyRate = userBiWeeklyRate * (float)2;
            userYearlyRate = userMonthlyRate * (float)12;

            // Overtime rates
            printf("\nHow many hours do you usually work overtime in a day? \n");
            scanf("%f", &overtimeHours);

            userHourlyOvertimeRate = overtimeMultiplier * userHourlyRate; // Overtime is 1.5x regular rate
            userDailyOvertimeRate = userHourlyOvertimeRate * overtimeHours;
            userWeeklyOvertimeRate = userDailyOvertimeRate * days;
            userBiWeeklyOvertimeRate = userWeeklyOvertimeRate * (float)2;
            userMonthlyOvertimeRate = userBiWeeklyOvertimeRate * (float)2;
            userYearlyOvertimeRate = userMonthlyOvertimeRate * (float)12;

            // Total Gross Income (Standard + Overtime)
            totalDailyIncome = userDailyRate + userDailyOvertimeRate;
            totalWeeklyIncome = userWeeklyRate + userWeeklyOvertimeRate;
            totalBiWeeklyIncome = userBiWeeklyRate + userBiWeeklyOvertimeRate;
            totalMonthlyIncome = userMonthlyRate + userMonthlyOvertimeRate;
            totalYearlyIncome = userYearlyRate + userYearlyOvertimeRate;

            // Print the results for the user
            printf("\nHere's the breakdown of your gross income (income before tax): \n");
            printf("\nYour estimated total daily income: %.2f CAD\n", totalDailyIncome);
            printf("Your estimated weekly income: %.2f CAD\n", totalWeeklyIncome);
            printf("Your estimated biweekly income: %.2f CAD\n", totalBiWeeklyIncome);
            printf("Your estimated monthly income: %.2f CAD\n", totalMonthlyIncome);
            printf("Your estimated yearly income: %.2f CAD\n", totalYearlyIncome);
        }
        else if (strcmp(userChoice, "Monthly") == 0)
        {
            // Standard rates for Monthly choice
            printf("\nWhat is your monthly rate (CAD)? \n");
            scanf("%f", &userMonthlyRate);

            printf("\nHow many hours do you work in a day (standard, non-overtime)? \n");
            scanf("%f", &hours);

            printf("\nHow many days do you work in a week (standard, non-overtime)? \n");
            scanf("%f", &days);

            // Calculate bi-weekly, weekly, daily, hourly, and yearly income based on the user's monthly rate
            userBiWeeklyRate = userMonthlyRate / (float)2;
            userWeeklyRate = userBiWeeklyRate / (float)2;
            userDailyRate = userWeeklyRate / days;
            userHourlyRate = userDailyRate / hours;
            userYearlyRate = userMonthlyRate * (float)12;

            // Overtime rates
            printf("\nHow many hours do you usually work overtime in a day? \n");
            scanf("%f", &overtimeHours);

            userHourlyOvertimeRate = overtimeMultiplier * userHourlyRate; // Overtime is 1.5x regular rate
            userDailyOvertimeRate = userHourlyOvertimeRate * overtimeHours;
            userWeeklyOvertimeRate = userDailyOvertimeRate * days;
            userBiWeeklyOvertimeRate = userWeeklyOvertimeRate * (float)2;
            userMonthlyOvertimeRate = userBiWeeklyOvertimeRate * (float)2;
            userYearlyOvertimeRate = userMonthlyOvertimeRate * (float)12;

            // Total Gross Income (Standard + Overtime)
            totalDailyIncome = userDailyRate + userDailyOvertimeRate;
            totalWeeklyIncome = userWeeklyRate + userWeeklyOvertimeRate;
            totalBiWeeklyIncome = userBiWeeklyRate + userBiWeeklyOvertimeRate;
            totalMonthlyIncome = userMonthlyRate + userMonthlyOvertimeRate;
            totalYearlyIncome = userYearlyRate + userYearlyOvertimeRate;

            // Print the results for the user
            printf("\nHere's the breakdown of your gross income (income before tax): \n");
            printf("\nYour estimated total daily income: %.2f CAD\n", totalDailyIncome);
            printf("Your estimated weekly income: %.2f CAD\n", totalWeeklyIncome);
            printf("Your estimated biweekly income: %.2f CAD\n", totalBiWeeklyIncome);
            printf("Your estimated monthly income: %.2f CAD\n", totalMonthlyIncome);
            printf("Your estimated yearly income: %.2f CAD\n", totalYearlyIncome);
        }
        else if (strcmp(userChoice, "Yearly") == 0)
        {
            // Standard rates for Yearly choice
            printf("\nWhat is your yearly rate (CAD)? \n");
            scanf("%f", &userYearlyRate);

            printf("\nHow many hours do you work in a day (standard, non-overtime)? \n");
            scanf("%f", &hours);

            printf("\nHow many days do you work in a week (standard, non-overtime)? \n");
            scanf("%f", &days);

            // Calculate monthly, bi-weekly, weekly, daily, and hourly income based on the user's yearly rate
            userMonthlyRate = userYearlyRate / (float)12;
            userBiWeeklyRate = userMonthlyRate / (float)2;
            userWeeklyRate = userBiWeeklyRate / (float)2;
            userDailyRate = userWeeklyRate / days;
            userHourlyRate = userDailyRate / hours;

            // Overtime rates
            printf("\nHow many hours do you usually work overtime in a day? \n");
            scanf("%f", &overtimeHours);

            userHourlyOvertimeRate = overtimeMultiplier * userHourlyRate; // Overtime is 1.5x regular rate
            userDailyOvertimeRate = userHourlyOvertimeRate * overtimeHours;
            userWeeklyOvertimeRate = userDailyOvertimeRate * days;
            userBiWeeklyOvertimeRate = userWeeklyOvertimeRate * (float)2;
            userMonthlyOvertimeRate = userBiWeeklyOvertimeRate * (float)2;
            userYearlyOvertimeRate = userMonthlyOvertimeRate * (float)12;

            // Total Gross Income (Standard + Overtime)
            totalDailyIncome = userDailyRate + userDailyOvertimeRate;
            totalWeeklyIncome = userWeeklyRate + userWeeklyOvertimeRate;
            totalBiWeeklyIncome = userBiWeeklyRate + userBiWeeklyOvertimeRate;
            totalMonthlyIncome = userMonthlyRate + userMonthlyOvertimeRate;
            totalYearlyIncome = userYearlyRate + userYearlyOvertimeRate;

            // Print the results for the user
            printf("\nHere's the breakdown of your gross income (income before tax): \n");
            printf("\nYour estimated total daily income: %.2f CAD\n", totalDailyIncome);
            printf("Your estimated weekly income: %.2f CAD\n", totalWeeklyIncome);
            printf("Your estimated biweekly income: %.2f CAD\n", totalBiWeeklyIncome);
            printf("Your estimated monthly income: %.2f CAD\n", totalMonthlyIncome);
            printf("Your estimated yearly income: %.2f CAD\n", totalYearlyIncome);
        }

        // Ask the user if they want to calculate their income tax
        char taxChoiceChar;
        printf("\nWould you like to calculate your income tax? (y/n): ");
        scanf(" %c", &taxChoiceChar);

        if (taxChoiceChar == 'y' || taxChoiceChar == 'Y')
        {
            // Variables for tax calculations
            float federalTax = 0.0, provincialTax = 0.0, totalTax = 0.0;
            const char *provinceList[] = {
                "Alberta",
                "British Columbia",
                "Nova Scotia",
                "Nunavut",
                "Prince Edward Island",
                "Quebec",
                "Yukon",
                "Northwest Territories",
                "Saskatchewan",
                "New Brunswick",
                "Newfoundland and Labrador"};
            int userProvince;

            // Ask the user to select their province
            printf("\nWhich province do you live in? \n");
            for (int i = 0; i < 11; i++)
            {
                printf("%d. %s \n", i, provinceList[i]);
            }
            printf("Enter your choice: ");
            scanf("%d", &userProvince);

            // Federal tax calculation based on yearly income
            if (totalYearlyIncome <= (float)55867)
            {
                federalTax = totalYearlyIncome * (float)0.15;
            }
            else if (totalYearlyIncome <= (float)111733)
            {
                federalTax = totalYearlyIncome * (float)0.205;
            }
            else if (totalYearlyIncome <= (float)173205)
            {
                federalTax = totalYearlyIncome * (float)0.26;
            }
            else if (totalYearlyIncome <= (float)246752)
            {
                federalTax = totalYearlyIncome * (float)0.29;
            }
            else
            {
                federalTax = totalYearlyIncome * (float)0.33;
            }

            // Example for Alberta provincial tax (can be expanded for other provinces)
            if (userProvince == 0)
            { // Alberta
                if (totalYearlyIncome <= (float)142292)
                {
                    provincialTax = totalYearlyIncome * (float)0.10;
                }
                else if (totalYearlyIncome <= (float)170751)
                {
                    provincialTax = totalYearlyIncome * (float)0.12;
                }
                else if (totalYearlyIncome <= (float)227668)
                {
                    provincialTax = totalYearlyIncome * (float)0.13;
                }
                else if (totalYearlyIncome <= (float)341502)
                {
                    provincialTax = totalYearlyIncome * (float)0.14;
                }
                else
                {
                    provincialTax = totalYearlyIncome * (float)0.15;
                }
            } // Provincial tax calculations for all provinces
            if (userProvince == 0)
            { // Alberta
                if (totalYearlyIncome <= (float)142292)
                {
                    provincialTax = totalYearlyIncome * (float)0.10;
                }
                else if (totalYearlyIncome <= (float)170751)
                {
                    provincialTax = totalYearlyIncome * (float)0.12;
                }
                else if (totalYearlyIncome <= (float)227668)
                {
                    provincialTax = totalYearlyIncome * (float)0.13;
                }
                else if (totalYearlyIncome <= (float)341502)
                {
                    provincialTax = totalYearlyIncome * (float)0.14;
                }
                else
                {
                    provincialTax = totalYearlyIncome * (float)0.15;
                }
            }
            // Provincial tax calculations for all provinces
            if (userProvince == 0)
            { // Alberta
                if (totalYearlyIncome <= (float)142292)
                {
                    provincialTax = totalYearlyIncome * (float)0.10;
                }
                else if (totalYearlyIncome <= (float)170751)
                {
                    provincialTax = totalYearlyIncome * (float)0.12;
                }
                else if (totalYearlyIncome <= (float)227668)
                {
                    provincialTax = totalYearlyIncome * (float)0.13;
                }
                else if (totalYearlyIncome <= (float)341502)
                {
                    provincialTax = totalYearlyIncome * (float)0.14;
                }
                else
                {
                    provincialTax = totalYearlyIncome * (float)0.15;
                }
            }
            else if (userProvince == 1)
            { // British Columbia
                if (totalYearlyIncome <= (float)47937)
                {
                    provincialTax = totalYearlyIncome * (float)0.0506;
                }
                else if (totalYearlyIncome <= (float)95875)
                {
                    provincialTax = ((float)47937 * (float)0.0506) + ((totalYearlyIncome - (float)47937) * (float)0.077);
                }
                else if (totalYearlyIncome <= (float)110075)
                {
                    provincialTax = ((float)47937 * (float)0.0506) + (((float)95875 - (float)47937) * (float)0.077) + ((totalYearlyIncome - (float)95875) * (float)0.105);
                }
                else if (totalYearlyIncome <= (float)133752)
                {
                    provincialTax = ((float)47937 * (float)0.0506) + (((float)95875 - (float)47937) * (float)0.077) + (((float)110075 - (float)95875) * (float)0.105) + ((totalYearlyIncome - (float)110075) * (float)0.1229);
                }
                else
                {
                    provincialTax = ((float)47937 * (float)0.0506) + (((float)95875 - (float)47937) * (float)0.077) + (((float)110075 - (float)95875) * (float)0.105) + (((float)133752 - (float)110075) * (float)0.1229) + ((totalYearlyIncome - (float)133752) * (float)0.147);
                }
            }
            else if (userProvince == 2)
            { // Nova Scotia
                if (totalYearlyIncome <= (float)29590)
                {
                    provincialTax = totalYearlyIncome * (float)0.0879;
                }
                else if (totalYearlyIncome <= (float)59180)
                {
                    provincialTax = ((float)29590 * (float)0.0879) + ((totalYearlyIncome - (float)29590) * (float)0.1495);
                }
                else if (totalYearlyIncome <= (float)93000)
                {
                    provincialTax = ((float)29590 * (float)0.0879) + (((float)59180 - 29590) * (float)0.1495) + ((totalYearlyIncome - 59180) * (float)0.1667);
                }
                else if (totalYearlyIncome <= 150000)
                {
                    provincialTax = (29590 * (float)0.0879) + ((59180 - 29590) * (float)0.1495) + ((93000 - (float)59180) * (float)0.1667) + ((totalYearlyIncome - 93000) * (float)0.175);
                }
                else
                {
                    provincialTax = (29590 * (float)0.0879) + ((59180 - 29590) * (float)0.1495) + (((float)93000 - (float)59180) * (float)0.1667) + (((float)150000 - (float)93000) * (float)0.175) + ((totalYearlyIncome - 150000) * (float)0.21);
                }
            }
            else if (userProvince == 3)
            { // Nunavut
                if (totalYearlyIncome <= (float)53268)
                {
                    provincialTax = totalYearlyIncome * (float)0.04;
                }
                else if (totalYearlyIncome <= (float)106537)
                {
                    provincialTax = ((float)53268 * (float)0.04) + ((totalYearlyIncome - (float)53268) * (float)0.07);
                }
                else if (totalYearlyIncome <= 173205)
                {
                    provincialTax = (53268 * (float)0.04) + ((106537 - 53268) * (float)0.07) + ((totalYearlyIncome - 106537) * (float)0.09);
                }
                else
                {
                    provincialTax = (53268 * (float)0.04) + ((106537 - 53268) * (float)0.07) + ((173205 - 106537) * (float)0.09) + ((totalYearlyIncome - 173205) * (float)0.115);
                }
            }
            else if (userProvince == 4)
            { // Prince Edward Island
                if (totalYearlyIncome <= 32656)
                {
                    provincialTax = totalYearlyIncome * (float)0.098;
                }
                else if (totalYearlyIncome <= 64313)
                {
                    provincialTax = (32656 * (float)0.098) + ((totalYearlyIncome - 32656) * (float)0.138);
                }
                else
                {
                    provincialTax = (32656 * (float)0.098) + ((64313 - 32656) * (float)0.138) + ((totalYearlyIncome - 64313) * (float)0.167);
                }
            }
            else if (userProvince == 5)
            { // Quebec
                if (totalYearlyIncome <= 51780)
                {
                    provincialTax = totalYearlyIncome * (float)0.14;
                }
                else if (totalYearlyIncome <= 103545)
                {
                    provincialTax = (51780 * (float)0.14) + ((totalYearlyIncome - 51780) * (float)0.19);
                }
                else if (totalYearlyIncome <= 126000)
                {
                    provincialTax = (51780 * (float)0.14) + ((103545 - 51780) * (float)0.19) + ((totalYearlyIncome - 103545) * (float)0.24);
                }
                else
                {
                    provincialTax = (51780 * (float)0.14) + ((103545 - 51780) * (float)0.19) + ((126000 - 103545) * (float)0.24) + ((totalYearlyIncome - (float)126000) * (float)0.2575);
                }
            }
            else if (userProvince == 6)
            { // Yukon
                if (totalYearlyIncome <= 55867)
                {
                    provincialTax = totalYearlyIncome * (float)0.064;
                }
                else if (totalYearlyIncome <= 111733)
                {
                    provincialTax = (55867 * (float)0.064) + ((totalYearlyIncome - 55867) * (float)0.09);
                }
                else if (totalYearlyIncome <= 173205)
                {
                    provincialTax = (55867 * (float)0.064) + ((111733 - 55867) * (float)0.09) + ((totalYearlyIncome - 111733) * (float)0.109);
                }
                else if (totalYearlyIncome <= 500000)
                {
                    provincialTax = (55867 * (float)0.064) + ((111733 - 55867) * (float)0.09) + ((173205 - 111733) * (float)0.109) + ((totalYearlyIncome - 173205) * (float)0.128);
                }
                else
                {
                    provincialTax = (55867 * (float)0.064) + ((111733 - 55867) * (float)0.09) + ((173205 - 111733) * (float)0.109) + ((500000 - 173205) * (float)0.128) + ((totalYearlyIncome - 500000) * (float)0.15);
                }
            }
            else if (userProvince == 7)
            { // Northwest Territories
                if (totalYearlyIncome <= 50597)
                {
                    provincialTax = totalYearlyIncome * (float)0.059;
                }
                else if (totalYearlyIncome <= 101198)
                {
                    provincialTax = (50597 * (float)0.059) + ((totalYearlyIncome - 50597) * (float)0.086);
                }
                else if (totalYearlyIncome <= 164525)
                {
                    provincialTax = (50597 * (float)0.059) + ((101198 - 50597) * (float)0.086) + ((totalYearlyIncome - 101198) * (float)0.122);
                }
                else
                {
                    provincialTax = (50597 * (float)0.059) + ((101198 - 50597) * (float)0.086) + ((164525 - 101198) * (float)0.122) + ((totalYearlyIncome - 164525) * (float)0.1405);
                }
            }
            else if (userProvince == 8)
            { // Saskatchewan
                if (totalYearlyIncome <= 47630)
                {
                    provincialTax = totalYearlyIncome * (float)0.105;
                }
                else if (totalYearlyIncome <= 136605)
                {
                    provincialTax = (47630 * (float)0.105) + ((totalYearlyIncome - 47630) * (float)0.125);
                }
                else
                {
                    provincialTax = (47630 * (float)0.105) + ((136605 - 47630) * (float)0.125) + ((totalYearlyIncome - 136605) * (float)0.145);
                }
            }
            else if (userProvince == 9)
            { // New Brunswick
                if (totalYearlyIncome <= 47954)
                {
                    provincialTax = totalYearlyIncome * (float)0.094;
                }
                else if (totalYearlyIncome <= 95909)
                {
                    provincialTax = (47954 * (float)0.094) + ((totalYearlyIncome - 47954) * (float)0.1482);
                }
                else if (totalYearlyIncome <= 159442)
                {
                    provincialTax = (47954 * (float)0.094) + ((95909 - 47954) * (float)0.1482) + ((totalYearlyIncome - 95909) * (float)0.1652);
                }
                else if (totalYearlyIncome <= 214368)
                {
                    provincialTax = (47954 * (float)0.094) + ((95909 - 47954) * (float)0.1482) + ((159442 - 95909) * (float)0.1652) + ((totalYearlyIncome - 159442) * (float)0.1784);
                }
                else
                {
                    provincialTax = (47954 * (float)0.094) + ((95909 - 47954) * (float)0.1482) + ((159442 - 95909) * (float)0.1652) + ((214368 - 159442) * (float)0.1784) + ((totalYearlyIncome - 214368) * (float)0.203);
                }
            }
            else if (userProvince == 10)
            { // Newfoundland and Labrador
                if (totalYearlyIncome <= 41357)
                {
                    provincialTax = totalYearlyIncome * (float)0.087;
                }
                else if (totalYearlyIncome <= 82714)
                {
                    provincialTax = (41357 * (float)0.087) + ((totalYearlyIncome - 41357) * (float)0.145);
                }
                else if (totalYearlyIncome <= 148087)
                {
                    provincialTax = (41357 * (float)0.087) + ((82714 - 41357) * (float)0.145) + ((totalYearlyIncome - 82714) * (float)0.158);
                }
                else if (totalYearlyIncome <= 184590)
                {
                    provincialTax = (41357 * (float)0.087) + ((82714 - 41357) * (float)0.145) + (((float)148087 - (float)82714) * (float)0.158) + ((totalYearlyIncome - 148087) * (float)0.173);
                }
                else if (totalYearlyIncome <= 327784)
                {
                    provincialTax = (41357 * (float)0.087) + ((82714 - 41357) * (float)0.145) + ((148087 - 82714) * (float)0.158) + ((184590 - 148087) * (float)0.173) + ((totalYearlyIncome - 184590) * (float)0.183);
                }
                else
                {
                    provincialTax = (41357 * (float)0.087) + ((82714 - 41357) * (float)0.145) + ((148087 - 82714) * (float)0.158) + ((184590 - 148087) * (float)0.173) + ((327784 - 184590) * (float)0.183) + ((totalYearlyIncome - 327784) * (float)0.1835);
                }
            }

            // Calculate total tax (federal + provincial)
            totalTax = federalTax + provincialTax;

            // Display tax breakdown
            printf("\nHere's the breakdown of your income tax: \n");
            printf("Federal tax: %.2f CAD\n", federalTax);
            printf("Provincial tax for %s: %.2f CAD\n", provinceList[userProvince], provincialTax);
            printf("Total tax: %.2f CAD\n", totalTax);

            // Display net income (after tax)
            printf("\nHere's the breakdown of your net income (income after tax): \n");
            printf("Net daily income: %.2f CAD\n", (totalYearlyIncome - totalTax) / 260);
            printf("Net weekly income: %.2f CAD\n", (totalYearlyIncome - totalTax) / 52);
            printf("Net biweekly income: %.2f CAD\n", (totalYearlyIncome - totalTax) / 26);
            printf("Net monthly income: %.2f CAD\n", (totalYearlyIncome - totalTax) / 12);
            printf("Net yearly income: %.2f CAD\n", totalYearlyIncome - totalTax);
        }

        // Ask user if they want to continue
        char continueChoice;
        printf("\nDo you want to continue using the program? (y/n): ");
        scanf(" %c", &continueChoice);

        if (continueChoice == 'y' || continueChoice == 'Y')
        {
            // Clear all the data and restart from income choice
            clear_data(&hours, &days, &userHourlyRate, &userDailyRate, &userWeeklyRate, &userBiWeeklyRate, &userMonthlyRate, &userYearlyRate, &overtimeHours, &userHourlyOvertimeRate, &userDailyOvertimeRate, &userWeeklyOvertimeRate, &userBiWeeklyOvertimeRate, &userMonthlyOvertimeRate, &userYearlyOvertimeRate, &totalDailyIncome, &totalWeeklyIncome, &totalBiWeeklyIncome, &totalMonthlyIncome, &totalYearlyIncome);
            printf("\nData cleared. Starting over...\n");
        }
        else
        {
            // Exit the program
            printf("\nExiting the program. Goodbye!\n");
            continueProgram = false;
        }
    }

    return 0;
}
