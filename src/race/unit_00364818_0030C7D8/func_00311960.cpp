/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Info {unsigned char tag, count;};
struct Dst {float x, y, z; char pad[0x34-12];};
struct Obj {char pad0[0x10]; void *o10; char pad1[0x824-0x14]; Dst dst[1];};
extern "C" Info *func_002FD378(void *);
extern "C" float func_00311840(Obj *, int) throw();
extern "C" float func_003118D8(Obj *, int, int, float) throw();
extern "C" void func_00311960(Obj *self){
    float v[3];
    int i = 0;
    Info *info = func_002FD378(self->o10);
    if (__builtin_expect(info->count, 0) == 0) return;
    Dst *d = self->dst;
    do {
        float t = func_00311840(self, i);
        for (int j = 0; j < 3; j++)
            v[j] = func_003118D8(self, i, j, t);
        i++;
        d->x = v[0];
        d->y = v[2];
        d->z = -v[1];
        d++;
    } while (i < info->count);
}
