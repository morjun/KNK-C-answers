//
// Created by JediMasterJune on 21. 4. 10..
//

#include <stdio.h>

int main(void)
{
    int n;
    int y, x;
    
    printf("This program creates a magic square of a specified size. \n");
    printf("The size must be an odd number between 1 and 99.\n");
    
    do {
        printf("Enter the size of magic square : ");
        scanf("%d", &n);
    } while (n % 2 == 0);
    
    int square[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            square[i][j] = 0;
        }
    } // 배열 초기화
    
    // square[0][n / 2] = 1; // 책의 가이드라인을 따름 : row 0의 가운데에 1을 놓는다.
    y = 0, x = n / 2;// 책의 가이드라인을 따름 : row 0의 가운데에 1을 놓는다.
    for (int i = 1; i <= n * n;) {
        if (square[y][x] == 0) {
            square[y][x] = i;
            i++;
            x++; // 한 칸 오른쪽으로
            y--; // 한 칸 위로
        }
        else {
            y++;
            x--; // 원위치
            
            y++; // 한 칸 아래로
        }
        if (x >= n) {
            x -= n; // n-1번째 column 넘어가면 0으로
        }
        else if (x < 0) {
            x += n;
        }
        if (y < 0) {
            y += n; // 0번째 row를 넘어가면 n-1로.
        }
        else if (y >= n) {
            y -= n;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%2d ", square[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}