/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { short delta; short index; void (*fn)(void *, float); };
struct Obj { char *vt; };
struct Message { char pad[0x18]; float x; float y; unsigned int color; };
struct Text { char pad[0x12c]; const char *start; };
extern Text *D_00584418;
extern "C" int RaceDisplay__is_play_mode(Obj *);
extern "C" const char *RaceDisplay__get_race_signal_font(Obj *);
extern "C" void RaceMessageDisplay__setFont(void *, const char *, int);
extern "C" void RaceMessageDisplay__setMessage(void *, const char *, float, float);
static inline void position(Message *m, float x, float y) { m->x = x; m->y = y; }
static inline void invoke(Obj *self, int off, float value) {
    Entry *e = (Entry *)(self->vt + off);
    e->fn((char *)self + e->delta, value);
}
extern "C" void func_00356608(Obj *self) {
    if (RaceDisplay__is_play_mode(self)) {
        const char *font = RaceDisplay__get_race_signal_font(self);
        Message *m = (Message *)((char *)self + 0x24EC);
        RaceMessageDisplay__setFont(m, font, 0);
        m->color = 0x80c8c8c8;
        position(m, 0.0f, 0x1.333332p-3f);
        RaceMessageDisplay__setMessage(m, D_00584418->start, 1.0f, 0.0f);
    }
    invoke(self, 0x1B0, 8.0f);
    invoke(self, 0x1B8, 8.0f);
}
