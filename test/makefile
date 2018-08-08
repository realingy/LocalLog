#生成logfile.o
#g++ -c logfile.cpp

#生成logger.o
#g++ -c logger.cpp

#生成logger.o
#g++ -c log.cpp

cc = g++
app = log
source = main.cpp
obj = main.o logger.o logfile.o logrealize.o logstream.o logtime.o

$(app) : $(obj) 
	$(cc) -o $(app) $(obj)

%.o : %.c
	$(cc) -c $< -o $@

clean:
	rm -rf *.o
	rm -rf $(app)



#main.o : $(source)
#	$(cc) -c $(source)

#生成各个模块的目标文件
#logger.o : logger.cpp
#	$(cc) -c logger.cpp

#logfile.o : logfile.cpp
#	$(cc) -c logfile.cpp

#logrealize.o : logrealize.cpp
#	$(cc) -c logrealize.cpp

#logstream.o : logstream.cpp
#	$(cc) -c logstream.cpp

#logtime.o : logtime.cpp
#	$(cc) -c logtime.cpp

#生成可执行文件
#$(app) : $(source)
#	$(cc) $(source) -lmylog -o $(app)
#
#$(app) : $(source) logger.o logfile.o logrealize.o logstream.o logtime.o
#	$(cc) $(source) logger.o logfile.o logrealize.o logstream.o logtime.o -o $(app)

