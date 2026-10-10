struct Date { int w[8]; };
struct Rec { unsigned long long stamp; };

extern "C" int func_0040D360(Rec *r);
extern "C" void func_004107B0(unsigned long long stamp, Date *out);
extern "C" int func_00410930(Date *d, int flag);

extern "C" int func_0040D380(Rec *r)
{
    int n = func_0040D360(r);
    Date d;
    func_004107B0(r->stamp, &d);
    if (func_00410930(&d, 1))
        n--;
    return n;
}
