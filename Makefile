all:
	gcc MarkCalc.c -o MarkCalc -fno-stack-protector
	strip MarkCalc
