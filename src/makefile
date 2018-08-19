include ../build_config.mk

CFLAGS += 
OBJS = logger.o logfile.o logrealize.o logstream.o logtime.o
LIB = liblocallog.a
HEADER = logger.h logstream.h logcommon.h

all : $(OBJS) 
	mkdir -p $(HEADER_OUTPUT_DIR)
	ar -cru $(OUTPUT_DIR)/$(LIB) ${OBJS}
	#外部接口头文件
	cp $(HEADER) $(HEADER_OUTPUT_DIR)

.cpp.o:
	$(CXX) ${CFLAGS} -c $< -o $@

clean:
	rm -rf *.o $(OUTPUT_DIR)/$(LIB) $(HEADER_OUTPUT_DIR)

