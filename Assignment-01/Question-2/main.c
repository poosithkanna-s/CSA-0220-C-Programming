#include <stdio.h>
int main() {
    int answered, submitted;
    float remainingTime;

    printf("Enter number of questions answered: ");
    scanf("%d", &answered);

    printf("Enter remaining time (in minutes): ");
    scanf("%f", &remainingTime);

    printf("Has the exam already been submitted? (1 = Yes, 0 = No): ");
    scanf("%d", &submitted);

    if (submitted == 1) {
        printf("Submission not allowed: exam already submitted.\n");
    }
    else if (answered < 1) {
        printf("Submission not allowed: answer at least one question.\n");
    }
    else if (remainingTime <= 0) {
        printf("Submission not allowed: time is over.\n");
    }
    else {
        printf("Exam submitted successfully.\n");
    }

    return 0;
}