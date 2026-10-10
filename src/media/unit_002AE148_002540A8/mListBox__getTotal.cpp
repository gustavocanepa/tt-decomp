struct Obj;
extern "C" float func_00253EB8(Obj *o);
extern "C" float func_00278870(Obj *o);
extern "C" int func_002541E8(Obj *o);
extern "C" float func_00254268(Obj *o);

extern "C" float mListBox__getTotal(Obj *o)
{
    float w = func_00253EB8(o) + func_00278870(o);
    int n = func_002541E8(o);
    return w * (n - 1) + func_00254268(o);
}
