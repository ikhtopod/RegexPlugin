// Copyright (c) 2019 Vitaly Lifanov <vitaly@lifanoff.ru>

#pragma once

// TODO: convert to class

#include "RegexSMatch.generated.h"

/**
 * Result of a regular expression match.
 */
USTRUCT(BlueprintType)
struct REGEXCPP_API FRegexSMatch {
	GENERATED_USTRUCT_BODY()

public:
	// Number of matches in a fully-established result state
	UPROPERTY(BlueprintReadWrite, Category = "RegexSMatch|Size")
		int32 size;

	// Length of the particular sub-match
	UPROPERTY(BlueprintReadWrite, Category = "RegexSMatch|ElementAccess")
		int32 length;

	// Position of the first character of the particular sub-match
	UPROPERTY(BlueprintReadWrite, Category = "RegexSMatch|ElementAccess")
		int32 position;

	// Sequence of characters for the particular sub-match
	UPROPERTY(BlueprintReadWrite, Category = "RegexSMatch|ElementAccess")
		FString str;

	// Sub-sequence between the beginning of the target sequence and the beginning of the full match
	UPROPERTY(BlueprintReadWrite, Category = "RegexSMatch|ElementAccess")
		FString prefix;

	// Sub-sequence between the end of the full match and the end of the target sequence
	UPROPERTY(BlueprintReadWrite, Category = "RegexSMatch|ElementAccess")
		FString suffix;
};
