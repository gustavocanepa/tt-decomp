extern "C" float func_003A57E8(int a, int b);
extern "C" void ComputeTireWearGaugeColor(int level, int a, int b, int c);

extern "C" float func_003A5808(int a, int b, int c, int d, int e)
{
    float v = func_003A57E8(a, b);
    ComputeTireWearGaugeColor((int)(v * 127.0f), c, d, e);
    return v;
}
