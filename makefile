# CXX = g++
# CXXFLAGS = -std=c++17 -I/opt/homebrew/include
# LDFLAGS = -L/opt/homebrew/lib -lczmq -lzmq

# CLIENT_SRC = client.cpp
# SERVER_SRC = server.cpp

# CLIENT_OUT = outputs/client.exe
# SERVER_OUT = outputs/server.exe

# all: $(CLIENT_OUT) $(SERVER_OUT)

# $(CLIENT_OUT): $(CLIENT_SRC)
# 	$(CXX) $(CXXFLAGS) $< $(LDFLAGS) -o $@

# $(SERVER_OUT): $(SERVER_SRC)
# 	$(CXX) $(CXXFLAGS) $< $(LDFLAGS) -o $@

# clean:
# 	rm -f outputs/*.exe
