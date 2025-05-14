CXX = clang++
CXXFLAGS = -g -std=c++17 -stdlib=libc++

SRCS = Source\ Files/Main.cpp \
        Source\ Files/DataLoader.cpp \
        Source\ Files/WorkshopList.cpp \
        Source\ Files/ParticipantList.cpp

TARGET = Main

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET) 