// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GuitarEffectPlugin : ModuleRules
{
    public GuitarEffectPlugin(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        
        PublicIncludePaths.AddRange(
            new string[] {
                // ... add public include paths required here ...

            }
            );
                
        
        PrivateIncludePaths.AddRange(
            new string[] {
                // ... add private include paths required here ...

            }
            );
            
        
        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                // ... add public dependencies that you statically link with here ...
                "Core",
                "Serialization",
                "SignalProcessing",
                "AudioExtensions",
                "MetasoundFrontend",
                "MetasoundGraphCore",
                "MetasoundStandardNodes",
            }
            );
            
        
        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                // ... add private dependencies that you statically link with here ...  
                "CoreUObject",
                "Engine",
            }
            );
        
        
        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
                // ... add any modules that your module loads dynamically here ...

            }
            );
    }
}
