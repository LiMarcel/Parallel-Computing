MP = mpicxx
FLAG = -g
hello: hello.cpp
	$(MP) $(FLAG) -o $@.o $<
sendrecv: sendrecv.cpp
	$(MP) $(FLAG) -o $@.o $<
rank: rank.cpp
	$(MP) $(FLAG) -o $@.o $<
wtime: wtime.cpp
	$(MP) $(FLAG) -o $@.o $<
tag: tag.cpp
	$(MP) $(FLAG) -o $@.o $<
tag_1: tag_1.cpp
	$(MP) $(FLAG) -o $@.o $<


.PHONY: clean
clean: rm -f *.o
