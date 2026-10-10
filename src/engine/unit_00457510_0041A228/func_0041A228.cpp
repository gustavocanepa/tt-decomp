struct Pt { float v[6]; };
struct Shape { char pad[2]; signed char nLines; char pad3; Pt pts[24]; signed char lines[1][2]; };
extern "C" void func_00474E90(Pt *, Pt *);

extern "C" void func_0041A228(Shape *s)
{
    for (int i = 0; i < s->nLines; i++)
        func_00474E90(&s->pts[s->lines[i][0]], &s->pts[s->lines[i][1]]);
}
