default: solar_system

solar_system: solar_system.cpp */*.cpp include/*/*.hpp
	g++ -std=c++17 -o solar_system -Iinclude *.cpp */*.cpp

solar_system.dbg: solar_system.cpp */*.cpp include/*/*.hpp
	g++ -std=c++17 -g -O0 -o solar_system.dbg -Iinclude *.cpp */*.cpp

.PHONY: clean
clean:
	rm -f solar_system solar_system.dbg
