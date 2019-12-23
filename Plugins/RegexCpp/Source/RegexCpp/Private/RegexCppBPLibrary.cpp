// Copyright (c) 2019 Vitaly Lifanov <vitaly@lifanoff.ru>

#include "RegexCppBPLibrary.h"
#include "RegexCpp.h"

#include <string>
#include <regex>


URegexCppBPLibrary::URegexCppBPLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer) {}


bool URegexCppBPLibrary::RegexSimpleMatch(FString target, FString pattern, bool ignoreCase) {
	std::string s { TCHAR_TO_UTF8(*target) };
	std::regex p { ignoreCase ? std::regex { TCHAR_TO_UTF8(*pattern), std::regex_constants::icase } : std::regex { TCHAR_TO_UTF8(*pattern) } };

	return std::regex_match(s, p);
}

bool URegexCppBPLibrary::RegexSimpleSearch(FString target, FString pattern, bool ignoreCase) {
	std::string s { TCHAR_TO_UTF8(*target) };
	std::regex p { ignoreCase ? std::regex { TCHAR_TO_UTF8(*pattern), std::regex_constants::icase } : std::regex { TCHAR_TO_UTF8(*pattern) } };

	return std::regex_search(s, p);
}

FString URegexCppBPLibrary::RegexSimpleReplace(FString target, FString pattern, FString substitution, bool ignoreCase) {
	std::string s { TCHAR_TO_UTF8(*target) };
	std::string ns { TCHAR_TO_UTF8(*substitution) };
	std::regex p { ignoreCase ? std::regex { TCHAR_TO_UTF8(*pattern), std::regex_constants::icase } : std::regex { TCHAR_TO_UTF8(*pattern) } };

	std::string result { std::regex_replace(s, p, ns) };

	return FString { result.c_str() };
}
