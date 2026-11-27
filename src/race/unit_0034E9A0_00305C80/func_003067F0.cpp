/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Body { char pad[0x4D2]; unsigned char busy; };
struct Car { char pad[0x104]; Body body; };
extern "C" unsigned short func_003067D0(Body *) throw();
extern "C" int func_003067F0(Car *car) {
    int r = 0;
    Body *b = &car->body;
    if (b->busy != 0) return r;
    r = (func_003067D0(b) + 59) / 60;
    return r;
}
