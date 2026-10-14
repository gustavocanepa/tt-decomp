typedef int s32;
typedef long long s64;

struct Database;
extern Database D_00585A30;

extern "C" s64 func_0040B840(Database *db, int key, int type);
extern "C" s32 func_0040BE90(void *self, s64 v);

extern "C" s32 func_0040BDF8(void *arg0, int arg1) {
    s64 v = func_0040B840(&D_00585A30, arg1, 0);
    if (v == -1) {
        v = func_0040B840(&D_00585A30, arg1, 0x26);
        if (v == -1) {
            return 0;
        }
    }
    return func_0040BE90(arg0, v);
}
