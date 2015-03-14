all: write.exe read.exe

write.exe:
	g++ -I include/ -DNULL=0 src/* ExifTester.cpp -o write

read.exe:
	g++ -I include/ -DNULL=0 src/* example1.cpp -o read
	
clean:
	rm write.exe read.exe