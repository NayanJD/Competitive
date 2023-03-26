CC = g++
CFLAGS = -std=gnu++17 -O2 -fsanitize=address -fno-omit-frame-pointer

buildnrun:
	$(CC) $(CFLAGS) $(FILENAME) -o a.out && ./a.out && $(MAKE) clean

clean:
	rm a.out
