/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rec { char data[64]; };
struct Obj { int count; Rec records[64]; };
extern "C" int func_003EB9B0(Obj *self, const Rec *src, int index) {
    int n = self->count;
    if (n >= 64) return -1;
    if (index < 0 || index > n) index = n;
    for (int j = n; j > index; --j) self->records[j] = self->records[j - 1];
    self->records[index] = *src;
    self->count++;
    return index;
}
