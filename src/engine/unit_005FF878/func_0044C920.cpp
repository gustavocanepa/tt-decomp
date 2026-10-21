/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { long long word0; long long value; };
struct Obj { char pad[0x30]; Entry *entries; int word34; int count; };
extern "C" long long func_0044C920(Obj *self, int index) {
    if (index >= self->count) return 0;
    return self->entries[index].value;
}
