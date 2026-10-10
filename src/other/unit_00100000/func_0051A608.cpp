typedef int s32;

/* hObject; its constructor is func_002A7618. The vptr follows its first word. */
struct func_002A7618 {
    s32 m0;
    func_002A7618();
    virtual ~func_002A7618();
};

struct mGame : func_002A7618 {
    s32 m8, mC;
    s32 m10;
    s32 m14;
    mGame(s32 a);
    virtual ~mGame();
};

mGame::mGame(s32 a) : m10(a), m14(0) {
}
