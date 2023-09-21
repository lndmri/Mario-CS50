#include <stdio.h>

// Define Struct for holding rates of each tool
typedef struct
{
    int rate_four_hours;
    int rate_per_day;
    int rate_per_week;
} tool;

int main(void)
{
    // fill each tool with the rates
    tool tools[4];

    tools[0].rate_four_hours = 7;
    tools[0].rate_per_day = 10;
    tools[0].rate_per_week = 40;

    tools[1].rate_four_hours = 27;
    tools[1].rate_per_day = 39;
    tools[1].rate_per_week = 156;

    tools[2].rate_four_hours = 61;
    tools[2].rate_per_day = 87;
    tools[2].rate_per_week = 348;

    tools[3].rate_four_hours = 59;
    tools[3].rate_per_day = 84;
    tools[3].rate_per_week = 336;

    int tool_num = 0;
    int hours = 0;
    int days = 0;
    int weeks = 0;
    int total_charge = 0;
    int total_week = 0;
    int total_days_hours = 0;

    // get input from user in what tool

    printf("Please select from four equipment: 1, 2, 3, and 4\n");
    printf("Enter equipment selection: ");
    scanf("%d", &tool_num);

    // validating selection
    if (tool_num < 1 || tool_num > 4)
    {
        printf("Invalid selection. Select from 1 to 4.\n");
        return 1;
    }

    // Get input from user for days and hours
    printf("Enter days: ");
    scanf("%d", &days);

    printf("Enter hours: ");
    scanf("%d", &hours);

    // Validate hours
    if (hours < 0 || hours > 24)
    {
        printf("Invalid hours.\n");
        return 1;
    }

    weeks = days / 7;
    days = days % 7;

    total_week = weeks * tools[tool_num - 1].rate_per_week;

    if (hours > 4)
    {
        total_days_hours = (days + 1) * tools[tool_num - 1].rate_per_day;
    }
    else
    {
        total_days_hours = (days * tools[tool_num - 1].rate_per_day) + tools[tool_num - 1].rate_four_hours;
    }

    // Capping charge of days and hours if it is greater than the rate per week
    if (total_days_hours > tools[tool_num - 1].rate_per_week)
    {
        total_days_hours = tools[tool_num - 1].rate_per_week;
    }

    total_charge = total_week + total_days_hours;

    printf("Charge($): %d\n", total_charge);
}