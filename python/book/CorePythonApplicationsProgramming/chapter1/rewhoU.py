#!/usr/bin/env python

import os
from distutils.log import warn as printf
import re

f = os.popen('who', 'r')
for eachLine in f:
    printf(re.split(r'\s\s+|\t', eachLine.rstrip()))
f.close()