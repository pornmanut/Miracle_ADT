$(CC)=gcc


%.run : %
	./%

%: %.o
	$(CC) -o $@ $<
%.o: %.c
	$(CC) -o -c $@ $<


