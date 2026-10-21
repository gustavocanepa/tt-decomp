typedef int s32;
int func_004F8588(char *a, char *b, s32 c);
void func_003542F0(char *arg0, char *arg1, s32 arg2, char *arg3) {
    arg3 += 0x54E4;
    if (arg3 != 0) {
        arg2 -= 1;
        func_004F8588(arg1, arg3, arg2);
        arg1[arg2] = 0;
    }
}
