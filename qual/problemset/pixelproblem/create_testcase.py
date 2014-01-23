import Image
import sys

def rgb2string(rgb):
    return "".join(map(hex_string,rgb))

def hex_string(x):
    s = hex(x).upper()[2:]
    while len(s) < 2:
        s = "0"+s
    return s

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print "Usage: python create_testcase [IMAGE_PATH]"
        exit()
    im = Image.open(sys.argv[1]).convert("RGB")
    pixels = list(im.getdata())
    print len(pixels)
    print " ".join(map(rgb2string, pixels))
