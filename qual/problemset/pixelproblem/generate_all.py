import os
import subprocess

paths = [
"data/secret/g1",
"data/secret/g2",
"data/secret/g3",
"data/secret/g4"]

image_formats = ["jpg", "jpeg", "png", "gif"]

if __name__ == "__main__":
    for path in paths:
        for p,_,files in os.walk(path):
            for f in files:
                if f.split(".")[-1] in image_formats:
                    print "Generating " + f.split(".")[0] + "..."
                    subprocess.call(["python", "create_testcase.py", os.path.join(path, f)])
