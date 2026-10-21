/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Source { char pad[0xA8]; int source[4]; };
struct Obj { char pad[0x20A20]; Source *table; };
struct Default { char data[64]; };
extern "C" Default D_00586310[2];
extern "C" long func_00433230(Obj *self, int kind, unsigned index) {
    Source *table = self->table;
    if (index >= 4) index = 0;
    int value = table->source[index];
    long p = value;
    if (value) return p;
    int n = 0;
    switch(kind) {
    case 0: break;
    case 1: n = 0; break;
    case 2: n = 1; break;
    case 3: n = 1; break;
    default: break;
    }
    p = (int)&D_00586310[n];
    return p;
}
