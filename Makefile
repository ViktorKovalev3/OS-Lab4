build: main1.cpp main2.cpp
	mkdir -p Build
	gcc -lpthread -o ./Build/main1 main1.cpp 
	gcc -lpthread -o ./Build/main2 main2.cpp
clean:
	rm -rf Build
run: build
	rm Build/SharedFile.txt
	gnome-terminal -e "./Build/main1"&               
	gnome-terminal -e "./Build/main2"&              
