ifeq ($(strip $(DIR)), )
$(error DIR is not set)
endif

CC = gcc
CFLAGS = -Wall -Wextra -g
SRCDIR = $(DIR)
UTILDIR = _Utilities
BINDIR = bin
OBJDIR = obj

# List of all utility directories
UTILDIRS := $(wildcard $(UTILDIR)/*)

# Collect all utility source files
UTILSOURCES := $(foreach dir,$(UTILDIRS),$(wildcard $(dir)/main.c))

# Since all the source files have the same name, we need to use the directory name as the object name
UTILOBJS := $(patsubst $(UTILDIR)/%/main.c,$(OBJDIR)/%.o,$(UTILSOURCES))

# List of all App source files
MAINSOURCES = $(wildcard $(SRCDIR)/*.c)
MAINOBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(MAINSOURCES))

# Executable name
EXECUTABLE = $(BINDIR)/main

all: clean $(EXECUTABLE)

$(EXECUTABLE): $(UTILOBJS) $(MAINOBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@

$(UTILOBJS): $(OBJDIR)/%.o: $(UTILDIR)/%/main.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(MAINOBJS): $(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean
