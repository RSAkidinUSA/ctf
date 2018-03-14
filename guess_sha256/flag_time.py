#!/usr/bin/python3
# This script is used to calculate the max time to guess the flag 
# given the charset and length on the given machine

import random
import time
from flag_vars import charset, flaglen
from flag_guess import gen_guess
from flag_test import test

def main():
	random.seed(time.time())
	
	start = time.time()
	for i in range(10000):
		guess = gen_guess()
		test('flag{' + guess + '}')
	stop = time.time()
	print('Time to generate 10000 guesses: %s' % (stop - start,))
	hps = 10000 / (stop - start)
	print('Hashes per sec: %s' % (hps,))
	total = pow(len(charset), flaglen)
	print('Hours to calculate all guesses: %s' % ((total / hps) / 3600,))


if __name__ == '__main__':
	main()