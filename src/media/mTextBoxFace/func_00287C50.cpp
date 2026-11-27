/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x3F8]; int pos; int active; };
struct Event { char pad[0x20]; int key; };
extern "C" int func_00287A08(void *, int) throw();
extern "C" int func_00287A50(void *, int) throw();
extern "C" int func_00287C50(Obj *self, void *arg1, Event *event) {
    int key = event->key;
    int handled = 0;
    if (key == 0xFF52 || key == 0xFF97) {
        func_00287A08(self, 1);
        handled = 1;
    } else if (key == 0xFF54 || key == 0xFF99) {
        func_00287A50(self, 1);
        handled = 1;
    } else if (key == 0xFF55) {
        func_00287A08(self, 16);
        handled = 1;
    } else if (key == 0xFF56) {
        func_00287A50(self, 16);
        handled = 1;
    } else if (key == 0xFF1B) {
        if (self->active) {
            self->active = 0;
            self->pos = 0;
        }
        handled = 1;
    }
    return handled * 2;
}
