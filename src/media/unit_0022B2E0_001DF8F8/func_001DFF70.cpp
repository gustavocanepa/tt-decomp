extern "C" {
void func_001DF250(void *) throw();
void func_001DF1F8(void *, int) throw();
void func_0029B4E0(void *, void *);
void func_0029B470(void *, void *);
void func_0029B488(void *, int);
void func_001E4E40(void *, void *);
}
extern char D_005B14B0[];
extern char D_005B1788[];
struct Filter { char *vtable; int member[3]; };
extern "C" void func_001DFF70(void *arg0, void *arg1, int arg2, void *arg3) {
    void *buf0[4];
    struct Filter buf1;
    int buf2[4];
    if (arg2 == 1) {
        func_001DF250(buf0);
        int *p2 = buf2;
        struct Filter *p1 = &buf1;
        func_0029B4E0(p2, arg3);
        p1->vtable = D_005B1788;
        p1->vtable = D_005B14B0;
        func_0029B470(p1->member, p2);
        func_0029B488(p2, 2);
        func_001E4E40(buf0[0], p1);
        p1->vtable = D_005B14B0;
        func_0029B488(p1->member, 2);
        p1->vtable = D_005B1788;
        func_001DF1F8(buf0, 2);
    }
}
