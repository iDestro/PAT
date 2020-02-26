#include <cstdio>
#include <algorithm>
int nums[4] = {0};

int arr2int(int nums[]) {
    int num = 0;
    for (int i = 0; i < 4; i++) {
        num = num*10 + nums[i];
    }
    return num;
}

void int2arr(int num) {
    for (int i = 0; i < 4; i++) {
        nums[4-i-1] = num % 10;
        num /= 10;
    }
}

bool Cmp(int a, int b) {
    return a > b;
}

int main() {
    int N;
    scanf("%d", &N);
    int2arr(N);
    while (1) {
        int2arr(N);
        std::sort(nums, nums+4, Cmp);
        int A = arr2int(nums);
        std::sort(nums, nums+4);        
        int B = arr2int(nums);
        if (A - B == 6174 || A - B == 0) {
            printf("%04d - %04d = %04d\n", A, B, A-B);
            break;
        } else {
            printf("%04d - %04d = %04d\n", A, B, A-B);
        }
        N = A-B;
    }
    return 0;
}