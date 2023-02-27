// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SIMPLESHOOTER_LootableAmmo_generated_h
#error "LootableAmmo.generated.h already included, missing '#pragma once' in LootableAmmo.h"
#endif
#define SIMPLESHOOTER_LootableAmmo_generated_h

#define FID_SimpleShooter_Source_SimpleShooter_LootableAmmo_h_12_SPARSE_DATA
#define FID_SimpleShooter_Source_SimpleShooter_LootableAmmo_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetAmmoAmount);


#define FID_SimpleShooter_Source_SimpleShooter_LootableAmmo_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetAmmoAmount);


#define FID_SimpleShooter_Source_SimpleShooter_LootableAmmo_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesALootableAmmo(); \
	friend struct Z_Construct_UClass_ALootableAmmo_Statics; \
public: \
	DECLARE_CLASS(ALootableAmmo, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SimpleShooter"), NO_API) \
	DECLARE_SERIALIZER(ALootableAmmo)


#define FID_SimpleShooter_Source_SimpleShooter_LootableAmmo_h_12_INCLASS \
private: \
	static void StaticRegisterNativesALootableAmmo(); \
	friend struct Z_Construct_UClass_ALootableAmmo_Statics; \
public: \
	DECLARE_CLASS(ALootableAmmo, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SimpleShooter"), NO_API) \
	DECLARE_SERIALIZER(ALootableAmmo)


#define FID_SimpleShooter_Source_SimpleShooter_LootableAmmo_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ALootableAmmo(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ALootableAmmo) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALootableAmmo); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALootableAmmo); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALootableAmmo(ALootableAmmo&&); \
	NO_API ALootableAmmo(const ALootableAmmo&); \
public:


#define FID_SimpleShooter_Source_SimpleShooter_LootableAmmo_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ALootableAmmo(ALootableAmmo&&); \
	NO_API ALootableAmmo(const ALootableAmmo&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ALootableAmmo); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ALootableAmmo); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ALootableAmmo)


#define FID_SimpleShooter_Source_SimpleShooter_LootableAmmo_h_9_PROLOG
#define FID_SimpleShooter_Source_SimpleShooter_LootableAmmo_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_SimpleShooter_Source_SimpleShooter_LootableAmmo_h_12_SPARSE_DATA \
	FID_SimpleShooter_Source_SimpleShooter_LootableAmmo_h_12_RPC_WRAPPERS \
	FID_SimpleShooter_Source_SimpleShooter_LootableAmmo_h_12_INCLASS \
	FID_SimpleShooter_Source_SimpleShooter_LootableAmmo_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_SimpleShooter_Source_SimpleShooter_LootableAmmo_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_SimpleShooter_Source_SimpleShooter_LootableAmmo_h_12_SPARSE_DATA \
	FID_SimpleShooter_Source_SimpleShooter_LootableAmmo_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_SimpleShooter_Source_SimpleShooter_LootableAmmo_h_12_INCLASS_NO_PURE_DECLS \
	FID_SimpleShooter_Source_SimpleShooter_LootableAmmo_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SIMPLESHOOTER_API UClass* StaticClass<class ALootableAmmo>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_SimpleShooter_Source_SimpleShooter_LootableAmmo_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
