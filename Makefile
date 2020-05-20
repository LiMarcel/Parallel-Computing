MP = mpicxx
FLAG = -g
hello: hello.cpp
	$(MP) $(FLAG) -o $@ $<
