ROOT_DIR=$(CURDIR)
CXXFLAGS+= -std=c++11 -g -O0 -Wall
CFLAGS+= -g -O0

INCLUDE_DIR=$(ROOT_DIR)/include

INCLUDES+= -I$(ROOT_DIR)/grammar -I$(INCLUDE_DIR)

CXXFLAGS+= $(INCLUDES)
CFLAGS+= $(INCLUDES)

BUILD_DIR=build
PROGRAM=hangul
DEPS=.make.dep

all: $(DEPS) $(BUILD_DIR)/$(PROGRAM)

include grammar/Makefile
include src/Makefile

OBJS= $(SRCS:.cpp=.o)
C_OBJS= $(C_SRCS:.c=.o)

CLEAN_FILE+= $(OBJS) $(C_OBJS) $(BUILD_DIR)/$(PROGRAM) $(DEPS)

clean:
	rm -rf $(CLEAN_FILE)

depend: $(DEPS)

$(DEPS): $(SRCS) $(C_SRCS) $(HEADERS)
	@$(CXX) $(CXXFLAGS) -MM $(SRCS) > $(DEPS);
	@#$(CC) $(CFLAGS) -MM $(C_SRCS) >> $(DEPS);

$(BUILD_DIR)/$(PROGRAM): $(OBJS) $(C_OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(C_OBJS) -o $@ $(LIBS)

include $(DEPS)

.PHONY: all clean depend
