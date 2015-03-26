/**
 * @file	cyclic_buffer.c
 * @brief	A cyclic buffer is a data structure that uses a single, fixed-size buffer as if it were connected end-to-end.
 *
 * http://en.wikipedia.org/wiki/Circular_buffer
 *
 * @date Dec 8, 2013
 * @author Andrey Belomutskiy, Daniel Hill (c) 2012-2014
 * @author Daniel Hill - Modified to use C++ - Mar 2, 2014
 */

#include "cyclic_buffer.h"
#include <string.h>

cyclic_buffer::cyclic_buffer() {
  baseC(CB_MAX_SIZE);
}

cyclic_buffer::cyclic_buffer(int size) {
  baseC(size);
}

void cyclic_buffer::baseC(int size) {
	currentIndex = 0;
	setSize(size);
}

//cpctor
cyclic_buffer::cyclic_buffer(const cyclic_buffer& cb) {
	//Deep copy the data
	currentIndex = cb.currentIndex;
	count = cb.count;
	size = cb.size;
	for (int i = 0; i < size; ++i) {
		elements[i] = cb.elements[i];
	}
}

//dtor
cyclic_buffer::~cyclic_buffer() {
	//No dynamic allocation - safe to leave
}

//overloaded =operator
cyclic_buffer& cyclic_buffer::operator=(const cyclic_buffer& rhCb) {
	//Deep copy
	currentIndex = rhCb.currentIndex;
	count = rhCb.count;
	for (int i = 0; i < size; ++i) {
		elements[i] = rhCb.elements[i];
	}
	return *this;
}

void cyclic_buffer::add(int value) {
	++currentIndex;
	if (currentIndex == size) {
		currentIndex = 0;
	}
	elements[currentIndex] = value;

	++count;
}

void cyclic_buffer::setSize(int size) {
	clear();
	this->size = size;
}

void cyclic_buffer::clear() {
	memset((void*) elements, 0, sizeof(elements)); // I would usually use static_cast, but due to the elements being volatile we cannot.
	count = 0;
	count = 0;
}

int cyclic_buffer::sum(int length) {
	if (length > count) {
		length = count;
	}

	int ci = currentIndex; // local copy to increase thread-safety
	int result = 0;

	for (int i = 0; i < length; ++i) {
		int index = ci - i;
		while (index < 0) {
			index += size;
		}

		result += elements[index];
	}

	return result;
}

