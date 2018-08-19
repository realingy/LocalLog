include ../build_config.mk

CFLAGS += -I../output/include
CLIBS += ../output/liblocallog.a

all : $(OBJS)
	$(CXX) -o numtest.out $(CFLAGS) numtest.cpp $(CLIBS)

clean:
	rm -rf *.o *.a *.out
