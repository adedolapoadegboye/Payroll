#include <stdio.h>
#include <stdbool.h>
#include <string.h> // Required for strcmp()

int main()
{
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

    float overtimeMultiplier = 1.5;

    float totalDailyIncome;
    float totalWeeklyIncome;
    float totalBiWeeklyIncome;
    float totalMonthlyIncome;
    float totalYearlyIncome;

    printf("\nWelcome to the Payroll Calculator. Please enter your name to get started: \n");
    scanf("%s", username);

    printf("\nHello, %s. Welcome to the Payroll Calculator. \n", username);

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
            // Clear the input buffer
            while (getchar() != '\n' && getchar() != EOF)
                ;
        }
        else
        {
            // Convert character choice to an integer index
            int index = choice - '0';
            const char *userChoice = choiceList[index];

            // Clear the input buffer after user input
            while (getchar() != '\n' && getchar() != EOF)
                ;

            // Use strcmp to compare the strings
            if (strcmp(userChoice, "Hourly") == 0)
            {
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

                userHourlyOvertimeRate = overtimeMultiplier * userHourlyRate;
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
            }
            else if (strcmp(userChoice, "Daily") == 0)
            {
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

                userHourlyOvertimeRate = overtimeMultiplier * userHourlyRate;
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
            }
            else if (strcmp(userChoice, "Weekly") == 0)
            {
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

                userHourlyOvertimeRate = overtimeMultiplier * userHourlyRate;
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
            }
            else if (strcmp(userChoice, "Bi-Weekly") == 0)
            {
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

                userHourlyOvertimeRate = overtimeMultiplier * userHourlyRate;
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
            }
            else if (strcmp(userChoice, "Monthly") == 0)
            {
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

                userHourlyOvertimeRate = overtimeMultiplier * userHourlyRate;
                userDailyOvertimeRate = userHourlyOvertimeRate * overtimeHours;
                userWeeklyOvertimeRate = userDailyOvertimeRate * days;
                userBiWeeklyOvertimeRate = userWeeklyOvertimeRate * 2;
                userMonthlyOvertimeRate = userBiWeeklyOvertimeRate * 2;
                userYearlyOvertimeRate = userMonthlyOvertimeRate * 12;

                // Total Gross Income
                totalDailyIncome = userDailyRate + userDailyOvertimeRate;
                totalWeeklyIncome = userWeeklyRate + userWeeklyOvertimeRate;
                totalBiWeeklyIncome = userBiWeeklyRate + userBiWeeklyOvertimeRate;
                totalMonthlyIncome = userMonthlyRate + userMonthlyOvertimeRate;
                totalYearlyIncome = userYearlyRate + userYearlyOvertimeRate;

                printf("\nHere's the breakdown of your gross income (income before tax): \n");
                printf("\nYour estimated total daily income: %.2f CAD\n", totalDailyIncome);
                printf("Your estimated weekly income: %.2f CAD\n", totalWeeklyIncome);
                printf("Your estimated biweekly income: %.2f CAD\n", totalBiWeeklyIncome);
                printf("Your estimated monthly income: %.2f CAD\n", totalMonthlyIncome);
                printf("Your estimated yearly income: %.2f CAD\n", totalYearlyIncome);
            }
            else if (strcmp(userChoice, "Yearly") == 0)
            {
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

                userHourlyOvertimeRate = overtimeMultiplier * userHourlyRate;
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
                printf("Your estimated yearly income: %.2f CAD\033[0m\n", totalYearlyIncome);
            }

            char taxChoiceChar;
            printf("\nWould you like to calculate your income tax? (y/n) \n");
            validChoice = scanf("%c", taxChoiceChar) == 1 && (taxChoiceChar == 'y' || taxChoiceChar == 'Y');

            // Calculate taxes
            float federalTax;
            float provincialTax;
            float totalTax = federalTax + provincialTax;
            const char *provinceList[] = {"Alberta", "British Columbia", "Nova Scotia", "Nunavut", "Prince Edward Island", "Quebec", "Yukon", "Northwest Territories", "Saskatchewan", "New Brunswick", "Newfoundland and Labrador"};
            char userProvince;

            if (validChoice)
            {
                printf("\n Which province do you live in? \n");
                printf("0. Alberta \n");
                printf("1. British Columbia \n");
                printf("2. Nova Scotia \n");
                printf("3. Nunavut \n");
                printf("4. Prince Edward Island \n");
                printf("5. Quebec \n");
                printf("6. Yukon \n");
                printf("7. Northwest Territories \n");
                printf("8. Saskatchewan \n");
                printf("9. New Brunswick \n");
                printf("10. Newfoundland and Labrador \n");
                printf("Enter your choice: \n");
                scanf("%c", &userProvince);
            }

            // Federal Tax
            if (totalYearlyIncome > 0 && totalYearlyIncome <= 55867)
            {
                federalTax = totalYearlyIncome * 0.15;
            }
            else if (totalYearlyIncome > 55867 && totalYearlyIncome <= 111733)
            {
                federalTax = totalYearlyIncome * 0.205;
            }
            else if (totalYearlyIncome > 111733 && totalYearlyIncome <= 173205)
            {
                federalTax = totalYearlyIncome * 0.26;
            }
            else if (totalYearlyIncome > 173205 && totalYearlyIncome <= 246752)
            {
                federalTax = totalYearlyIncome * 0.29;
            }
            else if (totalYearlyIncome > 246752)
            {
                federalTax = totalYearlyIncome * 0.33;
            }

            // Provincial Tax
            if (userProvince == '0')
            {
                printf("\nProvince: %s \n", provinceList[userProvince - '0']);

                if (totalYearlyIncome > 0 && totalYearlyIncome <= 142292)
                {
                    federalTax = totalYearlyIncome * 0.1;
                }
                else if (totalYearlyIncome > 142292 && totalYearlyIncome <= 170751)
                {
                    federalTax = totalYearlyIncome * 0.12;
                }
                else if (totalYearlyIncome > 170751 && totalYearlyIncome <= 227668)
                {
                    federalTax = totalYearlyIncome * 0.13;
                }
                else if (totalYearlyIncome > 227668 && totalYearlyIncome <= 341502)
                {
                    federalTax = totalYearlyIncome * 0.14;
                }
                else if (totalYearlyIncome > 341502)
                {
                    federalTax = totalYearlyIncome * 0.15;
                }
            }
            else if (userProvince == '1')
            {
                printf("\nProvince: %s \n", provinceList[userProvince - '0']);
                if (totalYearlyIncome <= 47937)
                    provincialTax = totalYearlyIncome * 0.0506;
                else if (totalYearlyIncome <= 95875)
                    provincialTax = (47937 * 0.0506) + ((totalYearlyIncome - 47937) * 0.077);
                else if (totalYearlyIncome <= 110075)
                    provincialTax = (47937 * 0.0506) + ((95875 - 47937) * 0.077) + ((totalYearlyIncome - 95875) * 0.105);
                else if (totalYearlyIncome <= 133663)
                    provincialTax = (47937 * 0.0506) + ((95875 - 47937) * 0.077) + ((110075 - 95875) * 0.105) + ((totalYearlyIncome - 110075) * 0.1229);
                else if (totalYearlyIncome <= 181231)
                    provincialTax = (47937 * 0.0506) + ((95875 - 47937) * 0.077) + ((110075 - 95875) * 0.105) + ((133663 - 110075) * 0.1229) + ((totalYearlyIncome - 133663) * 0.147);
                else
                    provincialTax = (47937 * 0.0506) + ((95875 - 47937) * 0.077) + ((110075 - 95875) * 0.105) + ((133663 - 110075) * 0.1229) + ((181231 - 133663) * 0.147) + ((totalYearlyIncome - 181231) * 0.168);
            }
            else if (userProvince == '2')
            {
                printf("\nProvince: %s \n", provinceList[userProvince - '0']);
                if (totalYearlyIncome <= 29590)
                    provincialTax = totalYearlyIncome * 0.0879;
                else if (totalYearlyIncome <= 59180)
                    provincialTax = (29590 * 0.0879) + ((totalYearlyIncome - 29590) * 0.1495);
                else if (totalYearlyIncome <= 93000)
                    provincialTax = (29590 * 0.0879) + ((59180 - 29590) * 0.1495) + ((totalYearlyIncome - 59180) * 0.1667);
                else if (totalYearlyIncome <= 150000)
                    provincialTax = (29590 * 0.0879) + ((59180 - 29590) * 0.1495) + ((93000 - 59180) * 0.1667) + ((totalYearlyIncome - 93000) * 0.175);
                else
                    provincialTax = (29590 * 0.0879) + ((59180 - 29590) * 0.1495) + ((93000 - 59180) * 0.1667) + ((150000 - 93000) * 0.175) + ((totalYearlyIncome - 150000) * 0.21);
            }
            else if (userProvince == '3')
            {
                printf("\nProvince: %s \n", provinceList[userProvince - '0']);
            }
            else if (userProvince == '3')
            { // Nunavut
                printf("\nProvince: %s \n", provinceList[userProvince - '0']);
                if (totalYearlyIncome <= 53268)
                    provincialTax = totalYearlyIncome * 0.04;
                else if (totalYearlyIncome <= 106537)
                    provincialTax = (53268 * 0.04) + ((totalYearlyIncome - 53268) * 0.07);
                else if (totalYearlyIncome <= 173205)
                    provincialTax = (53268 * 0.04) + ((106537 - 53268) * 0.07) + ((totalYearlyIncome - 106537) * 0.09);
                else
                    provincialTax = (53268 * 0.04) + ((106537 - 53268) * 0.07) + ((173205 - 106537) * 0.09) + ((totalYearlyIncome - 173205) * 0.115);
            }
            else if (userProvince == '4')
            { // Prince Edward Island
                printf("\nProvince: %s \n", provinceList[userProvince - '0']);
                if (totalYearlyIncome <= 32656)
                    provincialTax = totalYearlyIncome * 0.098;
                else if (totalYearlyIncome <= 64313)
                    provincialTax = (32656 * 0.098) + ((totalYearlyIncome - 32656) * 0.138);
                else
                    provincialTax = (32656 * 0.098) + ((64313 - 32656) * 0.138) + ((totalYearlyIncome - 64313) * 0.167);
            }
            else if (userProvince == '5')
            { // Quebec
                printf("\nProvince: %s \n", provinceList[userProvince - '0']);
                if (totalYearlyIncome <= 51780)
                    provincialTax = totalYearlyIncome * 0.14;
                else if (totalYearlyIncome <= 103545)
                    provincialTax = (51780 * 0.14) + ((totalYearlyIncome - 51780) * 0.19);
                else if (totalYearlyIncome <= 126000)
                    provincialTax = (51780 * 0.14) + ((103545 - 51780) * 0.19) + ((totalYearlyIncome - 103545) * 0.24);
                else
                    provincialTax = (51780 * 0.14) + ((103545 - 51780) * 0.19) + ((126000 - 103545) * 0.24) + ((totalYearlyIncome - 126000) * 0.2575);
            }
            else if (userProvince == '6')
            { // Yukon
                printf("\nProvince: %s \n", provinceList[userProvince - '0']);
                if (totalYearlyIncome <= 55867)
                    provincialTax = totalYearlyIncome * 0.064;
                else if (totalYearlyIncome <= 111733)
                    provincialTax = (55867 * 0.064) + ((totalYearlyIncome - 55867) * 0.09);
                else if (totalYearlyIncome <= 173205)
                    provincialTax = (55867 * 0.064) + ((111733 - 55867) * 0.09) + ((totalYearlyIncome - 111733) * 0.109);
                else if (totalYearlyIncome <= 500000)
                    provincialTax = (55867 * 0.064) + ((111733 - 55867) * 0.09) + ((173205 - 111733) * 0.109) + ((totalYearlyIncome - 173205) * 0.128);
                else
                    provincialTax = (55867 * 0.064) + ((111733 - 55867) * 0.09) + ((173205 - 111733) * 0.109) + ((500000 - 173205) * 0.128) + ((totalYearlyIncome - 500000) * 0.15);
            }
            else if (userProvince == '7')
            { // Northwest Territories
                printf("\nProvince: %s \n", provinceList[userProvince - '0']);
                if (totalYearlyIncome <= 50597)
                    provincialTax = totalYearlyIncome * 0.059;
                else if (totalYearlyIncome <= 101198)
                    provincialTax = (50597 * 0.059) + ((totalYearlyIncome - 50597) * 0.086);
                else if (totalYearlyIncome <= 164525)
                    provincialTax = (50597 * 0.059) + ((101198 - 50597) * 0.086) + ((totalYearlyIncome - 101198) * 0.122);
                else
                    provincialTax = (50597 * 0.059) + ((101198 - 50597) * 0.086) + ((164525 - 101198) * 0.122) + ((totalYearlyIncome - 164525) * 0.1405);
            }
            else if (userProvince == '8')
            { // Saskatchewan
                printf("\nProvince: %s \n", provinceList[userProvince - '0']);
                if (totalYearlyIncome <= 52057)
                    provincialTax = totalYearlyIncome * 0.105;
                else if (totalYearlyIncome <= 148734)
                    provincialTax = (52057 * 0.105) + ((totalYearlyIncome - 52057) * 0.125);
                else
                    provincialTax = (52057 * 0.105) + ((148734 - 52057) * 0.125) + ((totalYearlyIncome - 148734) * 0.145);
            }
            else if (userProvince == '9')
            { // New Brunswick
                printf("\nProvince: %s \n", provinceList[userProvince - '0']);
                if (totalYearlyIncome <= 49958)
                    provincialTax = totalYearlyIncome * 0.094;
                else if (totalYearlyIncome <= 99916)
                    provincialTax = (49958 * 0.094) + ((totalYearlyIncome - 49958) * 0.14);
                else if (totalYearlyIncome <= 185064)
                    provincialTax = (49958 * 0.094) + ((99916 - 49958) * 0.14) + ((totalYearlyIncome - 99916) * 0.16);
                else
                    provincialTax = (49958 * 0.094) + ((99916 - 49958) * 0.14) + ((185064 - 99916) * 0.16) + ((totalYearlyIncome - 185064) * 0.195);
            }
            else if (userProvince == '10')
            { // Newfoundland and Labrador
                printf("\nProvince: %s \n", provinceList[userProvince - '0']);
                if (totalYearlyIncome <= 43198)
                    provincialTax = totalYearlyIncome * 0.087;
                else if (totalYearlyIncome <= 86395)
                    provincialTax = (43198 * 0.087) + ((totalYearlyIncome - 43198) * 0.145);
                else if (totalYearlyIncome <= 154244)
                    provincialTax = (43198 * 0.087) + ((86395 - 43198) * 0.145) + ((totalYearlyIncome - 86395) * 0.158);
                else if (totalYearlyIncome <= 215943)
                    provincialTax = (43198 * 0.087) + ((86395 - 43198) * 0.145) + ((154244 - 86395) * 0.158) + ((totalYearlyIncome - 154244) * 0.178);
                else if (totalYearlyIncome <= 275870)
                    provincialTax = (43198 * 0.087) + ((86395 - 43198) * 0.145) + ((154244 - 86395) * 0.158) + ((215943 - 154244) * 0.178) + ((totalYearlyIncome - 215943) * 0.198);
                else if (totalYearlyIncome <= 551739)
                    provincialTax = (43198 * 0.087) + ((86395 - 43198) * 0.145) + ((154244 - 86395) * 0.158) + ((215943 - 154244) * 0.178) + ((275870 - 215943) * 0.198) + ((totalYearlyIncome - 275870) * 0.208);
                else
                    provincialTax = (43198 * 0.087) + ((86395 - 43198) * 0.145) + ((154244 - 86395) * 0.158) + ((215943 - 154244) * 0.178) + ((275870 - 215943) * 0.198) + ((totalYearlyIncome - 275870) * 0.208) + ((totalYearlyIncome - 551739) * 0.213);
            }

            // Final prints
            printf("\n\033[1;34mHere's the breakdown of your Net income (income after tax): \n");
            printf("\nYour estimated federal tax per year: %.2f CAD\n", federalTax);
            printf("Your estimated provincial tax for the province of %s per year: %.2f CAD\n", provinceList[userProvince - '0'], provincialTax);
            printf("Your estimated total tax yearly: %.2f CAD\n", totalTax);

            printf("Your estimated net daily income: %.2f CAD\n", (totalYearlyIncome - totalTax) / 365);
            printf("Your estimated net weekly income: %.2f CAD\n", (totalYearlyIncome - totalTax) / 54);
            printf("Your estimated net bi-weekly income: %.2f CAD\n", (totalYearlyIncome - totalTax) / 27);
            printf("Your estimated net monthly income: %.2f CAD\n", (totalYearlyIncome - totalTax) / 12);
            printf("Your estimated net yearly income: %.2f CAD\n", totalYearlyIncome - totalTax);
        }
    }

    while (!validChoice);

    return 0;
}