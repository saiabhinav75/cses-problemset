# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall

# Input file (passed as argument)
FILE ?=
# Extract filename without path and extension
FILENAME := $(basename $(notdir $(FILE)))
# Output directory and file
OUTDIR := outputs
OUTFILE := $(OUTDIR)/$(FILENAME).exe

# Default target
.PHONY: run
run:
ifeq ($(FILE),)
	@echo "❌ Usage: make run FILE=path/to/source.cpp"
else
	@echo "🔧 Compiling $(FILE)..."
	@$(CXX) $(CXXFLAGS) $(FILE) -o $(OUTFILE)
	@if [ $$? -eq 0 ]; then \
		echo "✅ Build successful: $(OUTFILE)"; \
		echo "🚀 Running program..."; \
		echo "--------------------------------"; \
		./$(OUTFILE); \
		echo "\n--------------------------------"; \
	else \
		echo "❌ Compilation failed."; \
	fi
endif

# Clean up build files
.PHONY: clean
clean:
	@echo "🧹 Cleaning outputs..."
	@rm -rf $(OUTDIR)
	@echo "✅ Done."
