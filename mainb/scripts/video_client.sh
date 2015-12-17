#!/bin/sh
nc isfar.local 9999 | mplayer -fps 200 -demuxer h264es -
