/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ctx { char pad[0x6E14]; void *anim; };
struct Slot {
    char pad[0x10];
    unsigned short loop : 1;
    unsigned short reverse : 1;
};
extern "C" void *func_004404F8(Slot *s, Ctx *c);
extern "C" void func_0043A368(void *anim, void *target, int loop, int reverse, float t);

extern "C" void func_00440518(Slot *s, Ctx *c, float t)
{
    func_0043A368(c->anim, func_004404F8(s, c), s->loop, s->reverse, t);
}
