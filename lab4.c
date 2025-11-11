#include <stdio.h>

void TowerofHanoi(int, char, char, char);
void main(){
    int n;
    printf("Enter a No. of disk: ");
    scanf("%d", &n);

    printf("Steps to solve Tower of Hanoi: \n");
    // A- source, B-Destination and C- Aux
    TowerofHanoi(n,'A','C','B');
    
}

void TowerofHanoi(int n, char fromsrc, char aux, char todes){
    if (n==1){
        printf("Move disk 1 from %c to %c\n",fromsrc, todes);
        return;
    }
    TowerofHanoi(n - 1, fromsrc, todes, aux);
    printf("Move disk %d from %c to %c\n", n, fromsrc, todes);
    TowerofHanoi(n - 1, aux, fromsrc, todes);

}
