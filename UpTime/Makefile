#
# Compling & Linking App and test code
#

all: uptime uptime_test file

uptime: util.o uptime.o
	@echo "Linking App ...";
	g++ -o bin\uptime.exe build\uptime.o build\util.o

uptime.o: 
	@echo "Compiling App ...";
	g++ -o build\uptime.o -c src\UpTime.cpp

util.o: 
	@echo "Compiling Util ...";
	g++ -o build\util.o -c src\Util.cpp

uptime_test: uptime_test.o util.o
	@echo "Linking test ...";
	g++ -o bin\uptime_test.exe  build\uptime_test.o build\util.o

uptime_test.o: 
	@echo "Compiling test ...";
	g++ -o build\uptime_test.o -c test\UpTimeUnitTest.cpp

file :
	xcopy data bin\data /I

#
# Run static analysis, test code and code
#

run : static_analysis test_code code 

code :
	@echo "Running code ...";
	.\bin\uptime.exe

static_analysis :
	@echo "Running static analysis ...";
	cppcheck --enable=all --suppress=missingIncludeSystem src/*.cpp

test_code :
	@echo "Running test ...";
	.\bin\uptime_test.exe

#
# Clean executable .exe and object .out files from bin and build folder
#

cleanall: clean_bin clean_file clean_build
	
clean_bin : 
	@echo " Cleaning bin ...";
	rm -rf bin/*.exe
	
clean_file :
	rm -rf bin/data/* 
	rm -rf "bin\data"


clean_build :
	@echo " Cleaning build ...";
	rm -rf build/*.o

