TARGET = brightness.exe
OUT_DIR = out

CXX = g++

CXXFLAGS = -std=c++20 -O3 -mavx2 -Wall -Wextra -std=c++17

SRCS = $(wildcard *.cpp)
OBJS = $(addprefix $(OUT_DIR)/,$(SRCS:.cpp=.o))

all: $(TARGET)

$(OUT_DIR):
	mkdir -p $@

$(TARGET): $(OUT_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

$(OUT_DIR)/%.o: %.cpp | $(OUT_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OUT_DIR) $(TARGET)

.PHONY: all clean