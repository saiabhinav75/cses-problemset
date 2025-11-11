# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -O2 -Wall

# Input file (passed as argument)
FILE ?=
FILENAME := $(basename $(notdir $(FILE)))
OUTDIR := outputs
OUTFILE := $(OUTDIR)/$(FILENAME).exe
TIMEOUT := 5

# ----------------------------------
# 🏗️ Build target
# ----------------------------------
$(OUTFILE): $(FILE)
	@mkdir -p $(OUTDIR)
	@echo "🔧 Compiling $(FILE)..."
	@$(CXX) $(CXXFLAGS) $(FILE) -o $(OUTFILE)
	@echo "✅ Build successful: $(OUTFILE)"

# ----------------------------------
# 🏃 Run target
# ----------------------------------
.PHONY: run
run: $(OUTFILE)
	@if [ -n "$$INPUT" ]; then \
		echo "🚀 Running with input: $$INPUT"; \
		echo "--------------------------------"; \
		./$(OUTFILE) < $$INPUT; \
		echo "\n--------------------------------"; \
	else \
		echo "🚀 Running program (no input file)..."; \
		echo "--------------------------------"; \
		./$(OUTFILE); \
		echo "\n--------------------------------"; \
	fi

# ----------------------------------
# 🧪 Test target (build once, run many)
# ----------------------------------
.PHONY: test
test: $(OUTFILE)
ifeq ($(FILE),)
	@echo "❌ Usage: make test FILE=path/to/source.cpp"
else
	@TESTDIR=tests/$(FILENAME); \
	if [ -d $$TESTDIR ]; then \
		for t in $$TESTDIR/*.txt; do \
			echo "--------------------------------"; \
			echo "📘 Running test: $$t"; \
			echo "--------------------------------"; \
			gtimeout $(TIMEOUT)s ./$(OUTFILE) < $$t || echo "⏱️  Timed out after $(TIMEOUT)s"; \
			echo "\n"; \
		done; \
	else \
		echo "⚠️ No tests found for $(FILENAME) (expected in tests/$(FILENAME)/)"; \
	fi
endif

# ----------------------------------
# 🧹 Clean target
# ----------------------------------
.PHONY: clean
clean:
	@echo "🧹 Cleaning outputs..."
	@rm -rf $(OUTDIR)
	@echo "✅ Done."
