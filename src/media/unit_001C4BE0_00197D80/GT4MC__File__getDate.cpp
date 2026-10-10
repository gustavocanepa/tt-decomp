typedef struct { char b[9]; } Str9;
extern "C" Str9 D_005E6AC0;
extern "C" char D_005E6AD0[];
extern "C" int func_004A6500(char *, const char *, ...);

struct Date {
    unsigned char pad[4];
    unsigned char m;
    unsigned char d;
    unsigned short y;
};

extern "C" void GT4MC__File__getDate(char *obj, char *buf) {
    Date *d = (Date *)(obj + 0x10);
    if (d->y == 0) {
        *(Str9 *)buf = D_005E6AC0;
        return;
    }
    func_004A6500(buf, D_005E6AD0, d->y - 2000, d->d, d->m);
}
