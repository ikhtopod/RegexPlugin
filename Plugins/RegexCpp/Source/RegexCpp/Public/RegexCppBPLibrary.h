// Copyright (c) 2019 Vitaly Lifanov <vitaly@lifanoff.ru>

#pragma once

#include <regex>

#include "RegexSMatch.h"

#include "Kismet/BlueprintFunctionLibrary.h"
#include "RegexCppBPLibrary.generated.h"


/**
 * Regular expressions library based on the c++ std::regex.
 */
UCLASS()
class URegexCppBPLibrary : public UBlueprintFunctionLibrary {
	GENERATED_UCLASS_BODY()

public:
	/**
		Attempts to match a regular expression to an entire character sequence
		@param target - Target string
		@param pattern - Regular expression
		@param ignoreCase - Ignore case
		@param isDone - true if match is done, otherwise - false
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Regex Match", Keywords = "algorithm regex regular expression match"), Category = "RegExCpp|Algorithms")
		static void RegexMatch(FString target, FString pattern, bool ignoreCase, bool& isDone);

	/**
		Attempts to match a regular expression to any part of a character sequence
		@param target - Target string
		@param pattern - Regular expression
		@param ignoreCase - Ignore case
		@param isDone - true if search is done, otherwise - false
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Regex Search", Keywords = "algorithm regex regular expression search"), Category = "RegExCpp|Algorithms")
		static void RegexSearch(FString target, FString pattern, bool ignoreCase, bool& isDone);

	/**
		Replaces occurrences of a regular expression with formatted replacement text
		@param target - Target string
		@param pattern - Regular expression
		@param substitution - Substitution string
		@param ignoreCase - Ignore case
		@param isDone - true if replace is done, otherwise - false
		@param resultReplace - Result of replace
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Regex Replace", Keywords = "algorithm regex regular expression replace"), Category = "RegExCpp|Algorithms")
		static void RegexReplace(FString target, FString pattern, FString substitution, bool ignoreCase, bool& isDone, FString& resultReplace);

	/**
		Attempts to match a regular expression to an entire character sequence
		@param target - Target string
		@param pattern - Regular expression
		@param ignoreCase - Ignore case
		@param isDone - true if match is done, otherwise - false
		@param resultMatch - Result of match
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Regex Match Extended", Keywords = "algorithm regex regular expression match extended result"), Category = "RegExCpp|Algorithms")
		static void RegexMatchExtended(FString target, FString pattern, bool ignoreCase, bool& isDone, FRegexSMatch& resultMatch);

	/**
		Attempts to match a regular expression to any part of a character sequence
		@param target - Target string
		@param pattern - Regular expression
		@param ignoreCase - Ignore case
		@param isDone - true if search is done, otherwise - false
		@param resultMatch - Result of match
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Regex Search Extended", Keywords = "algorithm regex regular expression search extended result"), Category = "RegExCpp|Algorithms")
		static void RegexSearchExtended(FString target, FString pattern, bool ignoreCase, bool& isDone, FRegexSMatch& resultMatch);

private:
	static void SMatch_To_FRegexSMatch(const std::smatch& m, FRegexSMatch& regexSMatch);
};
