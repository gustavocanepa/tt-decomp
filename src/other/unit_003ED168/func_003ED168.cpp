typedef int s32;

struct Obj001C7208 {
    char pad[0xB0];
    void *unkB0;
};

extern char D_005D7408[];
extern "C" s32 func_003ED1C0(Obj001C7208 *arg0);

extern "C" s32 func_003ED168(Obj001C7208 *arg0) {
    arg0->unkB0 = D_005D7408;
    return func_003ED1C0(arg0);
}
