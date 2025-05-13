
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//hi
// 승자를 결정하는 함수
void the_winner_is(int winner[], int arr_for_previous[], int size) {
    int first_ath_pts, second_ath_pts;

    for (int i = 0; i < size / 8; i++) {
        first_ath_pts = rand() % 6;
        second_ath_pts = rand() % 6;

        while (first_ath_pts == second_ath_pts) {
            printf(" 경기 %d: 선수%d vs 선수%d\n 선수 %d의 점수: %d\n 선수 %d의 점수: %d\n 동점입니다! 재경기를 진행합니다.\n", 
                   i + 1, arr_for_previous[2 * i], arr_for_previous[2 * i + 1],
                   arr_for_previous[2 * i], first_ath_pts, arr_for_previous[2 * i + 1], second_ath_pts);
            first_ath_pts = rand() % 6;
            second_ath_pts = rand() % 6;    
        }

        if (first_ath_pts > second_ath_pts) {
            winner[i] = arr_for_previous[2 * i];  // 승자 저장하기
            printf("경기 %d: 선수%d vs 선수%d\n 선수 %d의 점수: %d\n 선수 %d의 점수: %d\n 승자: 선수 %d (%d vs %d)\n\n", 
                   i + 1, arr_for_previous[2 * i], arr_for_previous[2 * i + 1],
                   arr_for_previous[2 * i], first_ath_pts, arr_for_previous[2 * i + 1], second_ath_pts,
                   arr_for_previous[2 * i], first_ath_pts, second_ath_pts);
        } else {
            winner[i] = arr_for_previous[2 * i + 1];  // 승자 저장하기
            printf("경기 %d: 선수%d vs 선수%d\n 선수 %d의 점수: %d\n 선수 %d의 점수: %d\n 승자: 선수 %d (%d vs %d)\n\n", 
                   i + 1, arr_for_previous[2 * i], arr_for_previous[2 * i + 1],
                   arr_for_previous[2 * i], first_ath_pts, arr_for_previous[2 * i + 1], second_ath_pts,
                   arr_for_previous[2 * i + 1], second_ath_pts, first_ath_pts);
        }
    }
}

int main() {
    int athlete[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int mid_athlete[4] = {0, 0, 0, 0};
    int final_athlete[2] = {0, 0};
    int winner[1];  
    printf("8명의 참가자 명단:\n");
    for(int j = 0; j<8;j++){
        printf("선수%d\n",athlete[j]);
    }
    srand(time(NULL));  // 현재 시간을 시드로 사용
    printf("===토너먼트 시작===\n\n");

    // 라운드 1
    printf("라운드 1 (남은 참가자: %d명)\n----------------\n", sizeof(athlete) / sizeof(athlete[0]));
    the_winner_is(mid_athlete, athlete, sizeof(athlete));

    // 라운드 2
    printf("라운드 2 (남은 참가자: %d명)\n----------------\n", sizeof(mid_athlete) / sizeof(mid_athlete[0]));
    the_winner_is(final_athlete, mid_athlete, sizeof(mid_athlete));

    // 라운드 3
    printf("라운드 3 (남은 참가자: %d명)\n----------------\n", sizeof(final_athlete) / sizeof(final_athlete[0]));
    the_winner_is(winner, final_athlete, sizeof(final_athlete));

    // 최종 승자 출력
    printf("===토너먼트 우승자===\n 축하합니다! 선수%d가 우승했습니다!\n", winner[0]);  
    
    return 0;
}
