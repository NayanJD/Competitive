CC = g++
CFLAGS = -std=c++20 -DDEBUG -Ofast -O2 -fsanitize=address -fsanitize=undefined -fno-omit-frame-pointer -g

Command := $(firstword $(MAKECMDGOALS))
Arguments := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))

buildnrun:
	$(CC) $(CFLAGS) $(Arguments) -o a.out && ./a.out && $(MAKE) clean

clean:
	rm a.out

brackets_to_braces:
	@echo $(INPUT) | sed 's/\[/{/g' | sed 's/\]/}/g'


