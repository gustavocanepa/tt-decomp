/* Draws a circle as an octagon: five calls of the 4-point primitive func_00473F50 around a centre (x, y)
   with radius r and vertical scale s.
   The fifth call is a tail call. */
extern "C" int func_00473F50(int, int, int, int);

extern "C" int func_00465020(float x, float y, float r, float s)
{
    int cx = (int)x;
    int c2 = (int)(r * 0.70710695f);
    int c1 = (int)(r * 0.92387897f);
    int c3 = (int)(r * 0.38268298f);
    int cy = (int)y;
    int Y2 = (int)((float)c2 * s);
    int Y1 = (int)((float)c1 * s);
    int Y3 = (int)((float)c3 * s);
    func_00473F50(cx - c3, cy - Y1, cx + c3, cy + Y1);
    func_00473F50(cx - c2, cy - Y2, cx - c3, cy + Y2);
    func_00473F50(cx - c1, cy - Y3, cx - c2, cy + Y3);
    func_00473F50(cx + c3, cy - Y2, cx + c2, cy + Y2);
    return func_00473F50(cx + c2, cy - Y3, cx + c1, cy + Y3);
}
