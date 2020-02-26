#include <cstdio>

typedef struct {
    char id[16];
    int in_time;
    int out_time;
}Person;

Person min, max, temp;

void init() {
    min.in_time = 24*3600;
    max.out_time = 0;
}

int main() {
    init();
    int M, inHH, inMM, inSS, outHH, outMM, outSS;
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%s %d:%d:%d %d:%d:%d", temp.id, &inHH, &inMM, &inSS, &outHH, &outMM, &outSS);
        temp.in_time = inHH*3600 + inMM*60 + inSS;
        temp.out_time = outHH*3600 + outMM*60 - outSS;
        if (temp.in_time < min.in_time) min = temp;
        if (temp.out_time > max.out_time) max = temp;
    }
    printf("%s %s", min.id, max.id);
    return 0;
}