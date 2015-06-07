/*
 * token.h
 *
 *  Created on: 2015. 6. 5.
 *      Author: 근홍
 */

#ifndef INCLUDE_TOKEN_H_
#define INCLUDE_TOKEN_H_

#include <string>

enum Token
{
	WITH_BATCHIM = 65536,
	WITHOUT_BATCHIM,
	INCOMPLETE_CHOSUNG,
	FLUSH,
	END_OF_FILE,
};

enum BufferType
{
	CHOSUNG=0,
	JUNGSUNG,
	JONGSUNG1,
	JONGSUNG2,
	BUFFER_TYPE_SIZE,
};

extern std::string buffer[BUFFER_TYPE_SIZE];

void fill_buffer(int pos, const std::string& in);
void flush_buffer();
void print_buffer();
std::string borrow_one();
void add_string(const std::string& str);

#endif /* INCLUDE_TOKEN_H_ */
