typedef int s32;
typedef long long s64;

struct Database;
extern Database D_00585A30;

extern "C" s64 func_0040B840(Database *db, int key, int type);
extern "C" s32 func_004109F8(s64 id, void *out);

extern "C" s32 func_00410950(int arg0, void *arg1) {
    s64 v = func_0040B840(&D_00585A30, arg0, 0);
    if (v == -1) {
        v = func_0040B840(&D_00585A30, arg0, 0x26);
        if (v == -1) {
            return 0;
        }
    }
    return func_004109F8(v, arg1);
}
