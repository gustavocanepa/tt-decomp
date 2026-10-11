struct Slot {
    short id;
    short flags;
    int data;
};

struct Table {
    int lock[2];
    Slot slots[256];
    unsigned char refs[0x1C];
    int count;
};

extern "C" void func_004A4930(void *lock);
extern "C" void func_004A4970(void *lock);

extern "C" void RaceEventQueue__remove(Table *t, int idx)
{
    func_004A4930(t);
    t->refs[t->slots[idx].id]--;
    t->count--;
    for (int i = idx; i < t->count; i++) {
        t->slots[i] = t->slots[i + 1];
    }
    func_004A4970(t);
}
