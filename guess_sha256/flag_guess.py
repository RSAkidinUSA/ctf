#!/usr/bin/python3
# This script is used to generate random guess from the charset and check
# if they are the flag of the ctf competition

import random
from flag_vars import charset, flaglen
from flag_test import test


def gen_guess():
	guess = ''
	for i in range(flaglen):
		c = charset[random.randint(0, len(charset) - 1)]
		guess = guess + c
	return guess

def main():
	while True:
		guess = 'flag{' + gen_guess() + '}'
		retval = test(guess)
		print('%s%s is %sthe correct flag!' % ('Sorry, ' if retval else '',
											'\'' + guess + '\'',
											'not ' if retval else ''))
		if (not retval):
			exit(0)



if __name__ == '__main__':
	main()