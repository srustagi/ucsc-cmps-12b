def octal(n):
	while(n>0):
		if(n/8>0):
			octal(n/8)
		print(n%8)

octal(100)