// Copyright (c) 2019 Vitaly Lifanov <vitaly@lifanoff.ru>

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "RegexCppBPLibrary.generated.h"

/**
	Regular expressions library based on the c++ std::regex.
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
		@return Result of match
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Regex Simple Match", Keywords = "algorithm regex regular expression match"), Category = "RegExCpp|Algorithms")
		static bool RegexSimpleMatch(FString target, FString pattern, bool ignoreCase = false);

	/**
		Attempts to match a regular expression to any part of a character sequence
		@param target - Target string
		@param pattern - Regular expression
		@param ignoreCase - Ignore case
		@return Result of search
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Regex Simple Search", Keywords = "algorithm regex regular expression search"), Category = "RegExCpp|Algorithms")
		static bool RegexSimpleSearch(FString target, FString pattern, bool ignoreCase = false);

	/**
		Replaces occurrences of a regular expression with formatted replacement text
		@param target - Target string
		@param pattern - Regular expression
		@param ignoreCase - Ignore case
		@param substitution - Substitution string
		@return Result of replace
	*/
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Regex Simple Replace", Keywords = "algorithm regex regular expression replace"), Category = "RegExCpp|Algorithms")
		static FString RegexSimpleReplace(FString target, FString pattern, FString substitution, bool ignoreCase = false);
};
