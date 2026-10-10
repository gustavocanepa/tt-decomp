typedef int s32;
typedef unsigned short u16;

struct Obj {
    char pad[0x24];
    u16 size;
    char pad2[0x24];
    void *data;
};

extern "C" void *func_00567248(void *, void *, s32);

extern "C" void *func_0041FE60(Obj *self, void *dst) {
    if (self->data == 0)
        return 0;
    return func_00567248(dst, self->data, self->size);
}
