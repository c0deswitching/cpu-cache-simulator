#pragma once
#include <memory>

const uint32_t MAIN_MEMORY_SIZE = 4 * 1024 * 1024; // 4mb main memory

class MainMemory {
public:
private:
	std::unique_ptr<std::array<uint32_t, MAIN_MEMORY_SIZE>> memory;
};

