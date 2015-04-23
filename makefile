CXX=g++
RM=rm -f
CPPFLAGS=-pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy \
    -Wdisabled-optimization -Wformat=2 -Winit-self -Wmissing-declarations \
    -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual \
    -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo \
    -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused

SRCS=test.cpp logprobs.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: test

test: $(OBJS)
	    $(CXX) -o test $(OBJS)

test.o: test.cpp

logprobs.o: logprobs.hpp logprobs.cpp

clean:
	    $(RM) $(OBJS)

dist-clean: clean
	    $(RM) test
