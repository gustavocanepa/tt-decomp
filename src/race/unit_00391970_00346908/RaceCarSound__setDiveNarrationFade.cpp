extern "C" int D_00583FD4;
extern "C" int D_00583FD8;
extern "C" void RaceCarSound__fadeMasterVolume(float scale, float alpha);

extern "C" void RaceCarSound__setDiveNarrationFade(void)
{
    float scale = 1.0f;
    if (D_00583FD4)
        scale = 0.45f;
    if (D_00583FD8)
        scale = 0.2f;
    RaceCarSound__fadeMasterVolume(scale, 1.0f);
}
