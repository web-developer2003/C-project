#include <stdio.h>
#include <string.h>

char* getLetterGrade(float percentage) {
    if (percentage >= 95) return "A+";
    else if (percentage >= 90) return "A";
    else if (percentage >= 85) return "B+";
    else if (percentage >= 80) return "B";
    else if (percentage >= 75) return "B-";
    else if (percentage >= 70) return "C+";
    else if (percentage >= 65) return "C";
    else if (percentage >= 60) return "C-";
    else if (percentage >= 40) return "D";
    else return "F";
}

float getValidInput(char* text, float min, float max) {
    float value;
    int valid = 0;

    while (!valid) {
        printf("%s", text);
        if (scanf("%f", &value) != 1) {
            // Clear invalid input
            while (getchar() != '\n');
            printf("Incorrect character! Please enter a number.\n");
            continue;
        }

        if (value < min || value > max) {
            printf("Oops! Points must be between %.0f and %.0f.\n", min, max);
        } else {
            valid = 1;
        }
    }

    return value;
}

int main() {
    float midtermPoints, finalPoints, linuxPoints, cPoints;
    char eligible;

    float midtermPercent, finalPercent, linuxPercent, cPercent;
    float totalPercent;
    char examType[20];

    printf("========================================\n");
    printf("   Student Grading Calculator System\n");
    printf("========================================\n\n");

    // Mid-term Exam (100 points = 30%)
    midtermPoints = getValidInput("Enter Mid-term exam points (out of 100): ", 0, 100);
    midtermPercent = (midtermPoints / 100) * 30;

    // Final Exam (50 points = 30%)
    finalPoints = getValidInput("Enter Final exam points (out of 50): ", 0, 50);
    finalPercent = (finalPoints / 50) * 30;

    // Linux Exam (100 points = 20%)
    linuxPoints = getValidInput("Enter Linux exam points (out of 100): ", 0, 100);
    linuxPercent = (linuxPoints / 100) * 20;

    int choice = 0;

    while (!choice) {
        printf("Are you eligible for Cisco exam? (y/n): ");
        scanf(" %c", &eligible);

        if (eligible == 'y' || eligible == 'Y' || eligible == 'n' || eligible == 'N') {
            choice = 1;
        } else {
            printf("Invalid character! Please enter 'y' or 'n'.\n");
            // Clear input buffer
            while (getchar() != '\n');
        }
    }

    if (eligible == 'y' || eligible == 'Y') {
        cPoints = getValidInput("Enter Cisco exam points (out of 100): ", 0, 100);
        strcpy(examType, "Cisco");
    } else {
        cPoints = getValidInput("Enter C Lab exam points (out of 100): ", 0, 100);
        strcpy(examType, "C Lab");
    }
    cPercent = (cPoints / 100) * 20;

    // calculate total percent
    totalPercent = midtermPercent + finalPercent + linuxPercent + cPercent;

    // Results
    printf("\n========================================\n");
    printf("           GRADE SUMMARY\n");
    printf("========================================\n\n");

    printf("Exam Name          Points    Percentage\n");
    printf("----------------------------------------\n");
    printf("Mid-term          %.2f/100   %.2f%%\n", midtermPoints, midtermPercent);
    printf("Final             %.2f/50    %.2f%%\n", finalPoints, finalPercent);
    printf("Linux             %.2f/100   %.2f%%\n", linuxPoints, linuxPercent);
    printf("%-17s %.2f/100    %.2f%%\n", examType, cPoints, cPercent);
    printf("----------------------------------------\n");
    printf("TOTAL PERCENTAGE:              %.2f%%\n", totalPercent);
    printf("Grade:                  %s\n", getLetterGrade(totalPercent));
    printf("----------------------------------------\n");

    // Pass/Fail Status
    if (totalPercent >= 40) {
        printf("Congratulations you passed\n");
    } else {
        printf("Sorry, you have to pay 2.5mln sums ^_^ \n");
    }


    return 0;
}