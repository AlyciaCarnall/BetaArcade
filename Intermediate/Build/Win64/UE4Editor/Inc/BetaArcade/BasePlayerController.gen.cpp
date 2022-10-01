// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BetaArcade/Private/BasePlayerController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBasePlayerController() {}
// Cross Module References
	BETAARCADE_API UClass* Z_Construct_UClass_ABasePlayerController_NoRegister();
	BETAARCADE_API UClass* Z_Construct_UClass_ABasePlayerController();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_BetaArcade();
// End Cross Module References
	DEFINE_FUNCTION(ABasePlayerController::execCallJump)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CallJump();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABasePlayerController::execCallMoveForward)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param__value);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CallMoveForward(Z_Param__value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABasePlayerController::execCallMoveRight)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param__value);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CallMoveRight(Z_Param__value);
		P_NATIVE_END;
	}
	void ABasePlayerController::StaticRegisterNativesABasePlayerController()
	{
		UClass* Class = ABasePlayerController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CallJump", &ABasePlayerController::execCallJump },
			{ "CallMoveForward", &ABasePlayerController::execCallMoveForward },
			{ "CallMoveRight", &ABasePlayerController::execCallMoveRight },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ABasePlayerController_CallJump_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABasePlayerController_CallJump_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/BasePlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABasePlayerController_CallJump_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABasePlayerController, nullptr, "CallJump", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABasePlayerController_CallJump_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABasePlayerController_CallJump_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABasePlayerController_CallJump()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABasePlayerController_CallJump_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABasePlayerController_CallMoveForward_Statics
	{
		struct BasePlayerController_eventCallMoveForward_Parms
		{
			float _value;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp__value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ABasePlayerController_CallMoveForward_Statics::NewProp__value = { "_value", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BasePlayerController_eventCallMoveForward_Parms, _value), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABasePlayerController_CallMoveForward_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABasePlayerController_CallMoveForward_Statics::NewProp__value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABasePlayerController_CallMoveForward_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/BasePlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABasePlayerController_CallMoveForward_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABasePlayerController, nullptr, "CallMoveForward", nullptr, nullptr, sizeof(BasePlayerController_eventCallMoveForward_Parms), Z_Construct_UFunction_ABasePlayerController_CallMoveForward_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABasePlayerController_CallMoveForward_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABasePlayerController_CallMoveForward_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABasePlayerController_CallMoveForward_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABasePlayerController_CallMoveForward()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABasePlayerController_CallMoveForward_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABasePlayerController_CallMoveRight_Statics
	{
		struct BasePlayerController_eventCallMoveRight_Parms
		{
			float _value;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp__value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ABasePlayerController_CallMoveRight_Statics::NewProp__value = { "_value", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BasePlayerController_eventCallMoveRight_Parms, _value), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABasePlayerController_CallMoveRight_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABasePlayerController_CallMoveRight_Statics::NewProp__value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABasePlayerController_CallMoveRight_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Private/BasePlayerController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABasePlayerController_CallMoveRight_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABasePlayerController, nullptr, "CallMoveRight", nullptr, nullptr, sizeof(BasePlayerController_eventCallMoveRight_Parms), Z_Construct_UFunction_ABasePlayerController_CallMoveRight_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABasePlayerController_CallMoveRight_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABasePlayerController_CallMoveRight_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABasePlayerController_CallMoveRight_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABasePlayerController_CallMoveRight()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABasePlayerController_CallMoveRight_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ABasePlayerController_NoRegister()
	{
		return ABasePlayerController::StaticClass();
	}
	struct Z_Construct_UClass_ABasePlayerController_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABasePlayerController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_BetaArcade,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ABasePlayerController_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ABasePlayerController_CallJump, "CallJump" }, // 1763438449
		{ &Z_Construct_UFunction_ABasePlayerController_CallMoveForward, "CallMoveForward" }, // 2589728596
		{ &Z_Construct_UFunction_ABasePlayerController_CallMoveRight, "CallMoveRight" }, // 3747743682
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABasePlayerController_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "BasePlayerController.h" },
		{ "ModuleRelativePath", "Private/BasePlayerController.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABasePlayerController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABasePlayerController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABasePlayerController_Statics::ClassParams = {
		&ABasePlayerController::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x008002A4u,
		METADATA_PARAMS(Z_Construct_UClass_ABasePlayerController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABasePlayerController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABasePlayerController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABasePlayerController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABasePlayerController, 2957847723);
	template<> BETAARCADE_API UClass* StaticClass<ABasePlayerController>()
	{
		return ABasePlayerController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABasePlayerController(Z_Construct_UClass_ABasePlayerController, &ABasePlayerController::StaticClass, TEXT("/Script/BetaArcade"), TEXT("ABasePlayerController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABasePlayerController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
