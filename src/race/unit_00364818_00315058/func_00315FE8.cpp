/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Table { unsigned char pad; unsigned char count; };
struct Entry { float value; char pad[0xF4-4]; };
struct Obj { char pad[0x10]; void *p; char pad2[0x1dc-0x14]; Entry entries[1]; };
extern "C" Table *func_002FD378(void *);
extern "C" int func_00315FE8(Obj *self) {
    int result = func_002FD378(self->p)->count;
    int i = 0;
    if (result != 0) {
        int n = result;
        do {
            result = 1;
            if (self->entries[i].value != 0.0f) return result;
            i++;
        } while (i < n);
    }
    result = 0;
    return result;
}
