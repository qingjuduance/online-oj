common:oj_server

oj_server:oj_server.cpp Control.cpp Model.cpp View.cpp
	g++ -o $@ $^ -L../Common -L../jsoncpp-master/build/debug/lib -ljsoncpp  -lCommon -lpthread -lctemplate -std=c++11




.PHONY:clean
clean:
	rm -rf oj_server