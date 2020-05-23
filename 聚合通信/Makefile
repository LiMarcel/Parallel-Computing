MP = mpicxx
FLAG = -g
cpi: cpi.cpp
	$(MP) $(FLAG) -o $@.o $<
gather: gather.cpp
	$(MP) $(FLAG) -o $@.o $<
gatherv: gatherv.cpp
	$(MP) $(FLAG) -o $@.o $<
reduce: reduce.cpp
	$(MP) $(FLAG) -o $@.o $<
scan: scan.cpp
	$(MP) $(FLAG) -o $@.o $<
.PHONY: clean
clean: 
	rm -f *.o
