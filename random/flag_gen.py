#!/usr/bin/python3

import hashlib, hmac
from flag_vars import charset
import random
from time import localtime, mktime, ctime
import fileinput
import re

# use date, hour and minute to set seed, write to flag_vars right after getting time

def gen_rand(loops):
	retval = bytes(charset[random.randint(0, len(charset) - 1)], 'utf-8')
	for i in range(loops):
		retval = retval + bytes(charset[random.randint(0, len(charset) - 1)], 'utf-8')
	return retval

def time():
	t = localtime()
	t = (tuple(t[:5] + (0,) + t[6:]))
	return mktime(t)


def main():
	seed = time()
	random.seed(seed)
	loops = random.randint(0, 250)

	loops = random.randint(0, 30)
	flag = 'flag{' + gen_rand(loops).decode('utf-8') + '}'

	h = hashlib.sha256(bytes(flag, 'utf-8'))
	
	hashHex = h.hexdigest()
	
	# Replace only hashHex in flag_vars.py
	for line in fileinput.input('flag_vars.py', inplace=1):
		# hexdigest only has values between a-z and 0-9
		line = re.sub('hashHex = \'[0-9a-z]*\'', 'hashHex = \'' + str(hashHex) + '\'', line)
		print(line.rstrip())

	print("Flag: %s" % (flag,))
	print("Hex Hash: %s" % (hashHex,))
	print("Seed: %s" % (ctime(seed),))


	exit(0)

if __name__ == '__main__':
	main()