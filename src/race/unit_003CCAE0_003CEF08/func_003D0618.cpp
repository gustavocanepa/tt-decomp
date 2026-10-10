struct Wheel {
    char data[0x74];
};

struct Effects {
    char data[0x14C];
};

struct Car {
    Wheel wheels[4];
    Effects effects;
    int count;
};

extern "C" void func_003CF128(Wheel *w);
extern "C" void func_003CA210(Effects *e);

extern "C" void func_003D0618(Car *car)
{
    Wheel *w = car->wheels;
    int n = 4;
    while (n--) {
        func_003CF128(w);
        w++;
    }
    func_003CA210(&car->effects);
    car->count = 0;
}
