/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Item { volatile unsigned char id; char pad1; signed char kind; char pad3[0x11]; float value; };
struct Range { void *data; int count; char pad[8]; };
struct Root { char pad0[0x10]; char *other; };
struct Self { char pad0[0x1c]; unsigned char id, pos, previous, current; char pad20[4]; float oldValue, value; char pad2c[0xbc]; Root *root; void *source; };
extern "C" void func_004368A8(Range *, void *, int);
extern "C" int func_00436968(Range *, int);
extern "C" unsigned int func_0042FB38(Self *) throw();
extern "C" float func_00433C70(Self *, int) throw();
extern "C" void func_004341A8(Self *self) {
    Range range;
    char *other = self->root->other;
    func_004368A8(&range, self->source, self->id);
    int count = range.count;
    func_0042FB38(self);
    self->previous = self->current;
    int index = self->pos;
    if ((index ^ count) == 0) index = 0;
    self->oldValue = self->value;
    if (((Item *)func_00436968(&range, index))->kind == -128) {
        ++index;
        if (index >= count) index -= count;
    }
    switch (self->current = ((Item *)func_00436968(&range, index))->id) {
    case 0:
        self->value = *(float *)(other + 0x101C);
        break;
    case 1:
    case 2:
        self->value = func_00433C70(self, index);
        break;
    }
}
