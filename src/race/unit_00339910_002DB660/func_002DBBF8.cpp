typedef int s32;
typedef unsigned char u8;

struct Obj;

struct Frame {
    s32 obj0[0x6A0 / 4];
    s32 obj1[0x60 / 4];
    s32 res[0x10 / 4];
};

extern char D_005F2AB8[];
extern char D_005F2AB0[];

extern "C" void func_0036F588(Obj *arg0);
extern "C" void func_0036F300(Obj *arg0);
extern "C" void func_002DBAA8(void *arg0, char *arg1, char *arg2);
extern "C" void func_002DD9C0(char *arg0, void *arg1, void *arg2);
extern "C" s32 func_00424008(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

extern "C" void func_002DBBF8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Frame f;

    func_0036F588((Obj *)&f);
    func_0036F300((Obj *)f.obj1);
    func_00424008((s32)f.res, arg1, arg0, (s32)D_005F2AB8);
    if (f.res[1] >= 0) {
        func_002DBAA8((void *)arg0, (char *)&f, (char *)f.obj1);
        func_002DD9C0((char *)arg2, (void *)&f, (void *)f.obj1);
        func_00424008((s32)f.res, arg1, arg0, (s32)D_005F2AB0);
        if (f.res[1] >= 0) {
            func_002DBAA8((void *)arg0, (char *)&f, (char *)f.obj1);
            func_002DD9C0((char *)arg3, (void *)&f, (void *)f.obj1);
        }
    }
}
