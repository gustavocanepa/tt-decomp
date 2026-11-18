#include "types.h"
extern char D_0060C128[];
extern "C" s32 func_004A8368(const char *s);
extern "C" s32 func_004E5700(const char *a, const char *b, s32 n);

extern "C" void func_004A9468(char *arg0) {
    char *s;
    char *end;
    char c;

    if (func_004E5700(arg0, D_0060C128, 5) != 0) {
        return;
    }
    s = arg0 + 5;
    if (s[1] == ':') {
        s = arg0 + 6;
    }
    if (*s != ':') {
        return;
    }
    end = s + func_004A8368(s);
    if (end[-2] != ';') {
        return;
    }
    if (end[-1] != '1') {
        return;
    }
    end -= 2;
    while (s < end) {
        c = *s;
        if ((unsigned char)(c - 'a') < 26) {
            *s = c - 0x20;
        } else if (c == '/') {
            *s = '\\';
        }
        s++;
    }
}
