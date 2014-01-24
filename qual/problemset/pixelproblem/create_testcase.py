import Image
import sys


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print "Usage: python create_testcase [IMAGE_PATH]"
        exit()
    image_name = sys.argv[1]
    testcase_name = image_name.split(".")[0]
    im = Image.open(image_name).convert("RGB")
    f = open(testcase_name + ".in", "w")
    pixels = list(im.getdata())
    f.write(str(len(pixels))+"\n")
    f.write(" ".join(map(lambda x: " ".join(map(str, x)), pixels)))
    f.write("\n")
    f.close()

    f = open(testcase_name + ".ans", "w")
    w,h = im.size
    f.write(" ".join(map(str,[w,h]))+"\n")
    f.close()
