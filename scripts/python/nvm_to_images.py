# Copyright (c) 2023, ETH Zurich and UNC Chapel Hill.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
#     * Redistributions of source code must retain the above copyright
#       notice, this list of conditions and the following disclaimer.
#
#     * Redistributions in binary form must reproduce the above copyright
#       notice, this list of conditions and the following disclaimer in the
#       documentation and/or other materials provided with the distribution.
#
#     * Neither the name of ETH Zurich and UNC Chapel Hill nor the names of
#       its contributors may be used to endorse or promote products derived
#       from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
# Author: Johannes L. Schoenberger (jsch-at-demuc-dot-de)

# This script converts a VisualSfM reconstruction file to a PLY point cloud.

import os
import argparse
import numpy as np


def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument("--nvm_path", required=True)
    parser.add_argument("--ply_path", required=True)
    parser.add_argument("--normalize", type=bool, default=True)
    parser.add_argument("--normalize_p0", type=float, default=0.2)
    parser.add_argument("--normalize_p1", type=float, default=0.8)
    parser.add_argument("--min_track_length", type=int, default=3)
    args = parser.parse_args()
    return args

class Img:
    def __init__(self, quaternion, translation, name):
        self.quaternion = quaternion
        self.translation = translation
        self.name = name

def main():
    args = parse_args()

    with open(args.nvm_path, "r") as fid:
        line = fid.readline()
        line = fid.readline()
        num_images = int(fid.readline())

        img_list = []
        for i in range(num_images):
            elems = fid.readline().split()
            img_list.append(Img(np.array(list(map(float, elems[2:6]))),
            np.array(list(map(float, elems[6:9]))),
            elems[0].replace('/', '_')))
        '''
        quaternion = np.zeros((num_images, 4), dtype=np.float32)
        translation = np.zeros((num_images, 3), dtype=np.float32)
        name = []

        for i in range(num_images):
            elems = fid.readline().split()
            quaternion[i] = np.array(list(map(float, elems[2:6])))
            translation[i] = np.array(list(map(float, elems[6:9])))
            name.append(elems[0].replace('/', '_'))
        '''
    
    sorted_img_list = sorted(img_list, key=lambda x: x.name)

    with open(args.ply_path, "w") as fid:
        fid.write("# Image list with two lines of data per image:\n")
        fid.write("#   IMAGE_ID, QW, QX, QY, QZ, TX, TY, TZ, CAMERA_ID, NAME\n")
        fid.write("#   POINTS2D[] as (X, Y, POINT3D_ID)\n")
        fid.write(f"# Number of images: {num_images}, mean observations per image: NaN\n")
        for i in range(num_images):
            if i % 1000 == 0:
                print("Writing point", i, "/", num_images)
            img = sorted_img_list[i]
            if i > 501:
                fid.write(f"{i+3} {img.quaternion[0]} {img.quaternion[1]} {img.quaternion[2]} {img.quaternion[3]} {img.translation[0]} {img.translation[1]} {img.translation[2]} 1 {img.name}\n\n")
            else:
                fid.write(f"{i+1} {img.quaternion[0]} {img.quaternion[1]} {img.quaternion[2]} {img.quaternion[3]} {img.translation[0]} {img.translation[1]} {img.translation[2]} 1 {img.name}\n\n")

            # fid.write(f"{i+1} {quaternion[i, 0]} {quaternion[i, 1]} {quaternion[i, 2]} {quaternion[i, 3]} {translation[i, 0]} {translation[i, 1]} {translation[i, 2]} 1 {name[i]}\n\n")
            # IMAGE_ID, QW, QX, QY, QZ, TX, TY, TZ, CAMERA_ID, NAME
            # 1 0.695104 0.718385 -0.024566 0.012285 -0.046895 0.005253 -0.199664 1 image0001.png
            # # Make sure every other line is left empty


if __name__ == "__main__":
    main()
