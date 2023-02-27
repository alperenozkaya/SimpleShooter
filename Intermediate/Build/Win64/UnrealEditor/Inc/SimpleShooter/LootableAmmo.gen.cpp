// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleShooter/LootableAmmo.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLootableAmmo() {}
// Cross Module References
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_ALootableAmmo_NoRegister();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_ALootableAmmo();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_SimpleShooter();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ALootableAmmo::execGetAmmoAmount)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetAmmoAmount();
		P_NATIVE_END;
	}
	void ALootableAmmo::StaticRegisterNativesALootableAmmo()
	{
		UClass* Class = ALootableAmmo::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetAmmoAmount", &ALootableAmmo::execGetAmmoAmount },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ALootableAmmo_GetAmmoAmount_Statics
	{
		struct LootableAmmo_eventGetAmmoAmount_Parms
		{
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ALootableAmmo_GetAmmoAmount_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(LootableAmmo_eventGetAmmoAmount_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ALootableAmmo_GetAmmoAmount_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALootableAmmo_GetAmmoAmount_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ALootableAmmo_GetAmmoAmount_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "LootableAmmo.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ALootableAmmo_GetAmmoAmount_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ALootableAmmo, nullptr, "GetAmmoAmount", nullptr, nullptr, sizeof(Z_Construct_UFunction_ALootableAmmo_GetAmmoAmount_Statics::LootableAmmo_eventGetAmmoAmount_Parms), Z_Construct_UFunction_ALootableAmmo_GetAmmoAmount_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ALootableAmmo_GetAmmoAmount_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x40020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ALootableAmmo_GetAmmoAmount_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ALootableAmmo_GetAmmoAmount_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ALootableAmmo_GetAmmoAmount()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ALootableAmmo_GetAmmoAmount_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ALootableAmmo);
	UClass* Z_Construct_UClass_ALootableAmmo_NoRegister()
	{
		return ALootableAmmo::StaticClass();
	}
	struct Z_Construct_UClass_ALootableAmmo_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AmmoType_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_AmmoType;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MeshComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MeshComp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AmmoAmount_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_AmmoAmount;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ALootableAmmo_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleShooter,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ALootableAmmo_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ALootableAmmo_GetAmmoAmount, "GetAmmoAmount" }, // 1969596159
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALootableAmmo_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "LootableAmmo.h" },
		{ "ModuleRelativePath", "LootableAmmo.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALootableAmmo_Statics::NewProp_AmmoType_MetaData[] = {
		{ "Category", "AmmoType" },
		{ "ModuleRelativePath", "LootableAmmo.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_ALootableAmmo_Statics::NewProp_AmmoType = { "AmmoType", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALootableAmmo, AmmoType), METADATA_PARAMS(Z_Construct_UClass_ALootableAmmo_Statics::NewProp_AmmoType_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALootableAmmo_Statics::NewProp_AmmoType_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALootableAmmo_Statics::NewProp_MeshComp_MetaData[] = {
		{ "Category", "LootableAmmo" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "LootableAmmo.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALootableAmmo_Statics::NewProp_MeshComp = { "MeshComp", nullptr, (EPropertyFlags)0x0040000000080009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALootableAmmo, MeshComp), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ALootableAmmo_Statics::NewProp_MeshComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALootableAmmo_Statics::NewProp_MeshComp_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALootableAmmo_Statics::NewProp_AmmoAmount_MetaData[] = {
		{ "Category", "LootableAmmo" },
		{ "ModuleRelativePath", "LootableAmmo.h" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ALootableAmmo_Statics::NewProp_AmmoAmount = { "AmmoAmount", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALootableAmmo, AmmoAmount), METADATA_PARAMS(Z_Construct_UClass_ALootableAmmo_Statics::NewProp_AmmoAmount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALootableAmmo_Statics::NewProp_AmmoAmount_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ALootableAmmo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALootableAmmo_Statics::NewProp_AmmoType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALootableAmmo_Statics::NewProp_MeshComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALootableAmmo_Statics::NewProp_AmmoAmount,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ALootableAmmo_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALootableAmmo>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ALootableAmmo_Statics::ClassParams = {
		&ALootableAmmo::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ALootableAmmo_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ALootableAmmo_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ALootableAmmo_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ALootableAmmo_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ALootableAmmo()
	{
		if (!Z_Registration_Info_UClass_ALootableAmmo.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ALootableAmmo.OuterSingleton, Z_Construct_UClass_ALootableAmmo_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ALootableAmmo.OuterSingleton;
	}
	template<> SIMPLESHOOTER_API UClass* StaticClass<ALootableAmmo>()
	{
		return ALootableAmmo::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALootableAmmo);
	struct Z_CompiledInDeferFile_FID_SimpleShooter_Source_SimpleShooter_LootableAmmo_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SimpleShooter_Source_SimpleShooter_LootableAmmo_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ALootableAmmo, ALootableAmmo::StaticClass, TEXT("ALootableAmmo"), &Z_Registration_Info_UClass_ALootableAmmo, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ALootableAmmo), 3026876833U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SimpleShooter_Source_SimpleShooter_LootableAmmo_h_1093578627(TEXT("/Script/SimpleShooter"),
		Z_CompiledInDeferFile_FID_SimpleShooter_Source_SimpleShooter_LootableAmmo_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SimpleShooter_Source_SimpleShooter_LootableAmmo_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
