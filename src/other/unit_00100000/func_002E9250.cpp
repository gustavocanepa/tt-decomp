struct Cond { char pad[0x2394C]; short lap; unsigned char done; };
extern "C" int func_002F04F0(Cond *self);

extern "C" int func_002E9250(Cond *self)
{
    int r = func_002F04F0(self); if (r == 1) { short lap = self->lap; int fin = !self->done; if (lap < 0) r = fin; } return r;
}
