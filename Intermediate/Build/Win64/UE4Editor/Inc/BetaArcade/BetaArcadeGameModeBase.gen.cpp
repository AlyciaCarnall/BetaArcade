// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BetaArcade/BetaArcadeGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBetaArcadeGameModeBase() {}
// Cross Module References
	BETAARCADE_API UClass* Z_Construct_UClass_ABetaArcadeGameModeBase_NoRegister();
	BETAARCADE_API UClass* Z_Construct_UClass_ABetaArcadeGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_BetaArcade();
// End Cross Module References
	void ABetaArcadeGameModeBase::StaticRegisterNativesABetaArcadeGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_ABetaArcadeGameModeBase_NoRegister()
	{
		return ABetaArcadeGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ABetaArcadeGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABetaArcadeGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_BetaArcade,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABetaArcadeGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "BetaArcadeGameModeBase.h" },
		{ "ModuleRelativePath", "BetaArcadeGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABetaArcadeGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABetaArcadeGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABetaArcadeGameModeBase_Statics::ClassParams = {
		&ABetaArcadeGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ABetaArcadeGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABetaArcadeGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABetaArcadeGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABetaArcadeGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABetaArcadeGameModeBase, 608283689);
	template<> BETAARCADE_API UClass* StaticClass<ABetaArcadeGameModeBase>()
	{
		return ABetaArcadeGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABetaArcadeGameModeBase(Z_Construct_UClass_ABetaArcadeGameModeBase, &ABetaArcadeGameModeBase::StaticClass, TEXT("/Script/BetaArcade"), TEXT("ABetaArcadeGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABetaArcadeGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
