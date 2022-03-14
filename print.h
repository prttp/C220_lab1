#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <algorithm>


enum class COLORS { red, green, blue };
inline std::ostream& operator<<(std::ostream& os, const std::set<std::string>& s) {
	for (std::string i : s) {
		os << i << ", ";
	}
	
	return os;
}
template<typename C>
void PrintAnyCont(const C& s) {
	for (const auto& i : s) {
		std::cout << i << ", ";
	}
	std::cout << std::endl;
}
template<typename C>
void NegateAll(C& s) {
	for (auto& i : s) {
		//if (typeid(*i) == typeid(std::string)) { transform(i.begin(), i.end(), i.begin(), [](unsigned char c) -> unsigned char { if (c < 'a') { return std::toupper(c); } else { return std::tolower(c); } }); }
		//else {
		//	i = 0 - i;
		//}
		i = - i;
	}
}

inline std::string operator-(std::string& i) {
	transform(i.begin(), i.end(), i.begin(), [](unsigned char c) -> unsigned char { if (c < 'a') { return std::tolower(c); } else { return std::toupper(c); } });
	return i;
	
}
template<typename C>
void absSort(C& s) {
	std::sort(std::begin(s), std::end(s), [](const auto& s1, const auto& s2) {return (s1 < 0 ? -s1 : s1) < (s2 < 0 ? -s2 : s2); });
}

template<typename C, typename T>
auto SumCont(const C& s1, const T& s2) {
	std::vector<decltype(*std::begin(s1)+ *std::begin(s2))> vAns;
	auto sum = [](const auto& a, const auto& b) { return a + b; };
	if (std::size(s1) > std::size(s2)) {
	vAns.assign(std::begin(s1), std::end(s1));
	std::transform(std::begin(s2), std::end(s2), std::begin(s1), vAns.begin(), sum);
	}
	else {
	vAns.assign(std::begin(s2), std::end(s2));
	std::transform(std::begin(s1), std::end(s1), std::begin(s2), vAns.begin(), sum);
	}
	
	return vAns;
}
template<typename T, typename C1, typename C2, typename P>
void Separate(const T& s, C1& d1, C2& d2, const P& p) {
	for (const auto& elem : s) {
		if (p(elem)) {
			d1.insert(d1.end(), elem);
		}
		else {
			d2.insert(d2.end(), elem);
		}
	}

}

template<typename T> std::map<std::string, T> data;
//template<>
//std::map<std::string, COLORS> data<COLORS> = { {std::string("red"), COLORS::red }, {std::string("green"), COLORS::green }, {std::string("blue"), COLORS::blue } };

template<typename T>
T stringToEnum(std::string str) {
	
	return data<T>.at(str);
}
template<typename T>
std::string enumToString(T str) {
	for (const auto& elem : data<T>) {
		if (elem.second == str) {
			return elem.first;
		}
		
	}
	throw ("not found");
}


