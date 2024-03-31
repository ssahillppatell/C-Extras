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

# Convert utility source filenames to object filenames
UTILOBJS := $(patsubst %.c,$(OBJDIR)/%.o,$(notdir $(UTILSOURCES)))

# List of all App source files
MAINSOURCES = $(wildcard $(SRCDIR)/main.c)
MAINOBJS = $(patsubst %.c,$(OBJDIR)/%.o,$(notdir $(MAINSOURCES)))

# Executable name
EXECUTABLE = $(BINDIR)/main

all: $(EXECUTABLE)

$(EXECUTABLE): $(UTILOBJS) $(MAINOBJS)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) $^ -o $@

$(UTILOBJS): $(OBJDIR)/%.o: $(UTILDIRS)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(MAINOBJS): $(OBJDIR)/%.o: $(SRCDIR)/%.c $(UTILOBJS)
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean
