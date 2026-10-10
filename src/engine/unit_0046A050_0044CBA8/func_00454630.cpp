struct Box {
    float row[2][4];
    float extra;
};

extern "C" void func_00454250(Box *out, int row, const Box *a, const Box *b);

extern "C" void func_00454630(Box *out, const Box *a, const Box *b)
{
    func_00454250(out, 0, a, b);
    func_00454250(out, 1, a, b);
    out->extra = a->extra - b->extra;
}
