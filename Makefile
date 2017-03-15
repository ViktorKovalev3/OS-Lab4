build: main1.cpp main2.cpp
	mkdir -p Build
	gcc -o ./Build/main1 main1.cpp -lpthread
	gcc -o ./Build/main2 main2.cpp -lpthread
clean:
	rm -rf Build
run: build
	rm Build/SharedFile.txt
	gnome-terminal -e "./Build/main1"&               
	gnome-terminal -e "./Build/main2"&              
