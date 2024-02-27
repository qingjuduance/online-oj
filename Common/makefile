


#先将所有的文件编译成 .o 文件 再进行动态库的打包

common:FileUtil.o LogUtil.o Machine.o
	g++ -shared -o libCommon.so $^
	rm *.o

FileUtil.o:FileUtil.cpp
	g++ -fPIC -o $@ -c $^ -std=c++11
LogUtil.o:LogUtil.cpp
	g++ -fPIC -o $@ -c $^ -std=c++11
Machine.o:Machine.cpp
	g++ -fPIC -o $@ -c $^ -std=c++11


.PHONY:clean
clean:
	rm *.so