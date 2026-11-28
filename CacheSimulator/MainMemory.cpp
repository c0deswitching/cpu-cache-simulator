#include "MainMemory.h"
#include <array>
#include <iostream>
#include <format>
#include <string>

MainMemory::MainMemory() {
	// allocate memory region
	memory = std::make_unique<std::array<uint8_t, MAIN_MEMORY_SIZE>>();

	// fill main memory with zeroes
	memory.get()->fill(0x00);
}

MainMemory::~MainMemory() {

}

void MainMemory::Read(uint32_t startAddress, uint8_t size, uint8_t* destination) {
	// read the requested amomunt of memory and copy to destination
	std::memcpy(destination, &memory.get()->at(startAddress), size);

}

void MainMemory::Write(uint32_t startAddress, uint8_t size, uint8_t* source) {
	// copy the requested amount of memory from the source to main memory
	std::memcpy(&memory.get()->at(startAddress), source, size);
}

void MainMemory::Print() {
	// print a slice of the memory region (for debug)
	const uint32_t ROWS = 24;
	const uint8_t COLUMNS = 12;

	for (uint32_t row = 0; row < ROWS; row++) {
		for (uint32_t column = 0; column < COLUMNS; column++) {
			std::string value = std::format("0x{:x}\t", memory.get()->at(row * COLUMNS + column));

			std::cout << value;
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	for (uint32_t dash = 0; dash < 80; dash++) {
		std::cout << "-";
	}
	std::cout << std::endl;
}