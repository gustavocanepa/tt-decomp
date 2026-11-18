/* compiler: ee-gcc2.96-no-strict-aliasing */
struct O {
    char pad0[0x28];
    int i28; int i2C;
    char pad1[0x80 - 0x30];
    float f80[18];
    int aC8[6];
    int aE0[6];
    int res[6];
};
struct Ctx3 { char pad[0x23968]; int n; };
extern "C" int func_00393A80(int) throw();
extern "C" void func_003EEC90(void *);
extern "C" void func_003EECA0(void *, int, int);
extern "C" int func_003F07C0(void *, int, int, float *, float, float);
static inline int invalid_result(const int &value) { return value; }
extern "C" void func_00395FA8(O *o, int a1, Ctx3 *c, int a3)
{
    char ctx[16];
    float sp10;
    int i = 0;
    func_003EEC90(ctx);
    func_003EECA0(ctx, 0, a1);
    do {
        if (o->i28 != 0) {
            if (func_003F07C0(ctx, o->aC8[a3], func_00393A80(i), &sp10, o->f80[a3], (float)o->aE0[a3]) != 0) {
                o->res[i] = (int)(sp10 + 0.5f);
            } else {
                o->res[i] = invalid_result(-1);
            }
            int v = o->res[i];
            if (v != 2) {
                if (c->n == 1) {
                    o->res[i] = invalid_result(-1);
                    v = invalid_result(-1);
                }
            }
            if (v == 2 && o->i2C == 0) {
                o->res[i] = invalid_result(-1);
            }
        } else {
            o->res[i] = invalid_result(-1);
        }
        i++;
    } while (i < 6);
}
