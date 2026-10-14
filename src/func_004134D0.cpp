#define NULL 0

typedef struct { char b[16]; } Block16;

void func_004134D0(void *arg0, void *arg1) {
    *(Block16 *)arg0 = *(Block16 *)arg1;
}
