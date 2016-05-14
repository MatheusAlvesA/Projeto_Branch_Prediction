All:
	@echo "Compilando..."
	@g++ -Wall -std=c++11 src/main.cpp -I include -o bin/binario
clean:
	@echo "Limpando..."
	@rm -f bin/binario
