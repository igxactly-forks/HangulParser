/*
 * token.cpp
 *
 *  Created on: 2015. 6. 6.
 *      Author: 근홍
 */


#include "token.h"
#include "hangul.hpp"
#include <cstdint>
#include <vector>
#include <cassert>
#include <iostream>

std::string buffer[BUFFER_TYPE_SIZE];

//static const uint32_t HANGUL_BASE = 44032;
static const uint32_t CHOSUNG_BASE = 588;
static const uint32_t JUNGSUNG_BASE = 28;

// 초성 리스트. 00 ~ 18
static std::vector<std::string> CHOSUNG_LIST = {
		"ㄱ", "ㄲ", "ㄴ", "ㄷ", "ㄸ", "ㄹ", "ㅁ", "ㅂ", "ㅃ",
		"ㅅ", "ㅆ", "ㅇ" , "ㅈ", "ㅉ", "ㅊ", "ㅋ", "ㅌ", "ㅍ", "ㅎ"
};

// 중성 리스트. 00 ~ 20
static std::vector<std::string> JUNGSUNG_LIST = {
		"ㅏ", "ㅐ", "ㅑ", "ㅒ", "ㅓ", "ㅔ",
		"ㅕ", "ㅖ", "ㅗ", "ㅘ", "ㅙ", "ㅚ",
		"ㅛ", "ㅜ", "ㅝ", "ㅞ", "ㅟ", "ㅠ",
		"ㅡ", "ㅢ", "ㅣ"
};

// 종성 리스트. 00 ~ 27 + 1(1개 없음)
static std::vector<std::string> JONGSUNG_LIST = {
		"", "ㄱ", "ㄲ", "ㄱㅅ", "ㄴ", "ㄴㅈ", "ㄴㅎ", "ㄷ",
		"ㄹ", "ㄹㄱ", "ㄹㅁ", "ㄹㅂ", "ㄹㅅ", "ㄹㅌ", "ㄹㅍ", "ㄹㅎ",
		"ㅁ", "ㅂ", "ㅂㅅ", "ㅅ", "ㅆ", "ㅇ", "ㅈ", "ㅊ",
		"ㅋ", "ㅌ", "ㅍ", "ㅎ"
};

static int get_index(const std::vector<std::string>& list, const std::string& target)
{
	for(size_t k=0; k<list.size(); k++)
	{
		if(target.compare(list[k]) == 0)
			return k;
	}
	return -1;
}

void fill_buffer(int pos, const std::string& in)
{
	std::cout<<in<<"["<<pos<<"]"<<std::endl;
	buffer[pos] = in;
}
void flush_buffer()
{
	uint32_t sum = 0;
	int ret = get_index(CHOSUNG_LIST, buffer[0]);
	assert(ret >= 0);
	sum += CHOSUNG_BASE*ret;

	assert(buffer[1].length() > 0);
	ret = get_index(JUNGSUNG_LIST, buffer[1]);
	assert(ret >= 0);
	sum += JUNGSUNG_BASE*ret;

	std::string concat = buffer[2].append(buffer[3]);
	ret = get_index(JONGSUNG_LIST, concat);
	assert(ret >= 0);
	sum += ret;

	std::cout <<"Char: "<<all_hangul[sum]<<std::endl;

	buffer[0] = "";
	buffer[1] = "";
	buffer[2] = "";
	buffer[3] = "";
}
std::string borrow_one()
{
	assert(buffer[2].length() > 0);
	std::string ret;
	if(buffer[3].length() == 0)
	{
		ret = buffer[2];
		buffer[2] = "";
	}
	else
	{
		ret = buffer[3];
		buffer[3] = "";
	}
	return ret;
}

void add_space()
{
	std::cout<<"Char: < >"<<std::endl;
}
