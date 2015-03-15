#!/usr/bin/python2
import sys
import cv2
import numpy as np
import matplotlib.pyplot as plt

pattern_size = (9, 6)
#pattern_size = (8, 5)
corners = np.array(())
object_points = []
image_points = []
image_count = 0

pattern_points = np.zeros( (np.prod(pattern_size), 3), np.float32 )
pattern_points[:,:2] = np.indices(pattern_size).T.reshape(-1, 2)
pattern_points *= 15
chessboard_ready = False

for f in sys.argv[1:]:
    img = cv2.imread(f, 1);
    h, w, ch = img.shape;
    r, corners = cv2.findChessboardCorners(img, pattern_size, corners, cv2.CALIB_CB_ADAPTIVE_THRESH + cv2.CALIB_CB_NORMALIZE_IMAGE)
    if r:
        cv2.cornerSubPix(cv2.cvtColor(img, cv2.COLOR_BGR2GRAY), corners, (5, 5), (-1, -1), (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_COUNT, 30, 0.1) )
	print "#", f
	for i in corners:
            print i[0][0], "\t", i[0, 1];
    else:
        print "No corners found\n"
