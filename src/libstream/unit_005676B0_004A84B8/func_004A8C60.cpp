struct Tag { char c[8]; };
struct Desc {
    Tag type;
    Tag group;
    Tag name;
    int id;
    int m1C;
    int m20;
    int active;
};
extern "C" Tag D_005981D8;
extern "C" Tag D_005981E0;

extern "C" void func_004A8C60(Desc *d, int id, const Tag *name)
{
    d->type = D_005981D8;
    d->group = D_005981E0;
    d->name = *name;
    d->active = 1;
    d->id = id;
    d->m20 = 0;
    d->m1C = 0;
}
