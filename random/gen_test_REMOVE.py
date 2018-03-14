#!/usr/bin/python3

import hashlib, hmac
from flag_vars import charset, hashHex
from flag_test import test
import random
from time import localtime, mktime, ctime
import fileinput
import re
import os, stat

# use date, hour and minute to set seed, write to flag_vars right after getting time

def gen_rand(loops):
	retval = bytes(charset[random.randint(0, len(charset) - 1)], 'utf-8')
	for i in range(loops):
		retval = retval + bytes(charset[random.randint(0, len(charset) - 1)], 'utf-8')
	return retval

def time():
	t = os.stat("flag_vars.py")[stat.ST_MTIME]
	t = localtime(t)
	t = (tuple(t[:5] + (0,) + t[6:]))
	return mktime(t)


def main():
	seed = time()
	random.seed(seed)
	loops = random.randint(0, 250)

	loops = random.randint(0, 30)
	flag = 'flag{' + gen_rand(loops).decode('utf-8') + '}'

	h = hashlib.sha256(bytes(flag, 'utf-8'))
	
	myHex = h.hexdigest()

	if (test(flag)):
		print("Flag not generated properly")
		print("My hash: %s" % (myHex,))
		print("Actual: %s" % (hashHex,))
		exit(1)
	else:
		print("Flag generated properly")
		print(flag)
		print("Disabling write access to flag_vars")
		oldstat = os.stat("flag_vars.py")[stat.ST_MODE]
		os.chmod("flag_vars.py", oldstat & ~(stat.S_IWUSR | stat.S_IWGRP | stat.S_IWOTH))
		exit(0)
		


	exit(0)

if __name__ == '__main__':
	main()