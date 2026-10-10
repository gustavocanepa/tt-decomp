struct Item;
struct Owner {
    char pad[0x5C];
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
    virtual int v05(Item *item, int event);
};
struct Flag { int w; };
extern "C" void func_00443CF0(Flag *f, int on);
struct Item {
    Owner *owner;
    char pad[0x3C];
    Flag flag;
};

extern "C" int func_0043D150(Item *self)
{
    func_00443CF0(&self->flag, 1);
    if (self->owner)
        return self->owner->v05(self, 16);
    return 0;
}
