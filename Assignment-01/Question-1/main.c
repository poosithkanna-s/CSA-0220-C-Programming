#include <stdio.h>
int main() {
    float distance, fare;
    int member;
    printf("Enter distance travelled (in Km): \n");
    scanf("%f",&distance);

    printf("Is the customer a member(1=yes,0=No) ?: \n");
    scanf("%d",&member);

    fare=100;
    if (distance>0){
        fare +=(distance-10)*20;
    }
    if (member==1){
        fare=fare-(fare*0.10);
    }
    printf("Amount payable: Rs. %.2f\n",fare);
    return 0;
}