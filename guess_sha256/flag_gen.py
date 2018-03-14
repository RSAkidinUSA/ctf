#!/usr/bin/python3
# This code is used to generate the hmac of the flag for the ctf competition

import hashlib, hmac
import sys
import fileinput
import re

from flag_vars import charset, flaglen

def check_valid(flag):
	valid = True
	# Check formatting of flag
	for i in range(len('flag{')):
		if flag[i] != 'flag{'[i]:
			valid = False
	if (flag[len(flag) - 1] != '}'):
		valid = False
	if (not valid):
		print('(Flag should be in format \'flag{something}\')')
		exit(2)

	# Check flag is valid len and charset
	thislen = (len(flag) - 1) - len('flag{')
	if (thislen != flaglen):
		valid = False
	for i in range(len('flag{'), len('flag{') + thislen):
		if flag[i] not in charset:
			valid = False
	if (not valid):
		print('Flag must be %d characters long, and must only contain characters from:\n%s' \
				% (flaglen, charset))
		exit(3)

def main():
	if (len(sys.argv) < 2):
		print('Usage: %s <flag>' % (sys.argv[0],))
		exit(1)
	flag = sys.argv[1]
	check_valid(flag)

	h = hashlib.sha256(bytes(flag, 'utf-8'))
	hashHex = h.hexdigest()

	# Replace only hashHex in flag_vars.py
	for line in fileinput.input('flag_vars.py', inplace=1):
		# hexdigest only has values between a-z and 0-9
		line = re.sub('hashHex = \'[0-9a-z]*\'', 'hashHex = \'' + str(hashHex) + '\'', line)
		print(line.rstrip())


	print('flag: %s' % (flag,))
	print('hmac: %s' % (hashHex,))



if __name__ == '__main__':
	main()