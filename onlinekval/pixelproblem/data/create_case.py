#!/usr/bin/python3 

import platform
import sys
from PIL import Image
import random



if __name__ == "__main__":
    try:
        if len(sys.argv) < 2:
            print("Usage: python create_testcase [IMAGE_PATH]")
            exit()
        image_name = sys.argv[1]
        testcase_name = image_name.split(".")[0]
        im = Image.open(image_name).convert("RGB")
        w,h = im.size

        pixels = list(im.getdata())
        
        trunc = random.randrange(1,min(w, int(250000/h)-10))
        print("casename",testcase_name,"range",w,":",int(250000/h)-10,", trunc:",trunc,file=sys.stderr)
        for i in range(trunc):
            pixels.pop()
        print(str(len(pixels)))
        print(" ".join(map(lambda x: " ".join(map(str, x)), pixels)))

        with open(sys.argv[2], "w") as f:
            f.write(str(w) + "\n")
    except Exception as e:
        print(str(e),file=sys.stderr)