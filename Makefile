src_dir := src
include_dir := include
obj_dir := obj
depend_dir := depend

program := bin/labyrinth
source_files := $(wildcard $(src_dir)/*.cpp)
#same as object_files := $(source_files:%.c=%.o)
object_files := $(patsubst  $(src_dir)/%.cpp, $(obj_dir)/%.o, $(source_files))
depend_files := $(patsubst  $(src_dir)/%.cpp, $(depend_dir)/%.d, $(source_files))

CC := g++
DFLAG := -MM 
IFLAG := $(addprefix -I, $(include_dir))
# -Q - shows every function that was compiled, and after tells how much time was spend to compile programm
#  # -Wconversion - shows warnings when code has implicit type conversion
# -Wold-style-cast - shows warnings when there is old C-style type conversion or implicit
#  # -Wshadow - shows warnings when local variable blocks global variable or another local variable
CFLAGS := -Wall -Werror -Wshadow -Wold-style-cast -pedantic-errors -ggdb 
LIBS := -lGL -lglut -lGLU

all: $(program)

$(program): $(object_files)
	$(CC) $(CFLAGS) $(LIBS) $(object_files) -o $@

$(obj_dir)/%.o: $(src_dir)/%.cpp
	$(CC) $(DFLAG) $(IFLAG) -MT $@ $< -o $(patsubst $(src_dir)/%.cpp, $(depend_dir)/%.d, $<)
	$(CC) -c $(CFLAGS) $(IFLAG) $< -o $@

.PHONY: clean
clean:
	rm -rf $(object_files) $(depend_files) $(program)

include $(wildcard $(depend_dir)/*.d)

