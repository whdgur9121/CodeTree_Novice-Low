#include <iostream>

using namespace std;

int x1[2], y1[2];
int x2[2], y2[2];

int main() {
    cin >> x1[0] >> y1[0] >> x2[0] >> y2[0];
    cin >> x1[1] >> y1[1] >> x2[1] >> y2[1];

    // Please write your code here.
    // 1번째 직사각형에 +1
    // 2번째 직사각형은 0으로 초기화
    // +1된 구역을 정하기
    // 배열 선언은 2001을 하고, 값에 1000씩을 더해 양수화

    int arr[2001][2001];
    for(int i = 0; i<2001; i++) {
        for(int k = 0; k<2001; k++) {
            arr[i][k] = 0;
        }
    }

    int first_start_x = x1[0] + 1000;
    int first_start_y = y1[0] + 1000;
    int first_finish_x = x2[0] + 1000;
    int first_finish_y = y2[0] + 1000;

    //cout << first_start_x << " " << first_finish_x << endl;
    //cout << first_start_y << " " << first_finish_y << endl;

    for(int i = first_start_x; i<first_finish_x; i++) {
        for(int k = first_start_y; k<first_finish_y; k++) {
            arr[i][k]++;
        }
    }

    int second_start_x = x1[1] + 1000;
    int second_start_y = y1[1] + 1000;
    int second_finish_x = x2[1] + 1000;
    int second_finish_y = y2[1] + 1000;

    //cout << second_start_x << " " << second_finish_x << endl;
    //cout << second_start_y << " " << second_finish_y << endl;

    for(int i = second_start_x; i<second_finish_x; i++) {
        for(int k = second_start_y; k<second_finish_y; k++) {
            arr[i][k] = 0;
        }
    }

    //문제를 잘못 이해
    //+1된 구역을 덮는 최소한의 직사각형을 구하는 문제
    //즉, 그 구역의 넓이가 아닌 다 덮을 수 있는 사각형을 추적해야 함
    //x의 최댓값, y의 최댓값을 구해서 넓이 구하기
    //4번 계산이 필요
    //왼쪽 하단에서 위, 우측 하단에서 위로
    //왼쪽 하단에서 좌측으로, 왼쪽 상단에서 좌측으로

    int max_x = 0;
    int max_y = 0;
    for(int i = first_start_x; i<first_finish_x; i++) {
        int cnt_y = 0;
        for(int k = first_start_y; k<first_finish_y; k++) {
            if(arr[i][k] == 1) {
                cnt_y++;
            }
        }
        if(cnt_y > max_y) {
                max_y = cnt_y;
        }
    }
    for(int i = first_start_y; i<first_finish_y; i++) {
        int cnt_x = 0;
        for(int k = first_start_x; k<first_finish_x; k++) {
            if(arr[k][i] == 1) {
                cnt_x++;
            }
        }
        if(cnt_x > max_x) {
            max_x = cnt_x;
        }
    }

    cout << max_x * max_y << endl;


    return 0;
}