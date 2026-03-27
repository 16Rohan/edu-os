import sys
import os

def verifyArgs(args):
    newstr = ""
    for i in range(1,len(args)):
        if not args[i].endswith(".c"):
            raise Exception("All file names must end in .c")
        else:
            newstr += " " + args[i]
    return newstr        

if len(sys.argv) > 1:
    cmd = verifyArgs(sys.argv)
    success = os.system(f"gcc {cmd}")
    if success == 0:
        print("Compilation Done.")
        os.system("mv a.out main")
    else:
        print("Error")
else:
    print("Test Function. Run using: python test.py [...filenames]")
