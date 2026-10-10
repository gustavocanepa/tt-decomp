struct Movie { char pad[0x1C]; float frameRate; };
struct mFlashPS2 {
    char pad[0xC];
    Movie *movie;
    void *player;
    char pad2[8];
    int loaded;
};

extern "C" void func_0043BE20(void *player, int frame);

extern "C" void func_002154E0(mFlashPS2 *self, float time)
{
    if (self->loaded && self->player && self->movie)
        func_0043BE20(self->player, (int)(time * self->movie->frameRate));
}
