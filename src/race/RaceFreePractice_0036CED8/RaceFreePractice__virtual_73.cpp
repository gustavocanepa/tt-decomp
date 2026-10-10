struct Car { char pad[0x18]; int id; };
struct Entry { Car *car; };
struct Grid { char pad[8]; Entry *entry; };
struct Race { char pad[0x60]; Grid *grid; char pad2[0x90]; char hud[4]; };
struct RaceFreePractice { char pad[0x6C]; Race *race; };

extern "C" void func_0037AD38(RaceFreePractice *self);
extern "C" int func_00301300(int id);
extern "C" void func_0036C908(void *hud, int a, int b, int c);

extern "C" void RaceFreePractice__virtual_73(RaceFreePractice *self)
{
    func_0037AD38(self);
    if (func_00301300(self->race->grid->entry->car->id) == 1)
        func_0036C908(self->race->hud, 1, 0, 0);
}
