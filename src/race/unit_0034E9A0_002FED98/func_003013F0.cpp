typedef int s32;
typedef short s16;

struct Obj {
    char pad[0x668];
    s16 unk64C;
};

extern "C" void func_003013F0(char *arg0) {
    struct Obj *obj = (struct Obj *)(arg0 + 0x104);
    if (obj->unk64C > 0) {
        obj->unk64C = 0;
        return;
    }
    obj->unk64C = -1;
}
