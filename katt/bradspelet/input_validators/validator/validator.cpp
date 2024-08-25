#include "validator.h"

void run() {
    int mx = Arg("max_v", 100);
    int x = Int(1, mx); Space();
    int y = Int(1, mx); Endl();
    Eof();
}
