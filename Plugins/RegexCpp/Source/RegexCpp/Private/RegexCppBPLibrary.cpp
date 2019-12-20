// Copyright (c) 2019 Vitaly Lifanov <vitaly@lifanoff.ru>

#include "RegexCppBPLibrary.h"
#include "RegexCpp.h"

#include <string>
#include <regex>


URegexCppBPLibrary::URegexCppBPLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer) {}


bool URegexCppBPLibrary::RegexMatch(FString str, FString pattern, bool ignoreCase) {
	std::string s { TCHAR_TO_UTF8(*str) };
	std::regex p { ignoreCase ? std::regex { TCHAR_TO_UTF8(*pattern), std::regex_constants::icase } : std::regex { TCHAR_TO_UTF8(*pattern) } };

	return std::regex_match(s, p);
}

bool URegexCppBPLibrary::RegexSearch(FString str, FString pattern, bool ignoreCase) {
	std::string s { TCHAR_TO_UTF8(*str) };
	std::regex p { ignoreCase ? std::regex { TCHAR_TO_UTF8(*pattern), std::regex_constants::icase } : std::regex { TCHAR_TO_UTF8(*pattern) } };

	return std::regex_search(s, p);
}

FString URegexCppBPLibrary::RegexReplace(FString str, FString pattern, FString newStr, bool ignoreCase) {
	std::string s { TCHAR_TO_UTF8(*str) };
	std::string ns { TCHAR_TO_UTF8(*newStr) };
	std::regex p { ignoreCase ? std::regex { TCHAR_TO_UTF8(*pattern), std::regex_constants::icase } : std::regex { TCHAR_TO_UTF8(*pattern) } };

	std::string result { std::regex_replace(s, p, ns) };

	return FString { result.c_str() };
}
