#include <stdio.h>

/*
 * Calculates the rental cost based on pricing rules.
 */
int costCalculation(int first_day, int daily_cost, int weekly_max, int days) {
    int cost = 0;

    if (days == 1) {
        cost = first_day;
    }
    else if (days <= 7) {
        cost = first_day + (days - 1) * daily_cost;
        if (cost > weekly_max) {
            cost = weekly_max;
        }
    }
    else {
        int weeks = days / 7;
        int remaining_days = days % 7;

        int remaining_cost;
        if (remaining_days == 0) {
            remaining_cost = 0;
        } else if (remaining_days == 1) {
            remaining_cost = first_day;
        } else {
            remaining_cost = first_day + (remaining_days - 1) * daily_cost;
            if (remaining_cost > weekly_max) {
                remaining_cost = weekly_max;
            }
        }

        cost = weeks * weekly_max + remaining_cost;
    }

    return cost;
}

int main(void) {
    int AC, days, cost;

    // Arrays holding pricing data
    int first_day[4]   = {50, 60, 80, 200};
    int daily_rate[4]  = {30, 35, 50, 120};
    int weekly_max[4]  = {160, 200, 280, 550};

    printf("Please select from four types of AC: 1, 2, 3, and 4\n");
    printf("Enter selection: ");
    scanf("%d", &AC);

    if (AC < 1 || AC > 4) {
        printf("Invalid selection. Select from 1 to 4.\n");
        return 0;
    }

    printf("Enter days: ");
    scanf("%d", &days);

    if (days <= 0) {
        printf("Invalid days.\n");
        return 0;
    }

    // Use arrays instead of switch
    int index = AC - 1;   // Convert 1–4 to 0–3

    cost = costCalculation(
        first_day[index],
        daily_rate[index],
        weekly_max[index],
        days
    );

    printf("Charge ($): %d\n", cost);

    return 0;
}
