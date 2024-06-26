// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ALootableAmmo;
class ALootableHealth;
class AGun;
#ifdef SIMPLESHOOTER_ShooterCharacter_generated_h
#error "ShooterCharacter.generated.h already included, missing '#pragma once' in ShooterCharacter.h"
#endif
#define SIMPLESHOOTER_ShooterCharacter_generated_h

#define FID_SimpleShooter_Source_SimpleShooter_ShooterCharacter_h_15_SPARSE_DATA
#define FID_SimpleShooter_Source_SimpleShooter_ShooterCharacter_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execPickUpAmmo); \
	DECLARE_FUNCTION(execPickUpHealth); \
	DECLARE_FUNCTION(execPickUpGun); \
	DECLARE_FUNCTION(execCurrentGun); \
	DECLARE_FUNCTION(execGetHealthPercent); \
	DECLARE_FUNCTION(execIsDead);


#define FID_SimpleShooter_Source_SimpleShooter_ShooterCharacter_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execPickUpAmmo); \
	DECLARE_FUNCTION(execPickUpHealth); \
	DECLARE_FUNCTION(execPickUpGun); \
	DECLARE_FUNCTION(execCurrentGun); \
	DECLARE_FUNCTION(execGetHealthPercent); \
	DECLARE_FUNCTION(execIsDead);


#define FID_SimpleShooter_Source_SimpleShooter_ShooterCharacter_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAShooterCharacter(); \
	friend struct Z_Construct_UClass_AShooterCharacter_Statics; \
public: \
	DECLARE_CLASS(AShooterCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SimpleShooter"), NO_API) \
	DECLARE_SERIALIZER(AShooterCharacter)


#define FID_SimpleShooter_Source_SimpleShooter_ShooterCharacter_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAShooterCharacter(); \
	friend struct Z_Construct_UClass_AShooterCharacter_Statics; \
public: \
	DECLARE_CLASS(AShooterCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SimpleShooter"), NO_API) \
	DECLARE_SERIALIZER(AShooterCharacter)


#define FID_SimpleShooter_Source_SimpleShooter_ShooterCharacter_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AShooterCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AShooterCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AShooterCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AShooterCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AShooterCharacter(AShooterCharacter&&); \
	NO_API AShooterCharacter(const AShooterCharacter&); \
public:


#define FID_SimpleShooter_Source_SimpleShooter_ShooterCharacter_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AShooterCharacter(AShooterCharacter&&); \
	NO_API AShooterCharacter(const AShooterCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AShooterCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AShooterCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AShooterCharacter)


#define FID_SimpleShooter_Source_SimpleShooter_ShooterCharacter_h_12_PROLOG
#define FID_SimpleShooter_Source_SimpleShooter_ShooterCharacter_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_SimpleShooter_Source_SimpleShooter_ShooterCharacter_h_15_SPARSE_DATA \
	FID_SimpleShooter_Source_SimpleShooter_ShooterCharacter_h_15_RPC_WRAPPERS \
	FID_SimpleShooter_Source_SimpleShooter_ShooterCharacter_h_15_INCLASS \
	FID_SimpleShooter_Source_SimpleShooter_ShooterCharacter_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_SimpleShooter_Source_SimpleShooter_ShooterCharacter_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_SimpleShooter_Source_SimpleShooter_ShooterCharacter_h_15_SPARSE_DATA \
	FID_SimpleShooter_Source_SimpleShooter_ShooterCharacter_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_SimpleShooter_Source_SimpleShooter_ShooterCharacter_h_15_INCLASS_NO_PURE_DECLS \
	FID_SimpleShooter_Source_SimpleShooter_ShooterCharacter_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SIMPLESHOOTER_API UClass* StaticClass<class AShooterCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_SimpleShooter_Source_SimpleShooter_ShooterCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
