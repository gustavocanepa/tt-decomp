typedef struct Range {
    int start;
    int index;
    int count;
} Range;

extern void func_00424130(Range *r, int a);
extern void func_00423FB0(Range *r, int b);

Range func_00424178(int a, int b)
{
    Range r;
    r.index = -1;
    r.count = 0;
    r.start = 0;
    func_00424130(&r, a);
    func_00423FB0(&r, b);
    return r;
}
