// Copyright (c) 2019 Vitaly Lifanov <vitaly@lifanoff.ru>

#include "RegexCpp.h"

#define LOCTEXT_NAMESPACE "FRegexCppModule"

void FRegexCppModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
}

void FRegexCppModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FRegexCppModule, RegexCpp)