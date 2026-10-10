extern "C" void func_001A3438(void *a, unsigned int from, void *c, unsigned int to, int n);

extern "C" void func_001A3478(void *a, unsigned int from, void *c, unsigned int to, float t)
{
    func_001A3438(a, from, c, to, (int)(t * (float)(from - to)));
}
