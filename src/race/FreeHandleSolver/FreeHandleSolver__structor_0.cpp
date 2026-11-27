/* compiler: ee-gcc2.96-no-strict-aliasing */
struct HandleSolverBase {
 char pad[0x4c];
 HandleSolverBase(int) throw() __asm__("func_003DDF18");
 virtual ~HandleSolverBase();
};
struct FreeHandleSolver : HandleSolverBase {
 const int value;
 FreeHandleSolver(int, int) __asm__("func_003DE110");
 virtual ~FreeHandleSolver();
};
FreeHandleSolver::FreeHandleSolver(int arg, int v) : HandleSolverBase(arg), value(v) {}
