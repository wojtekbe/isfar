OpenCV example of reading a stream from *fifo*
=================================================

on client side:
---------------
mkfifo fifo
nc -l -p 5001 > fifo
./readfifo

on host (R-Pi):
---------------
raspivid -t 999999 -o - | nc [client IP] 5001	
