typedef int s32;

struct Obj;

extern "C" void *func_0033BC80(Obj *self, s32 id);
extern "C" void *func_00386940(Obj *self, s32 id);
extern "C" void *func_00386980(Obj *self, s32 id);

extern "C" void *RaceFreeRun__virtual_71(Obj *self, s32 id) {
    switch (id) {
    case 0x100:
        return func_00386940(self, id);
    case 1:
        return func_00386980(self, id);
    default:
        return func_0033BC80(self, id);
    }
}
