SERVO:
the default i2c address is 0x0a, the angle reg is 0x01, the board is connected to i2c1 so

 .. code:: bash

 i2cset -y 1 0x0a 0x01 <angle>
