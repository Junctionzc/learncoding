n =  10240099
b1 = chr((n & 0xff000000) >> 24)
b2 = chr((n & 0xff0000) >> 16)
b3 = chr((n & 0xff00) >> 8)
b4 = chr(n & 0xff)
s = b1 + b2 + b3 + b4
print s

import struct
print struct.pack('>I', 10240099)
print struct.unpack('>IH', '\xf0\xf0\xf0\xf0\x80\x80')