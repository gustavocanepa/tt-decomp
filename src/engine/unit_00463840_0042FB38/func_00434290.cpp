/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Item { signed char id; char pad1; signed char kind; char pad3[0x11]; float value; };
struct Range { void *data; int count; char pad[8]; };
struct Root { char pad0[0x10]; char *other; char pad14[0xf0]; char data[0x4a4]; float limit; };
struct Self { char pad0[0x1c]; unsigned char id, pos, pad1e, current; char pad20[8]; float value; char pad2c[0xbc]; Root *root; void *source; };
extern "C" void func_004368A8(Range *, void *, int);
extern "C" Item *func_00436968(Range *, int);
extern "C" float func_00433C70(Self *, int) throw();
extern "C" void func_004341A8(Self *) throw();
static inline unsigned char getid(Item *item) { return item->id; }
extern "C" void func_00434290(Self *self) {
    Range range;
    int i = 0;
    char *data = self->root->data;
    char *other = self->root->other;
    func_004368A8(&range, self->source, self->id);
    float limit = *(float *)(data + 0x4C4);
    int count = range.count;
    self->pos = count;
    for (; i < count; ++i) {
        if (limit < ((Item *)func_00436968(&range, i))->value) {
            self->pos = i;
            break;
        }
    }
    int index = self->pos + count - 1;
    while (index >= count) index -= count;
    if (((Item *)func_00436968(&range, index))->kind == -128) {
        --index;
        index += (index < 0) * count;
    }
    switch (self->current = ((Item *)func_00436968(&range, index))->id) {
    case 0: self->value = *(float *)(other + 0x101C); break;
    default: self->value = func_00433C70(self, index); break;
    }
    func_004341A8(self);
}
