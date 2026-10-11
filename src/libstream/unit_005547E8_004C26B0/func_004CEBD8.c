/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef struct Obj {
    char pad0[0x4C];
    int result[2];
    int flag[2];
    int sema;
} Obj;

int func_004F4348(int sema);
int func_004F42C8(int sema);

int func_004CEBD8(Obj *o, int i, int *out) {
    *out = -1;
    func_004F4348(o->sema);
    if (o->flag[i])
        o->flag[i] = 0;
    *out = o->result[i];
    func_004F42C8(o->sema);
    return *out == -1 ? 3 : 0;
}
