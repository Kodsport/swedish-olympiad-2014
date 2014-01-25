import Image
import sys
import random

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print "Usage: python create_testcase [IMAGE_PATH]"
        exit()
    image_name = sys.argv[1]
    testcase_name = image_name.split(".")[0]
    im = Image.open(image_name).convert("RGB")
    w,h = im.size

    f = open(testcase_name + ".in", "w")
    pixels = list(im.getdata())
    trunc = random.randrange(1,w)
    for i in xrange(trunc):
        pixels.pop()
    f.write(str(len(pixels))+"\n")
    f.write(" ".join(map(lambda x: " ".join(map(str, x)), pixels)))
    f.write("\n")
    f.close()

    f = open(testcase_name + ".ans", "w")
    f.write(str(w) + "\n")
    f.close()
