/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Key { int pad[2]; float time; };
struct Track { int count; int pad[2]; Key *keys[1]; };

extern "C" int func_003F5048(Track *t, int lo, int hi, float time) throw();

extern "C" int func_003F50A0(Track *t, float time)
{
    int index;
    if (time <= t->keys[0]->time) {
        index = 0;
    } else if (t->keys[t->count - 1]->time <= time) {
        index = t->count - 1;
    } else {
        index = func_003F5048(t, 0, t->count - 1, time);
    }
    return index;
}
