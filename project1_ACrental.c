#include <stdio.h>

/*
 * Calculates the rental cost based on pricing rules. A new change
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
        int remaining_cost = remaining_days * daily_cost;

        if (remaining_cost > weekly_max) {
            remaining_cost = weekly_max;
        }

        cost = weeks * weekly_max + remaining_cost;
    }

    return cost;
}

int main(void) {
    int AC, days, cost;

    // Ask user to select AC type
    printf("Please select from four types of AC: 1, 2, 3, and 4\n");
    printf("Enter selection: ");
    scanf("%d", &AC);

    // Validate AC selection
    if (AC < 1 || AC > 4) {
        printf("Invalid selection. Select from 1 to 4.");
        return 0;
    }

    // Ask for number of rental days
    printf("Enter days: ");
    scanf("%d", &days);

    // Validate rental days
    if (days <= 0) {
        printf("Invalid days.\n");
        return 0;
    }

    /*
     * Use switch to choose pricing based on AC type.
     * Each case passes the correct pricing values to costCalculation.
     */
    switch (AC) {
        case 1:  // Mini Cooler
            cost = costCalculation(50, 30, 160, days);
            break;

        case 2:  // Mini XL
            cost = costCalculation(60, 35, 200, days);
            break;

        case 3:  // 1-Ton AC
            cost = costCalculation(80, 50, 280, days);
            break;

        case 4:  // 5-Ton AC
            cost = costCalculation(200, 120, 550, days);
            break;

        default:
            // This should never happen due to earlier validation
            printf("Invalid AC type.\n");
            return 0;
    }

    // Output final rental charge
    printf("Charge ($): %d", cost);

    return 0;
}
