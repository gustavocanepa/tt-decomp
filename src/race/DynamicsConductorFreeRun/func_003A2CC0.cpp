/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rec { char pad[0xC]; float time; };
struct Settings { char pad[0xE0]; int mode; };
struct Race { Settings *settings; };
struct Sub { char pad[0x460]; unsigned char index; char pad441[0x6B]; short lap; };
struct Arg { int unk0; Race *race; char pad8[0xFC]; Sub sub; };
struct Obj { char pad[0xD4]; char manager[0xFC]; int disabled; };
extern "C" Rec *func_002E8A48(int);
extern "C" void AutomobileControlRecord__Manager__reset(int);
extern "C" int func_002F2140(Race *, int);
extern "C" void func_00300070(Race *, int, Rec *);
extern "C" void func_003A2CC0(Obj *self, Arg *arg, int lap, float t) {
    Sub *s;
    if (self->disabled == 0) {
        s = &arg->sub;
        int m = (int)self + 0xD4;
        Rec *r = func_002E8A48(m);
        Race *race = arg->race;
        func_00300070(race, s->index, r);
        s->lap = lap + 1;
        AutomobileControlRecord__Manager__reset(m);
        t -= r->time;
        if (t < 0.0f) {
            if (race->settings->mode == 0 && s->index == 1) {
                func_002F2140(race, 1);
            }
            t += 1.0f;
        }
        *(float *)((char *)arg + 0x574) = t;
    }
}
