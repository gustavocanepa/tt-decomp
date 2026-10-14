/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VE { short adj; short pad; int (*fn)(void *, int); };
struct VT { char pad[0x18]; VE e18; };
struct Obj { VT *vt; };
extern "C" int func_004A8268(const char *, const char *) throw();
extern "C" int GranTurismo4__OptionRaceInputPortPS2__getDevice(Obj *o, const char *name) {
    if (!func_004A8268("CONTROLLER", name) || !func_004A8268("JOYSTICK", name) ||
        !func_004A8268("SINGLESHOCK", name) || !func_004A8268("DUALSHOCK", name) ||
        !func_004A8268("DUALSHOCK 2", name)) {
        VE *e = &o->vt->e18;
        return e->fn((char *)o + e->adj, 0);
    } else if (!func_004A8268("COUGAR", name)) {
        VE *e = &o->vt->e18;
        return e->fn((char *)o + e->adj, 1);
    } else if (!func_004A8268("JAGUAR", name)) {
        VE *e = &o->vt->e18;
        return e->fn((char *)o + e->adj, 2);
    } else if (!func_004A8268("CHEETAH", name)) {
        VE *e = &o->vt->e18;
        return e->fn((char *)o + e->adj, 3);
    }
    return 0;
}
