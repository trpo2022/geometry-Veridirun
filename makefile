APP_NAME = geometry
LIB_NAME = libgeometry
TEST_NAME = geometry_test

CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I src -MP -MMD
LDFLAGS =
LDLIBS = -lm
TEST_CPPFLAGS = -I thirdparty -MP -MMD

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
TEST_DIR = test

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a
TEST_PATH = $(BIN_DIR)/$(TEST_NAME)

SRC_EXT = cpp
CC = g++

APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.$(SRC_EXT)')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.$(SRC_EXT)')
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d) $(TEST_OBJECTS)

.PHONY: all
all: $(APP_PATH)

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ $(LDFLAGS) $(LDLIBS)

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

.PHONY: clean
clean:
	$(RM) $(APP_PATH) $(LIB_PATH)
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' \;

.PHONY: test
test: $(TEST_PATH)

$(TEST_PATH): obj/test/main.o obj/test/test.o obj/src/libgeometry/libgeometry.a
	$(CC) $(CFLAGS) -o $@ $^

obj/test/test.o: test/test.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $(TEST_CPPFLAGS) $< -o $@

obj/test/main.o: test/main.cpp
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $(TEST_CPPFLAGS) $< -o $@
