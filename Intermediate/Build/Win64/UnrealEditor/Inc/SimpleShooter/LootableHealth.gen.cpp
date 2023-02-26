// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SimpleShooter/LootableHealth.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLootableHealth() {}
// Cross Module References
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_ALootableHealth_NoRegister();
	SIMPLESHOOTER_API UClass* Z_Construct_UClass_ALootableHealth();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_SimpleShooter();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ALootableHealth::execGetHealthAmount)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetHealthAmount();
		P_NATIVE_END;
	}
	void ALootableHealth::StaticRegisterNativesALootableHealth()
	{
		UClass* Class = ALootableHealth::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetHealthAmount", &ALootableHealth::execGetHealthAmount },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ALootableHealth_GetHealthAmount_Statics
	{
		struct LootableHealth_eventGetHealthAmount_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ALootableHealth_GetHealthAmount_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(LootableHealth_eventGetHealthAmount_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ALootableHealth_GetHealthAmount_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ALootableHealth_GetHealthAmount_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ALootableHealth_GetHealthAmount_Statics::Function_MetaDataParams[] = {
		{ "Comment", "// Called when the player interacts with the health pickup\n" },
		{ "ModuleRelativePath", "LootableHealth.h" },
		{ "ToolTip", "Called when the player interacts with the health pickup" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ALootableHealth_GetHealthAmount_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ALootableHealth, nullptr, "GetHealthAmount", nullptr, nullptr, sizeof(Z_Construct_UFunction_ALootableHealth_GetHealthAmount_Statics::LootableHealth_eventGetHealthAmount_Parms), Z_Construct_UFunction_ALootableHealth_GetHealthAmount_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ALootableHealth_GetHealthAmount_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x40020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ALootableHealth_GetHealthAmount_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ALootableHealth_GetHealthAmount_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ALootableHealth_GetHealthAmount()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ALootableHealth_GetHealthAmount_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ALootableHealth);
	UClass* Z_Construct_UClass_ALootableHealth_NoRegister()
	{
		return ALootableHealth::StaticClass();
	}
	struct Z_Construct_UClass_ALootableHealth_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MeshComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MeshComp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HealthAmount_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_HealthAmount;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ALootableHealth_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SimpleShooter,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ALootableHealth_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ALootableHealth_GetHealthAmount, "GetHealthAmount" }, // 1773650186
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALootableHealth_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "LootableHealth.h" },
		{ "ModuleRelativePath", "LootableHealth.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALootableHealth_Statics::NewProp_MeshComp_MetaData[] = {
		{ "Category", "LootableHealth" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "LootableHealth.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ALootableHealth_Statics::NewProp_MeshComp = { "MeshComp", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALootableHealth, MeshComp), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ALootableHealth_Statics::NewProp_MeshComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALootableHealth_Statics::NewProp_MeshComp_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ALootableHealth_Statics::NewProp_HealthAmount_MetaData[] = {
		{ "Category", "LootableHealth" },
		{ "ModuleRelativePath", "LootableHealth.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ALootableHealth_Statics::NewProp_HealthAmount = { "HealthAmount", nullptr, (EPropertyFlags)0x0040000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ALootableHealth, HealthAmount), METADATA_PARAMS(Z_Construct_UClass_ALootableHealth_Statics::NewProp_HealthAmount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ALootableHealth_Statics::NewProp_HealthAmount_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ALootableHealth_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALootableHealth_Statics::NewProp_MeshComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ALootableHealth_Statics::NewProp_HealthAmount,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ALootableHealth_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ALootableHealth>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ALootableHealth_Statics::ClassParams = {
		&ALootableHealth::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ALootableHealth_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ALootableHealth_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ALootableHealth_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ALootableHealth_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ALootableHealth()
	{
		if (!Z_Registration_Info_UClass_ALootableHealth.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ALootableHealth.OuterSingleton, Z_Construct_UClass_ALootableHealth_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ALootableHealth.OuterSingleton;
	}
	template<> SIMPLESHOOTER_API UClass* StaticClass<ALootableHealth>()
	{
		return ALootableHealth::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALootableHealth);
	struct Z_CompiledInDeferFile_FID_SimpleShooter_Source_SimpleShooter_LootableHealth_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SimpleShooter_Source_SimpleShooter_LootableHealth_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ALootableHealth, ALootableHealth::StaticClass, TEXT("ALootableHealth"), &Z_Registration_Info_UClass_ALootableHealth, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ALootableHealth), 1408161850U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_SimpleShooter_Source_SimpleShooter_LootableHealth_h_3733786222(TEXT("/Script/SimpleShooter"),
		Z_CompiledInDeferFile_FID_SimpleShooter_Source_SimpleShooter_LootableHealth_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_SimpleShooter_Source_SimpleShooter_LootableHealth_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
