

CC= g++
CFLAGS= -g3 -Wall -Werror -Wextra
LDFLAGS=
LDLIBS=

OBJS = ${TARGET_OBJS}
OBJS ?= main.cpp
SUBDIRS = $(shell find . -maxdepth 1 -type dir)

TARGET=test


all : $(TARGET)

clean :
	@rm -f *.o

fclean :
	@make clean
	@rm -f $(TARGET)
	@rm -rf test.dSYM

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS) -std=c++11 -O2

re : 
	make fclean
	make all

dirClean : 
	@for dir in $(SUBDIRS); do \
        $(MAKE) -C $$dir fclean; \
     done

.PHONY: fclean clean re all dirClean
