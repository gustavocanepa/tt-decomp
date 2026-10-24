/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rec { char data[64]; };
struct Obj { int count; Rec records[1]; };
extern "C" int func_003EBB28(Obj *self, int idx) {
    int n = self->count;
    if (idx < 0 || idx >= n) return 0;
    for (; idx < n - 1; idx++) self->records[idx] = self->records[idx + 1];
    self->count--;
    return 1;
}
