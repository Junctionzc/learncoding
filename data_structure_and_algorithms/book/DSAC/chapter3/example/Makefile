CROSS_COMPILE =

CXX = $(CROSS_COMPILE)gcc

INCLUDE_PATH += 

LDFLAGS += 

SRC_FILES := list.c \
             test.c

LINK := 

APP := test

$(APP):$(SRC_FILES)
	$(CXX) $(LDFLAGS) $(INCLUDE_PATH) $(SRC_FILES) -o $(APP) $(LINK)

clean:
	rm $(APP)
