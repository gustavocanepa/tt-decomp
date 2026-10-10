struct B { char pad[0x20B00]; unsigned char cell[2][6]; };
void func_003A1240(struct B *b, int row, int col, unsigned char v)
{
    b->cell[row][col] = v;
}
