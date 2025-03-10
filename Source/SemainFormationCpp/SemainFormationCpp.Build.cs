// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SemainFormationCpp : ModuleRules
{
	public SemainFormationCpp(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput","UMG", "AdvancedWidgets" });
    }
}
