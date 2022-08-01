#!/usr/bin/python3 

import traceback
import platform
import sys
from PIL import Image
import random

# a random seed, manually check that we don't get any stupidly small images
random.seed(69)

if __name__ == "__main__":
    best_seed=69
    bestnum=0
    random.seed(75454)
    ints = [random.randint(0,1000000) for i in range(1000)]
    for i in range(1000):
        try:
            if len(sys.argv) < 2:
                print("Usage: python create_testcase [IMAGE_PATH]")
                exit()
            
            #print(sys.argv[1],sys.argv[2],file=sys.stderr)
            image_name = sys.argv[1]
            testcase_name = image_name.split(".")[0]
            s = ints[i]
            #random.seed(int(sys.argv[3]))
            random.seed(s)
            im = Image.open(image_name).convert("RGB")
            w,h = im.size

            pixels = list(im.getdata())
            
            num = random.randrange(min(int(w*h)/3,100000),min(w*h*2, 250000))
            if num>bestnum:
                bestnum =num
                best_seed=s
            print("casename",testcase_name,"range",w,":",int(250000/h)-10,", trunc:",num,file=sys.stderr)

            print(num)
            print(" ".join(map(lambda x: " ".join(map(str, x)), pixels[:num])))

            with open(sys.argv[2], "w") as f:
                f.write(str(w) + "\n")
        except Exception as e:
            print("error:", str(e),traceback.format_exc(),file=sys.stderr)
    print("done",file=sys.stderr)
    print(best_seed,bestnum,file=sys.stderr)
