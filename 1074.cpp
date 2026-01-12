#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

// 0~3 중 하나 반환
int getL(int N, int x, int y) {
    int MID = (N - 1) / 2;
    if (x <= MID && y <= MID) {
        return 0;
    }
    if (x <= MID && y > MID) {
        return 1;
    }
    if (y <= MID) {
        return 2;
    }
    return 3;
}

int getV(int x, int y) {
    if (x == 0 && y == 0) {
        return 0;
    }
    if (x == 0 && y == 1) {
        return 1;
    }
    if (x == 1 && y == 0) {
        return 2;
    }
    return 3;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, R, C;
    cin >> N >> R >> C;

    int SIZE = (1 << N);

    int total = 0;
    while (N != 1) {
        int L = getL(SIZE, R, C);
        total += pow(4, N - 1) * L;

        SIZE /= 2;
        R %= SIZE;
        C %= SIZE;
        N--;
    }

    total += getV(R, C);

    cout << total;
}
/*
[문제 분석]
1. 시간 복잡도 제약:
  - N <= 15일 때, 배열 크기는 2^15 * 2^15 = 2^30 (약 10억)이다.
  - 제한 시간 0.5초 내에 모든 좌표를 순회하는 O(4^N) 방식은 불가능
  - 따라서 좌표를 직접 찾아가는 O(N)의 분할 정복(divide-and-conquer) 방식이 필요

[알고리즘 설계]
1. 사분면 분할:
  - 전체 맵을 4개의 사분면(제1~4 구역)으로 나눔
  - 각 사분면의 크기(칸의 개수)는 4^(N-1)

2. 값 누적 및 재귀적 축수 (While 반복):
  - (R, C)가 현재 어느 사분면에 속하는지 판별 (0,1,2,3).
  - '이전 사분면들의 크기'만큼 결과값(total)에 합산
    -> total += (4^(N-1)) * (사분면 번호)
  - 좌표를 해당 사분면 내부의 상대 좌표로 갱신하고, N을 1 줄여 범위를 좁힘

3. Base Case:
  - N=1일 때 남은 좌표에 따라 0~3의 값 중 하나를 더하고 종료함
 */
