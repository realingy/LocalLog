$(shell sh build.sh 1>&2)
include build_config.mk

all:
	cd src; make
	cd test; make

clean:
	cd src; make clean
	cd test; make clean
	rm -rf *.o a.out

#all : 
#	cd src; make
#	cd test; make

#cc = g++
#app = log
#source = main.cpp
#obj = main.o logger.o logfile.o logrealize.o logstream.o logtime.o

#$(app) : $(obj) 
#	$(cc) -o $(app) $(obj)

#%.o : %.c
#	$(cc) -c $< -o $@

#clean:
#	rm -rf $(obj) $(app)


