import sys

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        exit(1)
    return default

N = int(cmdlinearg('n'))//6

sys.stdout.write("abc")
for i in range(N):
    sys.stdout.write("lo")
sys.stdout.write("ldef\n")

sys.stdout.write("abobc")
for i in range(2*N+2):
    sys.stdout.write("lo")
sys.stdout.write("ldef\n")
