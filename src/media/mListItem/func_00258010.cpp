struct Item {
    char pad0[0x1C];
    unsigned int low : 18;
    unsigned int flag18 : 1;
    unsigned int high : 13;
};

struct mListBox;
extern "C" int func_002571D8(mListBox *lb);
extern "C" Item *func_002571B8(mListBox *lb, int index);

extern "C" void func_00258010(mListBox *lb, int index, int on) {
    if (index >= 0 && index < func_002571D8(lb))
        func_002571B8(lb, index)->flag18 = on != 0;
}
