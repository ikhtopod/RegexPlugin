// Copyright (c) 2019 Vitaly Lifanov <vitaly@lifanoff.ru>

#include "RegexCppBPLibrary.h"
#include "RegexCpp.h"

#include <string>


URegexCppBPLibrary::URegexCppBPLibrary(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer) {}


void URegexCppBPLibrary::RegexMatch(FString target, FString pattern, bool ignoreCase, bool& isDone) {
	std::string s { TCHAR_TO_UTF8(*target) };
	std::regex p { ignoreCase ? std::regex { TCHAR_TO_UTF8(*pattern), std::regex_constants::icase } : std::regex { TCHAR_TO_UTF8(*pattern) } };

	isDone = std::regex_match(s, p);
}

void URegexCppBPLibrary::RegexSearch(FString target, FString pattern, bool ignoreCase, bool& isDone) {
	std::string s { TCHAR_TO_UTF8(*target) };
	std::regex p { ignoreCase ? std::regex { TCHAR_TO_UTF8(*pattern), std::regex_constants::icase } : std::regex { TCHAR_TO_UTF8(*pattern) } };

	isDone = std::regex_search(s, p);
}

void URegexCppBPLibrary::RegexReplace(FString target, FString pattern, FString substitution, bool ignoreCase, bool& isDone, FString& resultReplace) {
	std::string s { TCHAR_TO_UTF8(*target) };
	std::string ns { TCHAR_TO_UTF8(*substitution) };
	std::regex p { ignoreCase ? std::regex { TCHAR_TO_UTF8(*pattern), std::regex_constants::icase } : std::regex { TCHAR_TO_UTF8(*pattern) } };

	std::string resultString { std::regex_replace(s, p, ns) };

	resultReplace = FString { resultString.c_str() };
	isDone = !resultString.empty();
}

void URegexCppBPLibrary::RegexMatchExtended(FString target, FString pattern, bool ignoreCase, bool& isDone, FRegexSMatch& resultMatch) {
	std::string s { TCHAR_TO_UTF8(*target) };
	std::regex p { ignoreCase ? std::regex { TCHAR_TO_UTF8(*pattern), std::regex_constants::icase } : std::regex { TCHAR_TO_UTF8(*pattern) } };
	std::smatch m {};

	isDone = std::regex_match(s, m, p);
	URegexCppBPLibrary::SMatch_To_FRegexSMatch(m, resultMatch);
}

void URegexCppBPLibrary::RegexSearchExtended(FString target, FString pattern, bool ignoreCase, bool& isDone, FRegexSMatch& resultMatch) {
	std::string s { TCHAR_TO_UTF8(*target) };
	std::regex p { ignoreCase ? std::regex { TCHAR_TO_UTF8(*pattern), std::regex_constants::icase } : std::regex { TCHAR_TO_UTF8(*pattern) } };
	std::smatch m {};

	isDone = std::regex_search(s, m, p);
	URegexCppBPLibrary::SMatch_To_FRegexSMatch(m, resultMatch);
}


void URegexCppBPLibrary::SMatch_To_FRegexSMatch(const std::smatch& m, FRegexSMatch& regexSMatch) {
	regexSMatch.size = static_cast<int32>(m.size());
	regexSMatch.length = static_cast<int32>(m.length());
	regexSMatch.position = static_cast<int32>(m.position());
	regexSMatch.str = FString { m.str().c_str() };
	regexSMatch.prefix = FString { m.prefix().str().c_str() };
	regexSMatch.suffix = FString { m.suffix().str().c_str() };
}
