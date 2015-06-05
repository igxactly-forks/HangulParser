/*
 * token.cpp
 *
 *  Created on: 2015. 6. 6.
 *      Author: 근홍
 */


#include "token.h"
#include <cstdint>
#include <vector>
#include <cassert>
#include <iostream>

std::wstring buffer[BUFFER_TYPE_SIZE];

static const uint32_t HANGUL_BASE = 44032;
static const uint32_t CHOSUNG_BASE = 588;
static const uint32_t JUNGSUNG_BASE = 28;

// 초성 리스트. 00 ~ 18
static std::vector<std::wstring> CHOSUNG_LIST = {
		L"ㄱ", L"ㄲ", L"ㄴ", L"ㄷ", L"ㄸ", L"ㄹ", L"ㅁ", L"ㅂ", L"ㅃ",
		L"ㅅ", L"ㅆ", L"ㅇ" , L"ㅈ", L"ㅉ", L"ㅊ", L"ㅋ", L"ㅌ", L"ㅍ", L"ㅎ"
};

// 중성 리스트. 00 ~ 20
static std::vector<std::wstring> JUNGSUNG_LIST = {
		L"ㅏ", L"ㅐ", L"ㅑ", L"ㅒ", L"ㅓ", L"ㅔ",
		L"ㅕ", L"ㅖ", L"ㅗ", L"ㅘ", L"ㅙ", L"ㅚ",
		L"ㅛ", L"ㅜ", L"ㅝ", L"ㅞ", L"ㅟ", L"ㅠ",
		L"ㅡ", L"ㅢ", L"ㅣ"
};

// 종성 리스트. 00 ~ 27 + 1(1개 없음)
static std::vector<std::wstring> JONGSUNG_LIST = {
		L"", L"ㄱ", L"ㄲ", L"ㄱㅅ", L"ㄴ", L"ㄴㅈ", L"ㄴㅎ", L"ㄷ",
		L"ㄹ", L"ㄹㄱ", L"ㄹㅁ", L"ㄹㅂ", L"ㄹㅅ", L"ㄹㅌ", L"ㄹㅍ", L"ㄹㅎ",
		L"ㅁ", L"ㅂ", L"ㅂㅅ", L"ㅅ", L"ㅆ", L"ㅇ", L"ㅈ", L"ㅊ",
		L"ㅋ", L"ㅌ", L"ㅍ", L"ㅎ"
};

static int get_index(const std::vector<std::wstring>& list, const std::wstring& target)
{
	for(size_t k=0; k<list.size(); k++)
	{
		if(target.compare(list[k]) == 0)
			return k;
	}
	return -1;
}

void fill_buffer(int pos, const std::wstring& in)
{
	std::wcout<<in<<std::endl;
	buffer[pos] = in;
}
void flush_buffer()
{
	uint32_t sum = HANGUL_BASE;
	int ret = get_index(CHOSUNG_LIST, buffer[0]);
	assert(ret >= 0);
	sum += CHOSUNG_BASE*ret;

	assert(buffer[1].length() > 0);
	ret = get_index(JUNGSUNG_LIST, buffer[1]);
	assert(ret >= 0);
	sum += JUNGSUNG_BASE*ret;

	std::wstring concat = buffer[2].append(buffer[3]);
	ret = get_index(JONGSUNG_LIST, concat);
	assert(ret >= 0);
	sum += ret;

	char32_t current = (char32_t)sum;
	std::wcout <<L"Char: "<<(wchar_t)current<<std::endl;

	buffer[0] = L"";
	buffer[1] = L"";
	buffer[2] = L"";
	buffer[3] = L"";
}
std::wstring borrow_one()
{
	assert(buffer[2].length() > 0);
	std::wstring ret;
	if(buffer[3].length() == 0)
	{
		ret = buffer[2];
		buffer[2] = L"";
	}
	else
	{
		ret = buffer[3];
		buffer[3] = L"";
	}
	return ret;
}

void add_space()
{
	std::wcout<<L"Char: < >"<<std::endl;
}
