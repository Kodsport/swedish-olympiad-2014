import Image
import sys


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print "Usage: python create_testcase [IMAGE_PATH]"
        exit()
    im = Image.open(sys.argv[1]).convert("RGB")
    pixels = list(im.getdata())
    print len(pixels)
    print " ".join(map(lambda x: " ".join(map(str, x)), pixels))
