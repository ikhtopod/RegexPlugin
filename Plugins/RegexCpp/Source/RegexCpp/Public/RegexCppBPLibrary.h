// Copyright (c) 2019 Vitaly Lifanov <vitaly@lifanoff.ru>

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "RegexCppBPLibrary.generated.h"

/*
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu.
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
UCLASS()
class URegexCppBPLibrary : public UBlueprintFunctionLibrary {
	GENERATED_UCLASS_BODY()

public:
	// Attempts to match a regular expression to an entire character sequence
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Regex Match", Keywords = "algorithm regex regular expression match"), Category = "RegExCpp|Algorithms")
		static bool RegexMatch(FString str, FString pattern, bool ignoreCase = false);

	// Attempts to match a regular expression to any part of a character sequence
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Regex Search", Keywords = "algorithm regex regular expression search"), Category = "RegExCpp|Algorithms")
		static bool RegexSearch(FString str, FString pattern, bool ignoreCase = false);

	// Replaces occurrences of a regular expression with formatted replacement text
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Regex Replace", Keywords = "algorithm regex regular expression replace"), Category = "RegExCpp|Algorithms")
		static FString RegexReplace(FString str, FString pattern, FString newStr, bool ignoreCase = false);
};
